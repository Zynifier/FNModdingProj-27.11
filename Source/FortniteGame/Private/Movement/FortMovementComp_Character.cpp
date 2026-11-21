// Copyright Epic Games, Inc. All Rights Reserved.

#include "Movement/FortMovementComp_Character.h"

float UFortMovementComp_Character::GetFallingStartedZ() const
{
	return float();
}

bool UFortMovementComp_Character::GetModifiedOrientRotationToMovement() const
{
	return false;
}

bool UFortMovementComp_Character::GetModifiedUseControllerDesiredRotation() const
{
	return false;
}

FVector UFortMovementComp_Character::GetPlayerRelativeVelocityToWater() const
{
	return FVector();
}

FSlidingControlParams UFortMovementComp_Character::GetSlidingControlParams() const
{
	return FSlidingControlParams();
}

bool UFortMovementComp_Character::GetSwingAttached() const
{
	return false;
}

bool UFortMovementComp_Character::GetSwingAttachedVehicle() const
{
	return false;
}

const FSwingingControlParams& UFortMovementComp_Character::GetSwingingControlParameters() const
{
	static FSwingingControlParams Dummy;
	return Dummy;
}

float UFortMovementComp_Character::GetSwingingDistanceToGround() const
{
	return float();
}

float UFortMovementComp_Character::GetWaterImmersionDepth() const
{
	return float();
}

FVector UFortMovementComp_Character::GetWaterSurfaceLocation() const
{
	return FVector();
}

FVector UFortMovementComp_Character::GetWaterSurfaceNormal() const
{
	return FVector();
}

FVector UFortMovementComp_Character::GetWaterVelocity() const
{
	return FVector();
}

bool UFortMovementComp_Character::IsActivelyParachuting() const
{
	return false;
}

bool UFortMovementComp_Character::IsActivelySkydiving(const bool bCheckMovementMode) const
{
	return false;
}

bool UFortMovementComp_Character::IsActivelySkydivingUpInVortex() const
{
	return false;
}

bool UFortMovementComp_Character::IsActivelyStrafingInAir(const bool bCheckMovementMode) const
{
	return false;
}

bool UFortMovementComp_Character::IsPassivelyParachuting() const
{
	return false;
}

bool UFortMovementComp_Character::IsPassivelySkydiving() const
{
	return false;
}

bool UFortMovementComp_Character::IsSwingingAir() const
{
	return false;
}

bool UFortMovementComp_Character::IsSwingingGround() const
{
	return false;
}

bool UFortMovementComp_Character::SetActiveOverrideSwingingControlParameters(const FGameplayTag ControlParametersTag)
{
	return false;
}

void UFortMovementComp_Character::SetFromBusForTesting(const bool bInShouldBeFromBus)
{
}

void UFortMovementComp_Character::SetHasReplicatedAcceleration(const bool bInHasReplicatedAcceleration)
{
}

void UFortMovementComp_Character::SetSlidingControlParams(FSlidingControlParams NewSlidingControlParams)
{
}

void UFortMovementComp_Character::SetUseHighAccelerationTolerance(const bool bShouldUseHighTolerance, const FName UseHighToleranceId)
{
}
