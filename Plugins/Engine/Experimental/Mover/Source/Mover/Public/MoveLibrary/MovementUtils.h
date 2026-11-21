// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "MoveLibrary/MovementRecord.h"
#include "MoveLibrary/MovementUtilsTypes.h"
#include "MoverDataModelTypes.h"
#include "MovementUtils.generated.h"

class UKinematicMoverComponent;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMeshComponent;
enum class EMoveInputType : uint8;

// Input parameters for compute velocity function

USTRUCT(BlueprintType)
struct MOVER_API FComputeVelocityParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float DeltaSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FVector InitialVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FVector MoveDirectionIntent;

	// AuxState variables

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float TurningBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float Deceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float Acceleration;

};

/** Data about the floor for walking movement, used by Mover simulations */
USTRUCT(BlueprintType)
struct MOVER_API FFloorCheckResult
{
	GENERATED_BODY()

public:
	/**
	* True if there was a blocking hit in the floor test that was NOT in initial penetration.
	* The HitResult can give more info about other circumstances.
	*/
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterFloor")
	uint8 bBlockingHit : 1;

	/** True if the hit found a valid walkable floor. */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterFloor")
	uint8 bWalkableFloor : 1;

	/** True if the hit found a valid walkable floor using a line trace (rather than a sweep test, which happens when the sweep test fails to yield a walkable surface). */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterFloor")
	uint8 bLineTrace : 1;

	/** The distance to the floor, computed from the trace. Only valid if bLineTrace is true. */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterFloor")
	float LineDist;

	/** The distance to the floor, computed from the swept capsule trace. */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterFloor")
	float FloorDist;

	/** Hit result of the test that found a floor. Includes more specific data about the point of impact and surface normal at that point. */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterFloor")
	FHitResult HitResult;

};

// Input parameters for controlled free movement function

USTRUCT(BlueprintType)
struct MOVER_API FFreeMoveParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	EMoveInputType MoveInputType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FVector MoveInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FRotator OrientationIntent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FVector PriorVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FRotator PriorOrientation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float Deceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float TurningBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float TurningRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float DeltaSeconds;

};

// Input parameters for controlled ground movement function

USTRUCT(BlueprintType)
struct MOVER_API FGroundMoveParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	EMoveInputType MoveInputType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FVector MoveInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FRotator OrientationIntent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FVector PriorVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FRotator PriorOrientation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float Deceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float TurningRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float TurningBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FVector GroundNormal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	float DeltaSeconds;

};

/** Encapsulates detailed trajectory sample info, from a move that has already occurred or one projected into the future */
USTRUCT(BlueprintType)
struct MOVER_API FTrajectorySampleInfo
{
	GENERATED_BODY()

};

/** Data about the overlapping volume typically used for swimming */
USTRUCT(BlueprintType)
struct MOVER_API FWaterCheckResult
{
	GENERATED_BODY()

public:
	/** True if the hit found a valid swimmable volume. */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterVolume")
	uint8 bSwimmableVolume : 1;

	/** Velocity of water at the point of query */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterVolume")
	FVector Velocity;

	/** Depth of water at the point of query */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterVolume")
	float Depth;

	/** Immersion in water at the point of query */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterVolume")
	float ImmersionDepth;

	/** Hit result of the test that found a volume. Includes more specific data about the point of impact and surface normal at that point. */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CharacterVolume")
	FHitResult HitResult;

};

/**
 * MovementUtils: a collection of stateless static BP-accessible functions for a variety of movement-related operations
 */
