// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_LootChoice.h"
#include "Net/UnrealNetwork.h"

ECustomLootSelection AFortAthenaMutator_LootChoice::GetLootSelection()
{
	return ECustomLootSelection();
}

void AFortAthenaMutator_LootChoice::SetLootSelection(ECustomLootSelection NewSelection)
{
}

void AFortAthenaMutator_LootChoice::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_LootChoice, LootSelection);
	DOREPLIFETIME(AFortAthenaMutator_LootChoice, bUsingExperimentalTables);
}
