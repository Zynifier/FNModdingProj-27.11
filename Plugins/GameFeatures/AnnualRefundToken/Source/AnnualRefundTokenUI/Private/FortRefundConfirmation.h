// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortRefundConfirmation.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;
class UFortAnnualRefundTicket;
class UFortItemDefinition;
enum class EFortPurchaseHistoryRefundType : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortRefundConfirmation : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Update Items List"))
	void BP_UpdateItemsList(const TArray<UFortItemDefinition*>& SelectedItemDefs, const int32 TotalMtxPaid);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Update Refund Type"))
	void BP_UpdateRefundType(const EFortPurchaseHistoryRefundType RefundType, const bool bBundledRefund);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RefundsRemaining;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RefundCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AreYouSure;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRefundConfirmation", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Yes;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRefundConfirmation", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_No;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAnnualRefundTicket> RefundTicket_Left;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAnnualRefundTicket> RefundTicket_Center;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAnnualRefundTicket> RefundTicket_Right;

};

