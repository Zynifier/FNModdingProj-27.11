// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortWeaponComponent_TargetModeSelector.h"
#include "Net/UnrealNetwork.h"

void UFortWeaponComponent_TargetModeSelector::OnRep_TargetMode()
{
}

void UFortWeaponComponent_TargetModeSelector::OnSetTargeting(bool bNewIsTargeting)
{
}

void UFortWeaponComponent_TargetModeSelector::ServerSetTargetMode_Implementation(int32 NewTargetMode)
{
}

void UFortWeaponComponent_TargetModeSelector::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortWeaponComponent_TargetModeSelector, TargetMode);
}
