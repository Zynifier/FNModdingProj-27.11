// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Types/SlateEnums.h"
#include "BattlePassRewardPageBase.h"
#include "Items/ItemPreviewTypes.h"
#include "SeasonPass/BattlePassTypes.h"
#include "BattlePassRewardPageS27.generated.h"

class UAthenaSeasonItemData_BattleStar;
class UBattlePassBulkBuyInputData;
class UCommonAnimatedSwitcher;
class UCommonButtonBase;
class UFortBattlePassRewardTrack;
class UFortBattlePassTile;
class UFortBattlePassTutorialTooltipS27;
class UWidget;
enum class ERewardPageType : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassRewardPageS27 : public UBattlePassRewardPageBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Reward Page")
	FVaultWorldBackgroundData GetRewardPageBackgroundData() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitForPageType(const ERewardPageType InRewardPageType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPageChanged(const int32 PageNumber, const int32 RewardPageTotal);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInputMethodChanged(const ECommonInputType InputType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadingScreenSelectedChanged(bool bIsSelected);

	UPROPERTY(EditDefaultsOnly, Category="Tutorial")
	int32 HoldTileTooltip_ClaimedRewardsToHide;

	UPROPERTY(EditDefaultsOnly, Category="Tutorial")
	int32 HoldTileTooltip_ClaimedBattlePassToHide;

	UPROPERTY(EditDefaultsOnly, Category="Tutorial")
	int32 HoldTileTooltip_RequiredBattleStarsToShow;

	UPROPERTY(EditDefaultsOnly, Category="Tutorial")
	int32 LevelRequirementUnlockTooltip_RequiredLevel;

	UPROPERTY(EditDefaultsOnly, Category="Tutorial")
	int32 ClaimAllRewardsTooltip_RequiredLevelToShow;

private:
	UFUNCTION()
	UWidget* HandleRewardTracksBoundaryNavigation(EUINavigation InNavigation);

	UPROPERTY(EditDefaultsOnly, Category="BattlePassRewardPageS27")
	TSubclassOf<UFortBattlePassRewardTrack> RewardsTrackClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBattlePassTile> FocusedReward;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortBattlePassRewardTrack>> TrackPages;

	UPROPERTY(EditInstanceOnly, Category="Reward View")
	ERewardPageType RewardPageType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_RewardTracks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBattlePassTutorialTooltipS27> TutorialTooltip_LevelRequirementUnlock;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBattlePassTutorialTooltipS27> TutorialTooltip_ClaimAllRewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassRewardPageS27", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortBattlePassTutorialTooltipS27> TutorialTooltip_HoldTile;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaSeasonItemData_BattleStar> SeasonData_BattleStar;

	UPROPERTY(Transient)
	TObjectPtr<UBattlePassBulkBuyInputData> BulkBuyInputData;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_NextPage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PreviousPage;

};

