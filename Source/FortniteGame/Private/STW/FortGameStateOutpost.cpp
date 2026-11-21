// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortGameStateOutpost.h"
#include "Net/UnrealNetwork.h"

const bool AFortGameStateOutpost::DoesOutpostStatusAllowMissionStart() const
{
	return bool();
}

float AFortGameStateOutpost::GetPrepTime(const FName& OutpostDefenseType) const
{
	return float();
}

bool AFortGameStateOutpost::IsWithinPrepTime(const FName& OutpostDefenseType) const
{
	return false;
}

void AFortGameStateOutpost::OnRep_PlayerWeaponSkillLevel()
{
}

void AFortGameStateOutpost::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameStateOutpost, bOutpostDefenseActive);
	DOREPLIFETIME(AFortGameStateOutpost, bWargameActive);
	DOREPLIFETIME(AFortGameStateOutpost, StormShieldDefenseType);
	DOREPLIFETIME(AFortGameStateOutpost, bOutpostStatusAllowsMissionStart);
	DOREPLIFETIME(AFortGameStateOutpost, PlayerWeaponSkillLevel);
}
