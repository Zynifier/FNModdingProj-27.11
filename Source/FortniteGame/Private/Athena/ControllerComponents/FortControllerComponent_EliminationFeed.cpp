// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ControllerComponents/FortControllerComponent_EliminationFeed.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_EliminationFeed::AddMessageToQueue(const AFortCreativeDeviceProp* EliminationFeedDevice, const AFortPlayerState* PlayerStateMessage)
{
}

UFortControllerComponent_EliminationFeed* UFortControllerComponent_EliminationFeed::GetEliminationFeedComponentFromPlayerController(AFortPlayerController* PC, bool bCreateIfNotFound)
{
	return nullptr;
}

void UFortControllerComponent_EliminationFeed::GetMinigamePlayersForEliminationFeed(const AFortMinigame* FortMinigame, TArray<APlayerState*>& OutPlayers)
{
}

void UFortControllerComponent_EliminationFeed::OnRep_EliminationFeedMessageBatch()
{
}

void UFortControllerComponent_EliminationFeed::Reset()
{
}

void UFortControllerComponent_EliminationFeed::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_EliminationFeed, EliminationFeedMessageBatch);
}