UCLASS()
class MOVER_API UMovementUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Adjusts a move to account for active root motion, which may alter or nullify a proposed move. This will consume any accumulated motion from the mesh. */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static void AdjustProposedMoveForRootMotion(FProposedMove& MoveToAdjust, USkeletalMeshComponent* SkeletalMesh, const FVector& GroundNormal, float DeltaSeconds);

	/** Checks whether a given velocity is strong enough to lift off against gravity */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static bool CanEscapeGravity(const FVector& PriorVelocity, const FVector& NewVelocity, const FVector& GravityAccel, float DeltaSeconds);

	UFUNCTION(BlueprintCallable, Category="Mover")
	static bool CanStepUpOnHitSurface(const FHitResult& Hit);

	/** Computes the angular velocity needed to change from one orientation to another within a time frame. Use the optional TurningRateLimit to clamp to a maximum step (negative=unlimited). */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FRotator ComputeAngularVelocity(const FRotator& From, const FRotator& To, float DeltaSeconds, float TurningRateLimit = -1.000000f);

	/** Generate a new movement based on move/orientation intents and the prior state, unconstrained like when flying */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FProposedMove ComputeControlledFreeMove(const FFreeMoveParams& InParams);

	/** Generate a new movement based on move/orientation intents and the prior state, constrained to the ground movement plane. Also applies deceleration friction as necessary. */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FProposedMove ComputeControlledGroundMove(const FGroundMoveParams& InParams);

	/** Used to change a movement to be along a ramp's surface, typically to prevent slow movement when running up/down a ramp */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector ComputeDeflectedMoveOntoRamp(const FVector& OrigMoveDelta, const FHitResult& RampHitResult, float MaxWalkSlopeCosine, const bool bHitFromLineTrace);

	/** Computes the directional movement intent based on input vector and associated type */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector ComputeDirectionIntent(const FVector& MoveInput, EMoveInputType MoveInputType);

	/** Returns an alternative move delta to slide along a surface, based on parameters describing a blocked attempted move */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector ComputeSlideDelta(const FVector& Delta, const float PctOfDeltaToMove, const FVector& Normal, const FHitResult& Hit);

	/** Returns new ground-based velocity (worldspace) based on previous state, movement intent (worldspace), and movement settings */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector ComputeVelocity(const FComputeVelocityParams& InParams);

	/** Returns velocity (units per second) contributed by gravitational acceleration over a given time */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector ComputeVelocityFromGravity(const FVector& GravityAccel, float DeltaSeconds);

	/** Computes velocity based on start and end positions over time */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector ComputeVelocityFromPositions(const FVector& FromPos, const FVector& ToPos, float DeltaSeconds);

	/** Ensures input Vector (typically a velocity, acceleration, or move delta) is limited to a movement plane. 
	* @param bMaintainMagnitude - if true, vector will be scaled after projection in an attempt to keep magnitude the same 
	*/
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector ConstrainToPlane(const FVector& Vector, const FPlane& MovementPlane, bool bMaintainMagnitude = true);

	/** Checks whether a given velocity is exceeding a maximum speed, with some leeway to account for numeric imprecision */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static bool IsExceedingMaxSpeed(const FVector& Velocity, float InMaxSpeed);

	UFUNCTION(BlueprintCallable, Category="Mover")
	static bool IsHitSurfaceWalkable(const FHitResult& Hit, float MaxWalkSlopeCosine);

	// Checks if a hit result represents a walkable location that an actor can land on

	UFUNCTION(BlueprintCallable, Category="Mover")
	static bool IsValidLandingSpot(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, const FVector& Location, const FHitResult& Hit, float FloorSweepDistance, float MaxWalkSlopeCosine, FFloorCheckResult& OutFloorResult);

	/** Attempts to move a component along a surface, while checking for landing on a walkable surface. Intended for use while falling. Returns the percent of time applied, with 0.0 meaning no movement occurred. */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static float TryMoveToFallAlongSurface(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, UKinematicMoverComponent* MoverComponent, const FVector& Delta, float PctOfDeltaToMove, const FQuat Rotation, const FVector& Normal, FHitResult& Hit, bool bHandleImpact, float FloorSweepDistance, float MaxWalkSlopeCosine, FFloorCheckResult& OutFloorResult, FMovementRecord& MoveRecord);

	/** Attempts to move a component along a surface. Returns the percent of time applied, with 0.0 meaning no movement occurred. */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static float TryMoveToSlideAlongSurface(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, UKinematicMoverComponent* MoverComponent, const FVector& Delta, float PctOfDeltaToMove, const FQuat Rotation, const FVector& Normal, FHitResult& Hit, bool bHandleImpact, FMovementRecord& MoveRecord);

	/** Attempts to move a component and resolve any penetration issues with the proposed move Delta */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static bool TrySafeMoveUpdatedComponent(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, const FVector& Delta, const FQuat& NewRotation, bool bSweep, FHitResult& OutHit, ETeleportType Teleport, FMovementRecord& MoveRecord);

	/** Attempts to move a component along a surface in the walking mode. Returns the percent of time applied, with 0.0 meaning no movement occurred.
	 *  Note: This modifies the normal and calls UMovementUtils::TryMoveToSlideAlongSurface
	 */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static float TryWalkToSlideAlongSurface(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, UKinematicMoverComponent* MoverComponent, const FVector& Delta, float PctOfDeltaToMove, const FQuat Rotation, const FVector& Normal, FHitResult& Hit, bool bHandleImpact, FMovementRecord& MoveRecord, float MaxWalkSlopeCosine);

};

