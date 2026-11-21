// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "FortItemQuantityPair.h"
#include "BattleLabRewardWidget.generated.h"

class UFortQuestItem;
class UFortQuestObjectiveInfo;
class UTexture2D;

UENUM(BlueprintType)
enum class EBattleLabAlertType : uint8
{
	QuestComplete = 0,
	QuestGranted = 1,
	Reward = 2,
};

USTRUCT(BlueprintType)
struct FBattleLabDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="BattleLabDisplayData")
	FText TitleText;

	UPROPERTY(BlueprintReadOnly, Category="BattleLabDisplayData")
	FText DescriptionText;

	UPROPERTY(BlueprintReadOnly, Category="BattleLabDisplayData")
	EBattleLabAlertType AlertType;

	UPROPERTY(BlueprintReadOnly, Category="BattleLabDisplayData")
	int32 RewardCount;

	UPROPERTY(BlueprintReadOnly, Category="BattleLabDisplayData")
	int32 RewardCountTotal;

	UPROPERTY(BlueprintReadOnly, Category="BattleLabDisplayData")
	TSoftObjectPtr<UTexture2D> MainIconTexture;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UBattleLabRewardWidget : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleDisplayDynamicQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool DisplayStatusUpdate, bool DisplayAnnouncementUpdate);

	UFUNCTION()
	void HandleOnQuestCompleted(const TArray<UFortQuestItem*>& Quests);

	UFUNCTION()
	void HandleOnQuestsGranted(const TArray<UFortQuestItem*>& Quests);

	UFUNCTION(BlueprintCallable)
	void OnWidgetIsFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OpenWidget(const FBattleLabDisplayData& DisplayData);

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestItem>> CompletedQuests;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestItem>> NewlyGrantedQuests;

	UPROPERTY()
	TArray<FFortItemQuantityPair> GrantedRewards;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestItem>> OldQuests;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FGameplayTagContainer RequiredTags;

};

