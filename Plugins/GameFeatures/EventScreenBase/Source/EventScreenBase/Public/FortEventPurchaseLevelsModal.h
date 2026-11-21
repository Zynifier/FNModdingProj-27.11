// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEventModalBase.h"
#include "Online/FortMcpTypes.h"
#include "FortEventPurchaseLevelsModal.generated.h"

class UCommonButtonBase;
class UEventScreenListView;
class UFortEventScreenData;

UCLASS(Abstract)
class UFortEventPurchaseLevelsModal : public UFortEventModalBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	const UFortEventScreenData* GetEventScreenData() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAmountChangeButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCMSTextApplied(const FText& LegalText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEventScreenDataSet(const UFortEventScreenData* InEventScreenData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPurchaseAmountChanged(const int32 TotalPrice, const int32 LevelQuantity, const int32 PurchaseQuantity, const int32 ResourceQuantity);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchaseLevelsModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Addition;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchaseLevelsModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Subtraction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchaseLevelsModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Purchase;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchaseLevelsModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GetVBucks;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchaseLevelsModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchaseLevelsModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseMobile;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchaseLevelsModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEventScreenListView> ListView_RewardPreview;

	UPROPERTY(BlueprintReadOnly, Category="FortEventPurchaseLevelsModal")
	int32 CurrentResourceValue;

	UPROPERTY(BlueprintReadOnly, Category="FortEventPurchaseLevelsModal")
	int32 MaxResourceValue;

	UPROPERTY(BlueprintReadOnly, Category="FortEventPurchaseLevelsModal")
	int32 CurrentVBucks;

	UPROPERTY(BlueprintReadOnly, Category="FortEventPurchaseLevelsModal")
	int32 OfferResourceQuantity;

	UPROPERTY(EditDefaultsOnly, Category="FortEventPurchaseLevelsModal")
	bool bAnimateListViewFromEmpty;

private:
	UFUNCTION()
	void HandlePurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& InOfferId);

};

