// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortBattlePassReward.generated.h"

class UCommonTextBlock;
class UFortItemDefinition;
class UFortLazyImage;
class UImage;
class UOverlay;
class UTexture2D;
class UWidgetSwitcher;

UCLASS(Abstract)
class UFortBattlePassReward : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void InitForReward(const UFortItemDefinition* RewardItem);

	UFUNCTION(BlueprintImplementableEvent)
	void SetLargeRewardVisuals();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateVisualsToCompletedState();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnOverrideIcon(const TSoftObjectPtr<UTexture2D>& IconOverride);

	UFUNCTION(BlueprintImplementableEvent)
	void ResetToDefault();

private:
	UPROPERTY(EditAnywhere, Category="FortBattlePassReward")
	FName ImageParamName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_RewardIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_RewardLockedTint;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ChaseRewardSpacer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_SelectionBorder;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_EarnedRewardState;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_RewardTrackType;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_TrackNumber;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_NewTechInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FreeLevelNumber;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PaidLevelNumber;

};

