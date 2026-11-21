// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Timespan.h"
#include "Athena/Map/AthenaFullScreenMapQuestCategoryBase.h"
#include "Components/FortControllerComponent_PinQuest.h"
#include "Quests/QuestCategoryData.h"
#include "AthenaFullScreenMapQuestCategoryButton.generated.h"

class UAthenaQuestCategoryCompletedTracker;
class UCommonTextBlock;
class UFortLazyImage;
enum class EAthenaChallengeTimerState : uint8;
enum class EQuestCategoryButtonTimerState : uint8;

UENUM(BlueprintType)
enum class EQuestCategoryButtonTimerState : uint8
{
	Countdown = 0,
	Custom = 1,
	Disabled = 2,
	None = 3,
};

UCLASS(Abstract, meta=(Category="Fortnite UI"))
class UAthenaFullScreenMapQuestCategoryButton : public UAthenaFullScreenMapQuestCategoryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_Populate(const FText& Title, const FText& SubText, const int32 CompletedQuests, const int32 TotalQuest, const bool bIsPinned, const FQuestCategoryButtonOverrides& ButtonOverrides, bool bQuestListContentDisabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMoreInTimerSet(const EAthenaChallengeTimerState TimerState, const FTimespan& TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTimeRemainingTimerSet(const EAthenaChallengeTimerState TimerState, const EQuestCategoryButtonTimerState TimerType, const FText& TimerText, const FTimespan TimeRemaining);

private:
	UFUNCTION()
	void HandlePinnedQuestChanged(const FAthenaPinnedQuestData& PinnedQuestData);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapQuestCategoryButton", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DebugCategoryName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapQuestCategoryButton", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_Icon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapQuestCategoryButton", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaQuestCategoryCompletedTracker> Widget_AthenaQuestCategoryCompletedTracker;

};

