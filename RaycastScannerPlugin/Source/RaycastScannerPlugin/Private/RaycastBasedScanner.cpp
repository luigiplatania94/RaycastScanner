/*=============================================================================
	RaycastBasedScanner.cpp

	Doc:
	https://github.com/luigiplatania94/RaycastScanner

	Luigi Platania
	https://www.luigiplatania.net/

	Email:
	luigiplatania94@gmail.com

=============================================================================*/


#include "RaycastBasedScanner.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"


// Sets default values for this component's properties
URaycastBasedScanner::URaycastBasedScanner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}



// Called when the game starts
void URaycastBasedScanner::BeginPlay()
{
	Super::BeginPlay();

	// Set the Tick Interval to be equal to the user-defined Update Interval
	PrimaryComponentTick.TickInterval = UpdateInterval;
}



// Called every frame
void URaycastBasedScanner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*
	**	Get the Owner's Location
	*/
	AActor* Parent = GetOwner();
	if (Parent)
	{
		OwnerLocation = Parent->GetActorLocation();
	}
	
	// execute if the player has moved OR if the system needs to calculate until 16 frames
	if (!(OwnerLocation.Equals(OldOwnerLocation, Tolerance)) || bDoOnce)
	{
		// set the debug color to be red because the player is moving OR the system have NOT yet calculated 16 frames.
		DebugSphereColor = FColor::Red;

		// bDoOnce will be set to false once the system has calculated 16 frames
		bDoOnce = true;

		// set the NorthVector to always point at (1, 0, 0)
		FVector NorthVector = FVector(1, 0, 0);

		// offset the starting point of raycasting
		RayStartLocation = (FVector::UpVector * StartingPointOffset) + OwnerLocation;


		// Initialise the 3 elements array that will store the distances of a single phase
		TArray<float> DistancesBuffer { 0, 0, 0 };

		// Used to write distances of single raycast into the DistanceBuffer 
		int DistanceCounter{ 0 };

		// reset the offset when all 4 phases have completed the scan
		if (AngleOffset > 90)
		{
			AngleOffset = 0;
		}


		/*
		**	Perform three raycasts and store the distances a 3 elements buffer (DistancesBuffer)
		*/

		for (int i{ AngleOffset }; i < 360; i += 120)
		{
			// rotate on the Z axis
			FVector RotatedNorthVector = NorthVector.RotateAngleAxis(i, FVector(0, 0, 1));

			// scale the rotated forward vector and add it to the player location
			FVector RayEndLocation = (RotatedNorthVector * AzimuthRayLength) + RayStartLocation;

			float HitDistance{ AzimuthRayLength };

			// TRUE if a blocking hit is found
			if (GetWorld()->LineTraceSingleByChannel(HitResult, RayStartLocation, RayEndLocation, CollisionChannel))
			{
				// The distance from the TraceStart to The Location in world space where the moving shape would end up against the impacted object.
				HitDistance = HitResult.Distance;
			}

			// Add the HitDistance into the short history buffer. 
			DistancesBuffer[DistanceCounter] = HitDistance;

			DistanceCounter++;

			// reset the counter if it reached the maximum value
			if (DistanceCounter >= 3)
			{
				DistanceCounter = 0;
			}


			/*
			**	DEBUG line-traces
			*/
			//#if WITH_EDITOR
			//DrawDebugLine(GetWorld(), RayStartLocation, RayEndLocation, FColor::Red, false, UpdateInterval, 0, 12.333);
			//#endif // #if WITH_EDITOR

		}

		// offset the angle for the next phase
		AngleOffset += 30;

		// The two shortest distances will be averaged and stored into the Pessimistic_SinglePhase
		// The two largest distances will be avaraged and stored into the Optimistic_SinglePhase
		float Pessimistic_SinglePhase = AverageSmallestValues(DistancesBuffer);
		float Optimistic_SinglePhase = AverageLargestValues(DistancesBuffer);


		/*
		**	DEBUG optimistic and pessimistic single phases
		*/
		//#if WITH_EDITOR
		//FString Pessimistic_SinglePhase_String = FString::Printf(TEXT("The pessimistic single phase is %f"), Pessimistic_SinglePhase);
		//FString Optimistic_SinglePhase_String = FString::Printf(TEXT("The optimistic single phase is %f"), Optimistic_SinglePhase);

		//if (GEngine)
		//{
		//	GEngine->AddOnScreenDebugMessage(0, UpdateInterval, FColor::Blue, Pessimistic_SinglePhase_String);
		//	GEngine->AddOnScreenDebugMessage(1, UpdateInterval, FColor::Blue, Optimistic_SinglePhase_String);
		//}
		//#endif // #if WITH_EDITOR

		// new avarages are added to a 4 element short history buffer
		Pessimistic_PhasesBuffer[PhaseCounter] = Pessimistic_SinglePhase;
		Optimistic_PhasesBuffer[PhaseCounter] = Optimistic_SinglePhase;

		PhaseCounter++;

		// TRUE if four completed phases have been completed
		if (PhaseCounter >= 4)
		{
			// reset the counter
			PhaseCounter = 0;

			// The three shortest phases will be averaged and stored into the Pessimistic_TargetValue
			// The three largest phases will be avaraged and stored into the Optimistic_TargetValue
			Pessimistic_TargetValue = AverageSmallestValues(Pessimistic_PhasesBuffer);
			Optimistic_TargetValue = AverageLargestValues(Optimistic_PhasesBuffer);

			Pessimistic_TargetValues[SmoothCounter] = Pessimistic_TargetValue;
			Optimistic_TargetValues[SmoothCounter] = Optimistic_TargetValue;

			SmoothCounter++;

			// TRUE if 16 frames have passed
			if (SmoothCounter >= 4)
			{
				// Smooth out the values over 16 frames
				Pessimistic_AzimuthValueBeforeMapping = AvarageArrayElements(Pessimistic_TargetValues);
				Optimistic_AzimuthValueBeforeMapping = AvarageArrayElements(Optimistic_TargetValues);

				// Map the value into a range from 0 to 1
				PessimisticAzimuthValue = Pessimistic_AzimuthValueBeforeMapping / AzimuthRayLength;
				OptimisticAzimuthValue = Optimistic_AzimuthValueBeforeMapping / AzimuthRayLength;

				// SET THE RTPC ON YOUR MIDDLEWARE HERE
				// (...)
				// or alternatevely use OnMetricUpdate event in blueprint:
				// this will allow the sound designer to set an RTPC on the Blueprint child of these actor component just by overriding this event.
				OnMetricUpdate();

				// reset the counter
				SmoothCounter = 0;
				
				// The system will not calculate further if the player has stopped moving
				bDoOnce = false;
			}

		} // END if (SmoothCounter >= 4)
		
		// reset owner's location
		OldOwnerLocation = OwnerLocation;
	}



	/*
	**	DEBUG	
	*/
	#if WITH_EDITOR
	Debug();
	#endif // #if WITH_EDITOR

}



