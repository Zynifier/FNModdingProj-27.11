// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Challenges/AthenaChallengeListEntry.h"
#include "Components/FortControllerComponent_PinQuest.h"
#include "AthenaChallengeListEntry_NpcQuest.generated.h"

class UAthenaChallengeDateTimeTextBlock;
class UAthenaChallengeListEntryControls;
class UAthenaChallengeRewards;
class UCommonTextBlock;
class UFortAccountItem;
class UFortLazyImage;
class UFortQuestItem;
class UHorizontalBox;
class UObject;
class URichTextBlock;
class USizeBox;
enum class EAthenaChallengeTimerState : uint8;
enum class EFortRarity : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_NpcQuest : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetIsCompleted() const;

	UFUNCTION(BlueprintPure)
	bool HasVisibleRewards() const;

	UFUNCTION(BlueprintPure)
	bool IsChallengeRefreshingDaily() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_FormatForChallengeOwnerLeftGame(bool bHasOwnerLeftGame);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Challenge Seen Changed"))
	void BP_OnChallengeSeenChanged(bool bChallengeSeen);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Quest Giver Icon Set"))
	void BP_OnQuestGiverIconSet(const UObject* QuestIcon);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Rarity Set"))
	void BP_OnRaritySet(EFortRarity Rarity);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Selected For Quest Replacing"))
	void BP_OnSelectedForQuestReplacing(bool bSelected);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Timer Set"))
	void BP_OnTimerSet(EAthenaChallengeTimerState TimerState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetState(bool bIsCompleted, bool bIsLocked, bool bIsPartyAssisted);

private:
	UFUNCTION()
	void HandleObjectiveUpdate(const UFortQuestItem* QuestItem, const FName Objective, const int32 AchievedCount, const int32 GoalCount);

	UFUNCTION()
	void HandleQuestSeen(const UFortAccountItem* AccountItem);

	UFUNCTION()
	void HandleViewPlaylistButtonClicked();

	UFUNCTION(BlueprintPure, meta=(AllowPrivateAccess))
	bool IsSelected() const;

	UFUNCTION()
	void UpdateIconUL(const FAthenaPinnedQuestData& PinnedQuestData);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_ChallengeDesc;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_ObjectivesCompletedSelected;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_ObjectivesCompletedUnselected;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_FlavorText;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeDateTimeTextBlock> DateTimeText_TimeRemaining;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_CornerUL;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_IconUL;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeRewards> UserWidget_Rewards;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestID;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_StyleSize;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_PlayerLeftMatch;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeListEntryControls> Panel_ChallengeControls;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Expired Quest"))
	FText TextExpiredQuest;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Expired Quest Front End"))
	FText TextExpiredQuestFrontEnd;

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> DefaultPortraitDisplayAsset;

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> PinnedQuestIcon;

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowedClasses="/Script/Engine.MaterialInterface, /Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> SharedQuestIcon;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_DefaultWidgetsRoot;

	UPROPERTY(BlueprintReadOnly, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowPrivateAccess))
	EChallengeListEntryType EntryType;

	UPROPERTY(BlueprintReadOnly, Category="AthenaChallengeListEntry_NpcQuest", meta=(AllowPrivateAccess))
	bool bBangsOnUnseenSuppressed;

};

