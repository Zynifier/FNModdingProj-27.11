// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "BattlePassSubPageInterface.h"
#include "FortBattlePassBulkBuyPageBase.generated.h"

class UAthenaSeasonItemData_BattleStar;
class UAthenaSeasonItemDefinition;
class UCommonButtonBase;
class UCommonVisibilitySwitcher;
class UDynamicEntryBox;
class UFortBattlePassTile;
class UFortCTAButton;
class UScrollBox;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassBulkBuyPageBase : public UCommonActivatableWidget, public IBattlePassSubPageInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCostChanged(const int32 Cost);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPageRangeChanged(const int32 FromPage, const int32 ToPage);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRewardCountChanged(const int32 Count);

protected:
	UFUNCTION()
	void HandleUserScrolled(float ScrollAmount);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassBulkBuyPageBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Addition;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassBulkBuyPageBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Subtraction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassBulkBuyPageBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_TilesEntries;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassBulkBuyPageBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_BottomButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassBulkBuyPageBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_BuyLevels;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassBulkBuyPageBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_ClaimReward;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassBulkBuyPageBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> Widget_LevelUpMessagePremium;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaSeasonItemData_BattleStar> SeasonData_BattleStar;

private:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaSeasonItemDefinition> SeasonItemDefinition;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBattlePassTile> FocusedReward;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Pages;

};