/*
**	Find the smallest value of an array
*/
float URaycastBasedScanner::FindSmallestValue(const TArray<float>& ArrayOfElements) const
{

	// Initialise the first value to zero
	float Smallest{ FLT_MAX };

	for (int i{ 0 }; i < ArrayOfElements.Num(); i++)
	{
		// If current element is greater than first then update both first and second 
		if (ArrayOfElements[i] < Smallest)
		{
			Smallest = ArrayOfElements[i];
		}
	}

	return Smallest;
}



/*
**	Find the smallest values (size - 1) of an array and calculate the avarage
*/
float URaycastBasedScanner::AverageSmallestValues(const TArray<float>& ArrayOfElements) const
{	
	// average = (Sum - Largest Value) / Array's Length - 1
	float average = (SumArrayElements(ArrayOfElements) - FindLargestValue(ArrayOfElements)) / (ArrayOfElements.Num() - 1);

	/*
	**	DEBUG buffer elements and average
	*/
	//#if WITH_EDITOR
	//for (float element : ArrayOfElements)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("\nElement is: %f\n"), element);
	//}

	//UE_LOG(LogTemp, Warning, TEXT("\nAverage smallest values returns: %f"), average);
	//#endif // #if WITH_EDITOR

	return average;
}



/*
**	Find the largest value of an array 
*/
float URaycastBasedScanner::FindLargestValue(const TArray<float>& ArrayOfElements) const
{
	// Initialise the first value to zero
	float Largest{ 0.0f };


	for (int i{ 0 }; i < ArrayOfElements.Num(); i++)
	{
		// If current element is greater than first then update both first and second 
		if (ArrayOfElements[i] > Largest)
		{
			Largest = ArrayOfElements[i];
		}

	}

	return Largest;
}



