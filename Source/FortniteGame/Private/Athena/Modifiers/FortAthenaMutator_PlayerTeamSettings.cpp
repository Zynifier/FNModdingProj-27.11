// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_PlayerTeamSettings.h"
#include "Net/UnrealNetwork.h"

bool AFortAthenaMutator_PlayerTeamSettings::AddDataSourceForTeam(uint8 TeamIndex, const UObject* DataSource)
{
	return false;
}

UFortPlayerTeamSettingsComponent* AFortAthenaMutator_PlayerTeamSettings::GetComponentForEnabledSetting(const FName& PropertyName, bool bFallbackToDefaultTeam) const
{
	return nullptr;
}

uint8 AFortAthenaMutator_PlayerTeamSettings::GetTeamContext() const
{
	return uint8();
}

bool AFortAthenaMutator_PlayerTeamSettings::RemoveDataSource(const UObject* DataSource)
{
	return false;
}

void AFortAthenaMutator_PlayerTeamSettings::SetTeamContext(uint8 TeamIndex)
{
}

bool AFortAthenaMutator_PlayerTeamSettings::SetupGameRulesForTeamContext_Implementation(AFortMinigame* Minigame)
{
	return false;
}

void UFortPlayerTeamSettingsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayerTeamSettingsComponent, TeamIndex);
	DOREPLIFETIME(UFortPlayerTeamSettingsComponent, bRunOutTimeToWin);
}
