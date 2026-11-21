// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortGameplayAbility_ScoutDrone_Tether.h"
#include "Net/UnrealNetwork.h"

void UFortGameplayAbility_ScoutDrone_Tether::OnRep_bIsInSignalLossRange()
{
}

void UFortGameplayAbility_ScoutDrone_Tether::OnRep_bIsInWarningRange()
{
}

void UFortGameplayAbility_ScoutDrone_Tether::StartCheckingDistances()
{
}

void UFortGameplayAbility_ScoutDrone_Tether::StopCheckingDistances()
{
}

void UFortGameplayAbility_ScoutDrone_Tether::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameplayAbility_ScoutDrone_Tether, bIsInWarningRange);
	DOREPLIFETIME(UFortGameplayAbility_ScoutDrone_Tether, bIsInSignalLossRange);
}
