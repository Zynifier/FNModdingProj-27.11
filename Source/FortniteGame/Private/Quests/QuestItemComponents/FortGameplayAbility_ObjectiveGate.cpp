// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/QuestItemComponents/FortGameplayAbility_ObjectiveGate.h"

bool UFortGameplayAbility_ObjectiveGate::BlueprintCanGateClose_Implementation(const FName ObjectiveBackendName) const
{
	return false;
}

bool UFortGameplayAbility_ObjectiveGate::BlueprintCanGateOpen_Implementation(const FName ObjectiveBackendName) const
{
	return false;
}

void UFortGameplayAbility_ObjectiveGate::CloseGates() const
{
}

void UFortGameplayAbility_ObjectiveGate::OpenGates() const
{
}
