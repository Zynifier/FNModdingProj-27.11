// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoveLibrary/MovementUtils.h"

void UMovementUtils::AdjustProposedMoveForRootMotion(FProposedMove& MoveToAdjust, USkeletalMeshComponent* SkeletalMesh, const FVector& GroundNormal, float DeltaSeconds)
{
}

bool UMovementUtils::CanEscapeGravity(const FVector& PriorVelocity, const FVector& NewVelocity, const FVector& GravityAccel, float DeltaSeconds)
{
	return false;
}

bool UMovementUtils::CanStepUpOnHitSurface(const FHitResult& Hit)
{
	return false;
}

FRotator UMovementUtils::ComputeAngularVelocity(const FRotator& From, const FRotator& To, float DeltaSeconds, float TurningRateLimit)
{
	return FRotator();
}

FProposedMove UMovementUtils::ComputeControlledFreeMove(const FFreeMoveParams& InParams)
{
	return FProposedMove();
}

FProposedMove UMovementUtils::ComputeControlledGroundMove(const FGroundMoveParams& InParams)
{
	return FProposedMove();
}

FVector UMovementUtils::ComputeDeflectedMoveOntoRamp(const FVector& OrigMoveDelta, const FHitResult& RampHitResult, float MaxWalkSlopeCosine, const bool bHitFromLineTrace)
{
	return FVector();
}

FVector UMovementUtils::ComputeDirectionIntent(const FVector& MoveInput, EMoveInputType MoveInputType)
{
	return FVector();
}

FVector UMovementUtils::ComputeSlideDelta(const FVector& Delta, const float PctOfDeltaToMove, const FVector& Normal, const FHitResult& Hit)
{
	return FVector();
}

FVector UMovementUtils::ComputeVelocity(const FComputeVelocityParams& InParams)
{
	return FVector();
}

FVector UMovementUtils::ComputeVelocityFromGravity(const FVector& GravityAccel, float DeltaSeconds)
{
	return FVector();
}

FVector UMovementUtils::ComputeVelocityFromPositions(const FVector& FromPos, const FVector& ToPos, float DeltaSeconds)
{
	return FVector();
}

FVector UMovementUtils::ConstrainToPlane(const FVector& Vector, const FPlane& MovementPlane, bool bMaintainMagnitude)
{
	return FVector();
}

bool UMovementUtils::IsExceedingMaxSpeed(const FVector& Velocity, float InMaxSpeed)
{
	return false;
}

bool UMovementUtils::IsHitSurfaceWalkable(const FHitResult& Hit, float MaxWalkSlopeCosine)
{
	return false;
}

bool UMovementUtils::IsValidLandingSpot(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, const FVector& Location, const FHitResult& Hit, float FloorSweepDistance, float MaxWalkSlopeCosine, FFloorCheckResult& OutFloorResult)
{
	return false;
}

float UMovementUtils::TryMoveToFallAlongSurface(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, UKinematicMoverComponent* MoverComponent, const FVector& Delta, float PctOfDeltaToMove, const FQuat Rotation, const FVector& Normal, FHitResult& Hit, bool bHandleImpact, float FloorSweepDistance, float MaxWalkSlopeCosine, FFloorCheckResult& OutFloorResult, FMovementRecord& MoveRecord)
{
	return float();
}

float UMovementUtils::TryMoveToSlideAlongSurface(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, UKinematicMoverComponent* MoverComponent, const FVector& Delta, float PctOfDeltaToMove, const FQuat Rotation, const FVector& Normal, FHitResult& Hit, bool bHandleImpact, FMovementRecord& MoveRecord)
{
	return float();
}

bool UMovementUtils::TrySafeMoveUpdatedComponent(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, const FVector& Delta, const FQuat& NewRotation, bool bSweep, FHitResult& OutHit, ETeleportType Teleport, FMovementRecord& MoveRecord)
{
	return false;
}

float UMovementUtils::TryWalkToSlideAlongSurface(USceneComponent* UpdatedComponent, UPrimitiveComponent* UpdatedPrimitive, UKinematicMoverComponent* MoverComponent, const FVector& Delta, float PctOfDeltaToMove, const FQuat Rotation, const FVector& Normal, FHitResult& Hit, bool bHandleImpact, FMovementRecord& MoveRecord, float MaxWalkSlopeCosine)
{
	return float();
}
