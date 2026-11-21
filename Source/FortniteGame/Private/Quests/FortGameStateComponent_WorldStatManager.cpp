// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortGameStateComponent_WorldStatManager.h"
#include "Net/UnrealNetwork.h"

UFortGameStateComponent_WorldStatManager::UFortGameStateComponent_WorldStatManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortGameStateComponent_WorldStatManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_WorldStatManager, WorldStatsArray);
}
