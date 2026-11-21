// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortGameplayAbility_ScoutDrone_PassiveMark.h"
#include "Net/UnrealNetwork.h"

void UFortGameplayAbility_ScoutDrone_PassiveMark::OnActorIndicatorExpired(AActor* IndicatedActor)
{
}

void UFortGameplayAbility_ScoutDrone_PassiveMark::OnRep_CurrentTargetStatus()
{
}

void UFortGameplayAbility_ScoutDrone_PassiveMark::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameplayAbility_ScoutDrone_PassiveMark, CurrentTargetStatus);
}
