/*=============================================================================
	RaycastBasedScanner.cpp

	Doc:
	https://github.com/luigiplatania94/RaycastScanner

	Luigi Platania
	https://www.luigiplatania.net/

	Email:
	luigiplatania94@gmail.com

=============================================================================*/

/*
**	DISCLAIMER:
**	I'm using built-in array instead of TArrays because I am working on optimising the tool using SIMD intrinsics
*/


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


	// Allocate the memory and call the constructor for every arrays used
	PessimisticPhasesBuffer = new float[PhasesBufferSize] { 0.0f };
	OptimisticPhasesBuffer = new float[PhasesBufferSize] { 0.0f };

	PessimisticTargetValues = new float[TargetValuesSize] { 0.0f };
	OptimisticTargetValues = new float[TargetValuesSize] { 0.0f };
}

// Called to finish destroying the object.
void URaycastBasedScanner::FinishDestroy()
{
	/* 
	**	Call the destructor and de-allocate the memory for every arrays used
	**	I use Finish Destroy instead of BeginDestroy because FinishDestroy it's after any async stuff which might still try access the memory.
	*/
	delete[] PessimisticPhasesBuffer;
	PessimisticPhasesBuffer = nullptr;

	delete[] OptimisticPhasesBuffer;
	OptimisticPhasesBuffer = nullptr;

	delete[] PessimisticTargetValues;
	PessimisticTargetValues = nullptr;

	delete[] OptimisticTargetValues;
	OptimisticTargetValues = nullptr;


	// Because properties are destroyed here, Super::FinishDestroy() should always be called at the end of your child class's FinishDestroy() method, rather than at the beginning.
	Super::FinishDestroy();
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

		// set the NorthVector to be the "forward" vector 
		FVector NorthVector = FVector(1, 0, 0);

		// offset the starting point of the raycast
		RayStartLocation = (FVector::UpVector * StartingPointOffset) + OwnerLocation;

		const size_t DistancesBufferSize{ 3 };

		// Initialise the 3 elements array that will store the distances of a single phase
		float DistancesBuffer[DistancesBufferSize]{ 0, 0, 0 };

		// Used to write distances of single raycast into the DistanceBuffer 
		int DistanceCounter{ 0 };

		// reset the offset when all 4 phases have completed the scan
		if (AngleOffset > 270)
		{
			AngleOffset = 0;
		}


		/*
		**	Perform three raycasts and store the distances a 3 elements buffer (DistancesBuffer)
		*/

		for (int i{ AngleOffset }; i < 360 + AngleOffset; i += 120)
		{
			// rotate on the Z axis
			FVector RotatedNorthVector = NorthVector.RotateAngleAxis(i % 360, FVector(0, 0, 1));

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
		}

		// offset the angle for the next phase
		AngleOffset += 90;

		// The two shortest distances will be averaged and stored into the PessimisticSinglePhase
		// The two largest distances will be avaraged and stored into the OptimisticSinglePhase
		float PessimisticSinglePhase = AverageSmallestValues(DistancesBuffer, DistancesBufferSize);
		float OptimisticSinglePhase = AverageLargestValues(DistancesBuffer, DistancesBufferSize);

		// new avarages are added to a 4 element short history buffer
		PessimisticPhasesBuffer[PhaseCounter] = PessimisticSinglePhase;
		OptimisticPhasesBuffer[PhaseCounter] = OptimisticSinglePhase;

		PhaseCounter++;

		// TRUE if four completed phases have been completed
		if (PhaseCounter >= 4)
		{
			// reset the counter
			PhaseCounter = 0;

			// The three shortest phases will be averaged and stored into the PessimisticTargetValue
			// The three largest phases will be avaraged and stored into the OptimisticTargetValue
			PessimisticTargetValue = AverageSmallestValues(PessimisticPhasesBuffer, PhasesBufferSize);
			OptimisticTargetValue = AverageLargestValues(OptimisticPhasesBuffer, PhasesBufferSize);



			PessimisticTargetValues[FrameCounter] = PessimisticTargetValue;
			OptimisticTargetValues[FrameCounter] = OptimisticTargetValue;

			FrameCounter++;


			if (FrameCounter >= 4)
			{
				// Smooth out the values over 16 frames
				PessimisticAzimuthValueBeforeMapping = AvarageArrayElements(PessimisticTargetValues, TargetValuesSize);
				OptimisticAzimuthValueBeforeMapping = AvarageArrayElements(OptimisticTargetValues, TargetValuesSize);

				// Map the value into a range from 0 to 1
				PessimisticAzimuthValue = PessimisticAzimuthValueBeforeMapping / AzimuthRayLength;
				OptimisticAzimuthValue = OptimisticAzimuthValueBeforeMapping / AzimuthRayLength;

				// reset the counter
				FrameCounter = 0;
				
				// The system will not calculate further if the player has stopped moving
				bDoOnce = false;
			}

		} // END if (PhaseCounter >= 4)
		
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
float URaycastBasedScanner::FindSmallestValue(const float* ArrayOfElements, const size_t size) const
{
	// Initialise the first value to zero
	float Smallest{ FLT_MAX };


	for (int i{ 0 }; i < size; i++)
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
float URaycastBasedScanner::AverageSmallestValues(const float* ArrayOfElements, const size_t size) const
{
	float sum{ 0.0f };

	for (int i{ 0 }; i < size; i++)
	{
		sum += ArrayOfElements[i];
	}


	float average = (sum - FindLargestValue(ArrayOfElements, size)) / (size - 1);


	return average;
}



/*
**	Find the largest value of an array 
*/
float URaycastBasedScanner::FindLargestValue(const float* ArrayOfElements, const size_t size) const
{
	// Initialise the first value to zero
	float Largest{ 0.0f };


	for (int i{ 0 }; i < size; i++)
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
float URaycastBasedScanner::AverageLargestValues(const float* ArrayOfElements, const size_t size) const
{
	float sum{ 0.0f };

	for (int i{ 0 }; i < size; i++)
	{
		sum += ArrayOfElements[i];
	}

	float average = (sum - FindSmallestValue(ArrayOfElements, size)) / (size - 1);

	return average;
}



/*
**	Find the avarage all the elements contained into an array
*/
float URaycastBasedScanner::AvarageArrayElements(const float* ArrayOfElements, const size_t size) const
{
	float sum{ 0 };

	for (int i{ 0 }; i < size; i++)
	{
		sum += ArrayOfElements[i];
	}

	return (sum / size);
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
		DrawDebugCircle(GetWorld(), OwnerLocation + FVector(1, 1, 0), PessimisticAzimuthValueBeforeMapping, 64, FColor::Green, false, UpdateInterval, 0.0f, 20.0f, FVector(1, 0, 0), FVector(0, 1, 0));
		DrawDebugCircle(GetWorld(), OwnerLocation, OptimisticAzimuthValueBeforeMapping, 64, FColor::Blue, false, UpdateInterval, 0.0f, 20.0f, FVector(1, 0, 0), FVector(0, 1, 0));

		// draw the starting point of the raycast
		DrawDebugSphere(GetWorld(), RayStartLocation, 10, 9, DebugSphereColor, false, UpdateInterval, 0.0, 10.0f);
	}
	// set the debug color to be black because the player is NOT moving OR the system have calculated last 16 frames 
	DebugSphereColor = FColor::Black;

	// If TRUE print to the screen both the optimistic and pessimistic metric
	if (bDebugMetrics)
	{
		FString optimistic = FString::Printf(TEXT("The optimistic metric is %f"), OptimisticAzimuthValue);
		FString pessimistic = FString::Printf(TEXT("The pessimistic metric is %f"), PessimisticAzimuthValue);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(0, UpdateInterval, FColor::Yellow, optimistic);
			GEngine->AddOnScreenDebugMessage(1, UpdateInterval, FColor::Yellow, pessimistic);
		}
	}
}



