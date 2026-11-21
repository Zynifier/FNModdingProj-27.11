// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaChallengesWidget.h"
#include "FortUrgentQuestData.h"
#include "AthenaSpecialEventChallengesWidget.generated.h"

class AFortPlayerStateAthena;
class UUserWidget;
enum class EFortQuestState : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpecialEventChallengesWidget : public UAthenaChallengesWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="AthenaSpecialEventChallengesWidget")
	float UrgentQuestMessagingStartBuffer;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSpecialEventChallengesWidget")
	TObjectPtr<AFortPlayerStateAthena> AttachedPlayerState;

private:
	UFUNCTION()
	void HandleClearAllUrgentQuestEntries();

	UFUNCTION()
	void HandleSpectatorCompleteUrgentQuest(const FGameplayTag& EventTag);

	UFUNCTION()
	void HandleSpectatorFailUrgentQuest(const FGameplayTag& EventTag);

	UFUNCTION()
	void HandleUrgentQuestDescOverrideChanged(const FGameplayTag& UrgentQuestTag, const FGameplayTag& OverrideTag);

	UFUNCTION()
	void HandleUrgentQuestEnded(AFortPlayerStateAthena* PlayerState, const FGameplayTag& EventTag, const EFortQuestState QuestState);

	UFUNCTION()
	void HandleUrgentQuestStarted(const FUrgentQuestData& InUrgentQuestData, const float EventTimeRemaining);

	UFUNCTION()
	void RemoveEntry(UUserWidget* Entry);

	UPROPERTY(Transient)
	TArray<FUrgentQuestData> ActiveUrgentQuestDataArray;

};

