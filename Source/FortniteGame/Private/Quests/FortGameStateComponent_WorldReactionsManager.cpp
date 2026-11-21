// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortGameStateComponent_WorldReactionsManager.h"
#include "Net/UnrealNetwork.h"

UFortGameStateComponent_WorldReactionsManager::UFortGameStateComponent_WorldReactionsManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortGameStateComponent_WorldReactionsManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_WorldReactionsManager, WorldReactionsArray);
	DOREPLIFETIME(UFortGameStateComponent_WorldReactionsManager, DebugWorldStates);
}
