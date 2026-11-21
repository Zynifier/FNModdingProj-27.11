// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/Systems/AthenaAIServiceCreativePlayerBots.h"

void UAthenaAIServiceCreativePlayerBots::AddHiringHistory(AActor* HiredOwner, APlayerController* HiringPlayer)
{
}

void UAthenaAIServiceCreativePlayerBots::ClearHiringHistory(AActor* HiredOwner)
{
}

const APlayerController* UAthenaAIServiceCreativePlayerBots::GetLastHiringPlayer(const AActor* HiredOwner) const
{
	return nullptr;
}

bool UAthenaAIServiceCreativePlayerBots::IsMinigameBotSpawningRequired() const
{
	return false;
}

void UAthenaAIServiceCreativePlayerBots::OnFinishedAddingMinigamePlayer(FUniqueNetIdRepl UniqueNetId, bool bIsLocalPlayer)
{
}

void UAthenaAIServiceCreativePlayerBots::OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState)
{
}
