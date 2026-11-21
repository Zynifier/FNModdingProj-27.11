// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortGameStatePvE.h"
#include "Net/UnrealNetwork.h"

bool AFortGameStatePvE::CanSpawnDefender(AFortPlayerStateZone* PlayerCausingRemoval, const FName& RemoveFromDefenderSquadId, AFortAIPawn*& OutDefenderToBeRemoved, EDefenderSpawnFailureReason& OutFailureReason) const
{
	return false;
}

bool AFortGameStatePvE::CanSwapWeapon(const UFortItemDefinition* ItemDefinition) const
{
	return false;
}

AFortAircraft* AFortGameStatePvE::GetAircraft() const
{
	return nullptr;
}

void AFortGameStatePvE::GetPickupManagementSettings(FPickupManagementSettings& PickupSettings)
{
}

bool AFortGameStatePvE::IsDefenderItemDeployed(UFortItem* DefenderItem, AFortPlayerStateZone* RequestingPlayer) const
{
	return false;
}

bool AFortGameStatePvE::IsMulchingAllowed() const
{
	return false;
}

bool AFortGameStatePvE::IsSwappableWeaponType(const UFortItemDefinition* ItemDefinition) const
{
	return false;
}

bool AFortGameStatePvE::IsWeaponSwappingEnabled() const
{
	return false;
}

void AFortGameStatePvE::OnDefenderDeployed(AFortAIPawn* Defender)
{
}

void AFortGameStatePvE::OnDefenderRemoved(AFortAIPawn* Defender)
{
}

void AFortGameStatePvE::SetGameDifficultyExplicitly(const float InGameDifficulty)
{
}

void AFortGameStatePvE::SetGameDifficultyRow(const FDataTableRowHandle& GameDifficultyInfo)
{
}

void AFortGameStatePvE::SetPickupManagementSettings(FPickupManagementSettings& PickupSettings)
{
}

bool AFortGameStatePvE::ShouldUseMoonbeamGameplayFunctionality() const
{
	return false;
}

bool AFortGameStatePvE::ShouldUseMoonbeamHUD() const
{
	return false;
}

void AFortGameStatePvE::StartMaxMatchWarningTimer()
{
}

void AFortGameStatePvE::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameStatePvE, bAllowMulching);
	DOREPLIFETIME(AFortGameStatePvE, DeployedDefenders);
	DOREPLIFETIME(AFortGameStatePvE, Aircraft);
	DOREPLIFETIME(AFortGameStatePvE, bUseMoonbeamHUD);
}