/*
**	Find the largest values (size - 1) of an array and calculate the avarage 
*/
float URaycastBasedScanner::AverageLargestValues(const TArray<float>& ArrayOfElements) const
{
	// (Sum - Smallest Value) / Array's Length - 1
	float average = (SumArrayElements(ArrayOfElements) - FindSmallestValue(ArrayOfElements)) / (ArrayOfElements.Num() - 1);
	
	/*
	**	DEBUG buffer elements and average
	*/
	//#if WITH_EDITOR
	//for (float element : ArrayOfElements)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("\nElement is: %f\n"), element);
	//}

	//UE_LOG(LogTemp, Warning, TEXT("\nAverage largest values returns: %f"), average);
	//#endif // #if WITH_EDITOR

	return average;
}



/*
**	Find the avarage all the elements contained into an array
*/
float URaycastBasedScanner::AvarageArrayElements(const TArray<float>& ArrayOfElements) const
{

	float sum{ 0 };

	sum = SumArrayElements(ArrayOfElements);

	return (sum / ArrayOfElements.Num());
}



/*
**	Return the sum of all the array's elements. Utility function. 
*/
float URaycastBasedScanner::SumArrayElements(const TArray<float>& ArrayOfElements) const
{
	float sum{ 0.0f };

	for (int i{ 0 }; i < ArrayOfElements.Num(); i++)
	{
		sum += ArrayOfElements[i];
	}

	return sum;
}



/*
**	Debug
*/
void URaycastBasedScanner::Debug()
{
	// draw circles around the player (Green = Pessimistic. Blue = Optimistic) and draw a sphere on the raycast's starting point. 
	if (bDebugVisualisation)
	{
		// the center parameter has an offset (FVector (1,1,0) in order to avoid flickering effect
		DrawDebugCircle(GetWorld(), OwnerLocation + FVector(1, 1, 0), Pessimistic_AzimuthValueBeforeMapping, 64, FColor::Green, false, UpdateInterval, 0.0f, 20.0f, FVector(1, 0, 0), FVector(0, 1, 0));
		DrawDebugCircle(GetWorld(), OwnerLocation, Optimistic_AzimuthValueBeforeMapping, 64, FColor::Blue, false, UpdateInterval, 0.0f, 20.0f, FVector(1, 0, 0), FVector(0, 1, 0));

		// draw the starting point of the raycast
		DrawDebugSphere(GetWorld(), RayStartLocation, 10, 9, DebugSphereColor, false, UpdateInterval, 0.0, 10.0f);
	}
	// set the debug color to black because the player is NOT moving OR the system have calculated last 16 frames 
	DebugSphereColor = FColor::Black;

	// If TRUE print to the screen both the optimistic and pessimistic metric
	if (bDebugMetrics)
	{
		FString optimistic = FString::Printf(TEXT("The optimistic metric is %f"), OptimisticAzimuthValue);
		FString pessimistic = FString::Printf(TEXT("The pessimistic metric is %f"), PessimisticAzimuthValue);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(2, UpdateInterval, FColor::Yellow, optimistic);
			GEngine->AddOnScreenDebugMessage(3, UpdateInterval, FColor::Yellow, pessimistic);
		}
	}
}

