// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_PlayerClassSettings.h"
#include "Net/UnrealNetwork.h"

bool AFortAthenaMutator_PlayerClassSettings::AddDataSourceForPlayerClass(uint8 ClassSlotIndex, const UObject* DataSource)
{
	return false;
}

uint8 AFortAthenaMutator_PlayerClassSettings::GetClassContext() const
{
	return uint8();
}

bool AFortAthenaMutator_PlayerClassSettings::RemoveDataSource(const UObject* DataSource)
{
	return false;
}

void AFortAthenaMutator_PlayerClassSettings::SetClassContext(uint8 ClassSlotIndex)
{
}

bool AFortAthenaMutator_PlayerClassSettings::SetupGameRulesForClassContext_Implementation(AFortMinigame* Minigame)
{
	return false;
}

void UFortPlayerClassSettingsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayerClassSettingsComponent, ClassSlotIndex);
}
