// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "UObject/NoExportTypes.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "Items/AthenaSeasonItemDefinitionTypes.h"
#include "BattlePassViewAllRewardsScreen.generated.h"

class UBattlePassViewRewardData;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortItem;
class UFortItemDefinition;
class UTileView;

UCLASS()
class UBattlePassViewAllRewardsScreen : public UFortItemPreviewScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemViewed(const UBattlePassViewRewardData* ItemDisplayed);

	UPROPERTY(Transient)
	TObjectPtr<UFortItem> LastViewedItem;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UBattlePassViewRewardData>> AllRewardItems;

	UPROPERTY(EditDefaultsOnly, Category="BattlePassViewAllRewardsScreen")
	float StaggerTime;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SortLabel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChapterLabel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SeasonLabel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CycleSort;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTileView> TileView_Rewards;

};

UCLASS(BlueprintType)
class UBattlePassViewRewardData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="BattlePassViewRewardData")
	TObjectPtr<UFortItem> Reward;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassViewRewardData")
	bool bIsFreeItem;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassViewRewardData")
	bool bIsOwned;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassViewRewardData")
	EBattlePassRewardSource UnlockableSource;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassViewRewardData")
	TObjectPtr<UFortItemDefinition> UnlockableSourceItemDef;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassViewRewardData")
	int32 ItemLevel;

};

UCLASS(meta=(DisableNativeTick))
class UBattlePassViewRewardListEntry : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BPSetup(UBattlePassViewRewardData* InReward);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStaggerTimeElapsed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStaggerTimeStarted();

	UPROPERTY(Transient)
	TObjectPtr<UBattlePassViewRewardData> Reward;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TierLevel;

};

