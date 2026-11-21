// Copyright Epic Games, Inc. All Rights Reserved.

#include "LivingWorldEncounterPrefab.h"
#include "Net/UnrealNetwork.h"

void ALivingWorldEncounterPrefab::OnRep_EncounterDefinition()
{
}

void ALivingWorldEncounterPrefab::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALivingWorldEncounterPrefab, EncounterDefinition);
}
