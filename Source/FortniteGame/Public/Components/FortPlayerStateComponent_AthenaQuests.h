// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AthenaPlayerMatchReport.h"
#include "Components/FortPlayerStateComponent_Quests.h"
#include "FortUrgentQuestData.h"
#include "FortPlayerStateComponent_AthenaQuests.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerStateComponent_AthenaQuests : public UFortPlayerStateComponent_Quests
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNoLongerTargetingBotUrgentQuest);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpectatorClearUrgentQuests);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpectatorEndUrgentQuest, const FGameplayTag&, UrgentQuestEventTag);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpectatorUrgentQuest, const FUrgentQuestData&, UrgentQuestData, const float, EventTimeRemaining);

public:
	UFUNCTION()
	void HandleNoLongerTargetingBotUrgentQuest();

private:
	UFUNCTION(Client, Reliable)
	void ClientSpectatorClearUrgentQuestEntries();

	UFUNCTION(Client, Reliable)
	void ClientSpectatorCompleteUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData, const FGameplayTag& CompletedEventTag);

	UFUNCTION(Client, Reliable)
	void ClientSpectatorFailUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData, const FGameplayTag& FailedEventTag);

	UFUNCTION(Client, Reliable)
	void ClientSpectatorShowUrgentQuestEntry(const FUrgentQuestData& UrgentQuestData);

	UFUNCTION(Client, Reliable)
	void ClientSpectatorShowUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData);

	UFUNCTION()
	void HandleMatchRewardNotification(const FAthenaRewardResult& MatchRewardData);

};

