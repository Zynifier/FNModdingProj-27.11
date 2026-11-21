// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortEventModalBase.h"
#include "Online/FortMcpTypes.h"
#include "FortEventPurchasePremiumTrackModal.generated.h"

class UCommonButtonBase;
class UDynamicEntryBox;
class UFortCTAButton;
class UFortEventScreenData;
class UScrollBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventPurchasePremiumTrackModal : public UFortEventModalBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	const UFortEventScreenData* GetEventScreenData() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCMSTextApplied(const FText& HeaderText, const FText& LegalText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEventScreenDataSet(const UFortEventScreenData* InEventScreenData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPriceSet(const int32 Price);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchasePremiumTrackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Body;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchasePremiumTrackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Body;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchasePremiumTrackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_Purchase;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchasePremiumTrackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GetVBucks;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchasePremiumTrackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchasePremiumTrackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseMobile;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventPurchasePremiumTrackModal", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PreviewReward;

	UPROPERTY(BlueprintReadOnly, Category="FortEventPurchasePremiumTrackModal")
	int32 CurrentVBucks;

private:
	UFUNCTION()
	void HandlePurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& InOfferId);

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPurchasePremiumTrackBody : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortPurchasePremiumTrackBody(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulate(const int32 BodyIndex, const FText& BodyText);

};

