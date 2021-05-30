/*=============================================================================
	RaycastBasedScanner.h
	
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

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RaycastBasedScanner.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RAYCASTSCANNERPLUGIN_API URaycastBasedScanner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URaycastBasedScanner();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Maximum length of the raycast in the azimuth plane
	UPROPERTY(EditAnywhere, Category = "Raycast-Based Scanner | Setup")
	float AzimuthRayLength{ 1500.0f };

	// The users can specify their own collision channel 
	UPROPERTY(EditAnywhere, Category = "Raycast-Based Scanner | Setup")
	TEnumAsByte<ECollisionChannel> CollisionChannel{ ECC_Visibility };

	// User-defined Tick interval. 
	UPROPERTY(EditAnywhere, meta = (ClampMin = "0.0", ClampMax = "0.5"), Category = "Raycast-Based Scanner | Setup")
	float UpdateInterval{ 0.033f };

	// Offset the height of the starting point of the raycast scanner.
	UPROPERTY(EditAnywhere, Category = "Raycast-Based Scanner | Setup")
	float StartingPointOffset{ 100.0f };

	// The system does not measure if the parent actor changed it's position within this specified error limits
	UPROPERTY(EditAnywhere, Category = "Raycast-Based Scanner | Setup")
	float Tolerance{ 30.0f };

	// If TRUE draw circles around the player (Green = Pessimistic. Blue = Optimistic) and draw a sphere on the raycast's starting point. 
	UPROPERTY(EditAnywhere, Category = "Raycast-Based Scanner | Debug")
	bool bDebugVisualisation{ false };

	// If TRUE print to the screen both the optimistic and pessimistic metric
	UPROPERTY(EditAnywhere, Category = "Raycast-Based Scanner | Debug")
	bool bDebugMetrics{ false };


protected:
	// I use Finish Destroy instead of BeginDestroy because FinishDestroy it's after any async stuff which might still try access the memory.
	virtual void FinishDestroy() override;

	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Find the smallest value of an array
	float FindSmallestValue(const float* ArrayOfElements, const size_t size) const;

	// Average the (size - 1) smallest values of the array
	float AverageSmallestValues(const float* ArrayOfElements, const size_t size) const;

	// Find the largest value of an array
	float FindLargestValue(const float* ArrayOfElements, const size_t size) const;

	// Average the (size - 1) largest values of the array
	float AverageLargestValues(const float* ArrayOfElements, const size_t size) const;

	// Find the avarage of all the elements of the array
	float AvarageArrayElements(const float* ArrayOfElements, const size_t size) const;

	void Debug();

	// Location of the owner of this component
	FVector OwnerLocation;

	// Location of the owner in the previous calculation. Used to check whether the player has moved or not.
	FVector OldOwnerLocation;

	// Structure containing information about one hit of a trace, such as point of impact and surface normal at that point.
	FHitResult HitResult;

	/*
	**	Used to offset the starting angle of the phase. If the offset is 0 the phase would have 0, 120 and 240 angles respectively. 
	**	If the offset is 90 the phase would have 90, 210 and 330 angles.
	*/
	int AngleOffset{ 0 };

	// Raycast start location of the scanner. This can be offset by the user 
	FVector RayStartLocation;

	// Size of both pessimistic and optimistic four elements short history buffer
	const size_t PhasesBufferSize{ 4 };

	// These will be four elements short history buffer containing the result of each completed phases
	float* PessimisticPhasesBuffer;
	float* OptimisticPhasesBuffer;

	// Used to write avaraged distances of single phases into the PhasesBuffer.
	// If PhaseCounter >= 4, the system has calculated four phases 
	int PhaseCounter{ 0 };

	// Used to smooth out the azimuth value over 16 frames
	int FrameCounter{ 0 };

	// Used to measure even thought the player is not moving.
	// This will become false once the player has stopped moving AND the system has calculated 16 frames 
	bool bDoOnce{ true };

	// This is the avarage of the three shortest phases
	float PessimisticTargetValue{ 0.0f };

	// This is the avarage of the three largest phases
	float OptimisticTargetValue{ 0.0f };

	const size_t TargetValuesSize{ 4 };

	// These will contain last 4 target values. 
	// They are used to smooth out the final metric over 16 frames
	float* PessimisticTargetValues;
	float* OptimisticTargetValues;

	// These are the final metric before mapping the values from 0.0 to 1.0
	float PessimisticAzimuthValueBeforeMapping{ 0.0f };
	float OptimisticAzimuthValueBeforeMapping{ 0.0f };

	// Final metrics
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float PessimisticAzimuthValue{ 0 };

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float OptimisticAzimuthValue{ 0 };

	/* 
	**	Color of the sphere corresponding to the raycast's starting point. 
	**	RED if the player is moving or the system is calculating until 16 frames 
	**	BLACK if the player is NOT moving
	*/
	FColor DebugSphereColor{FColor::Black};
};
