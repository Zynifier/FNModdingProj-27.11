// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameFeatureRefactors/MissionStormShield/FortMissionStormShieldManager.h"
#include "Net/UnrealNetwork.h"

UFortMissionStormShieldManager::UFortMissionStormShieldManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UFortMissionStormShieldManager* UFortMissionStormShieldManager::Get(const UObject* WorldContextObject)
{
	return nullptr;
}

AFortMissionStormShield* UFortMissionStormShieldManager::GetMissionStormShield(const UObject* WorldContextObject)
{
	return nullptr;
}

AFortMissionStormShield* UFortMissionStormShieldManager::GetStormShield() const
{
	return nullptr;
}

void UFortMissionStormShieldManager::OnRep_StormShield()
{
}

void UFortMissionStormShieldManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMissionStormShieldManager, StormShield);
}
