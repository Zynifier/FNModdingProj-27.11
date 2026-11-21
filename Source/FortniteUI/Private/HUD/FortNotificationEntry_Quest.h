// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ChallengeBundles/FortChallengeSetStyle.h"
#include "HUD/FortNotificationEntry.h"
#include "FortNotificationEntry_Quest.generated.h"

class UAthenaChallengeDateTimeTextBlock;
class UBorder;
class UButton;
class UCommonTextBlock;
class UFortQuestItem;
class UObject;
class URichTextBlock;
class UXpEarnedSubNotification;
enum class EAthenaChallengeTimerState : uint8;
enum class EFortRarity : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortNotificationEntry_Quest : public UFortNotificationEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnableCompleteFlavorText(bool IsEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayRushedNotificationIntro(float Rate);

	UFUNCTION(BlueprintImplementableEvent)
	void SetAssistData(bool bWasAssisted, const FString& OtherPlayersName);

	UFUNCTION(BlueprintCallable)
	void TrackCurrentQuest();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDefaultObjectiveVisuals();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateQuestVisuals(const FFortChallengeSetStyle& DisplayStyle);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Initialize Quest Notification Finished"))
	void BP_OnInitializeQuestNotificationFinished();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Rarity Set"))
	void BP_OnRaritySet(EFortRarity Rarity);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Timer Set"))
	void BP_OnTimerSet(EAthenaChallengeTimerState TimerState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateNotificationBackground(const TSoftObjectPtr<UObject>& AssetToDisplay, bool bUseRarityContainer, bool bIsDailyPunchcardQuest);

	UFUNCTION(BlueprintCallable)
	void ShowNextStagedObjectiveInformation();

	UPROPERTY(EditAnywhere, Category="FortNotificationEntry_Quest")
	TArray<FName> BoundActions;

	UPROPERTY(BlueprintReadOnly, Category="FortNotificationEntry_Quest")
	int32 GoalCount;

	UPROPERTY(BlueprintReadOnly, Category="FortNotificationEntry_Quest")
	int32 CurrentCount;

	UPROPERTY(BlueprintReadOnly, Category="FortNotificationEntry_Quest")
	int32 PreviousCount;

	UPROPERTY(BlueprintReadOnly, Category="FortNotificationEntry_Quest")
	bool bNeedsStagedNotification;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_Quest", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_Quest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeDateTimeTextBlock> DateTimeText_TimeRemaining;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_Quest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_Quest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CategoryDisplay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_Quest", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_ObjectivesCompleted;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_Quest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FlavorText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_Quest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_AssistedBy;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_Quest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UXpEarnedSubNotification> XpSubNotification;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> Button_MobileClickCatcher;

	UPROPERTY()
	TWeakObjectPtr<UFortQuestItem> WeakQuest;

	UPROPERTY()
	FName ObjectiveName;

};

