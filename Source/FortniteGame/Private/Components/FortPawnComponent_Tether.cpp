// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortPawnComponent_Tether.h"
#include "Net/UnrealNetwork.h"

void UFortPawnComponent_Tether::DelayedSetViewTargetToTetherPawn()
{
}

void UFortPawnComponent_Tether::GamepadTetheredExitAndReloadReleased()
{
}

void UFortPawnComponent_Tether::OnRep_TetheredWithoutWeapon()
{
}

void UFortPawnComponent_Tether::OnRep_TetherPawn()
{
}

void UFortPawnComponent_Tether::ServerReleaseTether_Implementation()
{
}

void UFortPawnComponent_Tether::ServerRequestTetherJump_Implementation()
{
}

void UFortPawnComponent_Tether::SetViewTargetToTetherPawn()
{
}

void UFortPawnComponent_Tether::TetheredBoostPressed()
{
}

void UFortPawnComponent_Tether::TetheredBoostReleased()
{
}

void UFortPawnComponent_Tether::TetheredExitPressed()
{
}

void UFortPawnComponent_Tether::TetheredExitReleased()
{
}

void UFortPawnComponent_Tether::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPawnComponent_Tether, TetherPawn);
	DOREPLIFETIME(UFortPawnComponent_Tether, bTetheredWithoutWeapon);
}
