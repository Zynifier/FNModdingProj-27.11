// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Tutorial/FortAthenaTutorialManager.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaTutorialManager::Server_OnClientReadyToStartMatch_Implementation()
{
}

void AFortAthenaTutorialManager::Server_OnTutorialScreenCompleted_Implementation()
{
}

void AFortAthenaTutorialManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaTutorialManager, CurrentTutorialIndex);
}
