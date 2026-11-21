// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Online/FortMcpTypes.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortBattlePassPurchaseResourcesWidget.generated.h"

class UAthenaSeasonItemData_BattleStar;
class UCommonButtonBase;
class UCommonVisibilitySwitcher;
class UFortBattlePassCheckBoxButton;
class UFortHoldableButton;
class UFortItemDefinition;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassPurchaseResourcesWidget : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Experiment")
	bool IsReloadMtxEnabled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnAmountChangeButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOfferUnavailable();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPurchaseAmountChanged(const int32 NewAmount, const int32 LevelsLeft);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTotalPriceChanged(const int32 NewPrice);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatePageUnlockText(const FText& PageUnlockText);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortBattlePassPurchaseResourcesWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Addition;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortBattlePassPurchaseResourcesWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BatchAddition;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortBattlePassPurchaseResourcesWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Subtraction;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortBattlePassPurchaseResourcesWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BatchSubtraction;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortBattlePassPurchaseResourcesWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_PurchaseButtons;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortHoldableButton> Button_Purchase;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GetVBucks;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ReloadMtx;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortBattlePassCheckBoxButton> CheckBox_Bundle;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassPurchaseResourcesWidget")
	int32 CurrentLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassPurchaseResourcesWidget")
	bool bIsOfferActive;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassPurchaseResourcesWidget")
	int32 CurrentVBucks;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassPurchaseResourcesWidget")
	int32 CurrentBattleStars;

	UPROPERTY(EditAnywhere, Category="FortBattlePassPurchaseResourcesWidget")
	int32 BatchNum;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassPurchaseResourcesWidget")
	bool bOfferUnavailable;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassPurchaseResourcesWidget")
	int32 MaxBundleLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassPurchaseResourcesWidget")
	int32 MaxLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassPurchaseResourcesWidget")
	int32 MaxLevelPurchases;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassPurchaseResourcesWidget")
	int32 BundleAmount;

private:
	UFUNCTION()
	void HandlePurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UFUNCTION()
	void HandlePurchaseMultiComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const TArray<FString>& OfferIdList);

	UPROPERTY(EditAnywhere, Category="FortBattlePassPurchaseResourcesWidget", meta=(AllowPrivateAccess))
	TObjectPtr<UFortItemDefinition> LevelPreviewItem;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaSeasonItemData_BattleStar> BattleStarData;

};

