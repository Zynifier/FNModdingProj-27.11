// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "SeasonPass/BattlePassRewardViewBase.h"
#include "BattlePassRewardPagedTrack.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UDynamicEntryBox;
class UFortBattlePassReward;
class UFortSwipePanel;

UCLASS(Abstract, MinimalAPI)
class UBattlePassRewardPagedTrack : public UBattlePassRewardViewBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPageChanged(bool bIsForward);

	UPROPERTY(EditAnywhere, Category="BattlePassRewardPagedTrack")
	float UpdateItemCardsDelay;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UCommonButtonLegacy>> Pips;

	UPROPERTY(Transient)
	int32 LastPageIndex;

	UPROPERTY(Transient)
	int32 PageIndex;

	UPROPERTY(Transient)
	int32 PagesHidden;

	UPROPERTY(Transient)
	int32 LocalFocusedIndex;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBattlePassReward> FocusReward;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBattlePassReward> DefaultFocusReward;

	UPROPERTY(Transient)
	TArray<FBattlePassPageData> PageData;

	UPROPERTY(Transient)
	FTimerHandle UpdateItemCardsHandle;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardPagedTrack", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Rewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardPagedTrack", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NextPage;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardPagedTrack", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PreviousPage;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardPagedTrack", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Pips;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardPagedTrack", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_PageNumbers;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_Pips;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardPagedTrack", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortSwipePanel> SwipePanel_ChangePage;

};

