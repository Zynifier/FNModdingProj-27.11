// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortMountedTurret.h"
#include "Net/UnrealNetwork.h"

void AFortMountedTurret::DebugDrawTrajectory(const FVector AimDirection, const FVector TargetLocation, const float LaunchVelocity, const float InGravityMult, const FColor LineColor, const float KeepTime, const int32 Subdivisions) const
{
}

FVector AFortMountedTurret::GetAimDirectionToHitTarget(const FVector TargetLocation, const float LaunchVelocity, const float InGravityMult) const
{
	return FVector();
}

void AFortMountedTurret::GetYawPitchDeltaToTargetAimDirection(const int32 SocketIndex, const FVector TargetAimDirection, float& OutYawDelta, float& OutPitchDelta) const
{
}

bool AFortMountedTurret::IsLocalPlayerRiding() const
{
	return false;
}

float AFortMountedTurret::NativeCurrentOverheatScalar(float InReplicateOverheatOf20) const
{
	return float();
}

void AFortMountedTurret::NativeUpdateOverheatCosmetics(const AFortPlayerPawn* InDriverPawn, float InReplicateOverheatOf20, FRotator& OutTurretRotation)
{
}

void AFortMountedTurret::OnRep_TeamIndex(uint8 OldVal)
{
}

void AFortMountedTurret::OnRep_TurretSleeping()
{
}

void AFortMountedTurret::SetManned(bool bInIsManned)
{
}

void AFortMountedTurret::SetOverheating(bool bInIsOverheating)
{
}

bool AFortMountedTurret::ShouldShowActionLabelAtIndex_Implementation(const int32 Index, TArray<FName>& SeatActionNames, TArray<FText>& SeatActionLabels) const
{
	return false;
}

void AFortMountedTurret::TriggerVehicleSeatChangedCallbacks()
{
}

void AFortMountedTurret::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMountedTurret, TeamIndex);
	DOREPLIFETIME(AFortMountedTurret, bTurretSleeping);
}
