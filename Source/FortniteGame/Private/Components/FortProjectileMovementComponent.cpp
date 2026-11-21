// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortProjectileMovementComponent.h"
#include "Net/UnrealNetwork.h"

EFortHomingStyle UFortProjectileMovementComponent::GetInitalHomingStyle() const
{
	return EFortHomingStyle();
}

void UFortProjectileMovementComponent::OnRep_FortStopSimulatingRepData()
{
}

void UFortProjectileMovementComponent::OnRep_HomingData()
{
}

void UFortProjectileMovementComponent::OnRep_ReplicatedAutoRegisterUpdatedComponent()
{
}

void UFortProjectileMovementComponent::OnRep_ReplicatedVelocity()
{
}

void UFortProjectileMovementComponent::SetAccelerationMagnitude(const float InAccelerationMagnitude)
{
}

void UFortProjectileMovementComponent::SetDesiredDirection(const FVector& Direction)
{
}

void UFortProjectileMovementComponent::SetHomingData(const FProjectileHomingData& NewHomingData)
{
}

void UFortProjectileMovementComponent::SetHomingLaserTargetDistance(float NewDistance)
{
}

void UFortProjectileMovementComponent::SetHomingLockTargetDistanceThreshold(float NewDistanceThreshold)
{
}

void UFortProjectileMovementComponent::SetHomingStyle(EFortHomingStyle NewHomingStyle, bool ResetHomingTurnSpeedTimer)
{
}

void UFortProjectileMovementComponent::SetHomingTarget(AActor* HomingTarget)
{
}

void UFortProjectileMovementComponent::SetHomingTargetOffset(const FVector& NewHomingOffset, const bool bScaleTargetOffsetWithCapsuleHeight)
{
}

void UFortProjectileMovementComponent::SetHomingTargetPosition(const FVector& HomingTargetPosition)
{
}

void UFortProjectileMovementComponent::SetHomingTimeUntilMaxTurnSpeed(float NewTimeUntilMax)
{
}

void UFortProjectileMovementComponent::SetHomingTurnSpeedMax(float NewHomingTurnSpeedMax)
{
}

void UFortProjectileMovementComponent::SetHomingTurnSpeedMin(float NewHomingTurnSpeedMin)
{
}

void UFortProjectileMovementComponent::SetReplicatedAutoRegisterUpdatedComponent(const bool bInReplicatedAutoRegisterUpdatedComponent)
{
}

void UFortProjectileMovementComponent::SetVelocity(const FVector& InReplicatedVelocity)
{
}

void UFortProjectileMovementComponent::SetWaterInteractionComponent(UFortWaterInteractionComponent* WaterComponent)
{
}

void UFortProjectileMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortProjectileMovementComponent, HomingData);
	DOREPLIFETIME(UFortProjectileMovementComponent, bReplicatedAutoRegisterUpdatedComponent);
	DOREPLIFETIME(UFortProjectileMovementComponent, DesiredDirection);
	DOREPLIFETIME(UFortProjectileMovementComponent, AccelerationMagnitude);
	DOREPLIFETIME(UFortProjectileMovementComponent, ReplicatedVelocityData);
	DOREPLIFETIME(UFortProjectileMovementComponent, FortStopSimulatingRepData);
}
