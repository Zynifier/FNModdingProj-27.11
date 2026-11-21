// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingProp_BountyBoard.h"
#include "Net/UnrealNetwork.h"

void ABuildingProp_BountyBoard::MulticastSetInteractionText_Implementation(const TArray<FPawnBountyInteractionInfo>& PawnBountyInteractionInfo)
{
}

void ABuildingProp_BountyBoard::NotifyBountyEnded(AFortPlayerStateAthena* HunterPlayerState, const FGameplayTag& UrgentQuestTag, const EFortQuestState QuestState)
{
}

void ABuildingProp_BountyBoard::OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState)
{
}

void ABuildingProp_BountyBoard::OnRep_PlayersGrantedBounty()
{
}

void ABuildingProp_BountyBoard::StartUpdatingInteractionText(const AActor* TriggeredActor)
{
}

void ABuildingProp_BountyBoard::StopUpdatingInteractionText(const AActor* TriggeredActor)
{
}

void ABuildingProp_BountyBoard::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingProp_BountyBoard, PlayersGrantedBounty);
}
