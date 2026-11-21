// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortPurchaseHistoryScreen.generated.h"

class UCommonActivatableWidget;
class UCommonAnimatedSwitcher;
class UCommonButtonBase;
class UCommonTextBlock;
class UFortAnnualRefundTicket;
class UFortPurchaseHistoryTreeView;
class UFortRefundConfirmation;
class UScrollBox;
class UWidget;

UENUM(BlueprintType)
enum class EFortPurchaseHistoryRefundType : uint8
{
	CancelPurchase = 0,
	ReturnTicket = 1,
	TokenlessRefund = 2,
	NonRefundable = 3,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPurchaseHistoryScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Is Showing Purchases"))
	bool BP_IsShowingPurchases();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginRefundSubmission();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndRefundSubmission();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNoPurchasesAvailable();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateView();

	UPROPERTY(EditDefaultsOnly, Category="FortPurchaseHistoryScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackAction;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortPurchaseHistoryScreen")
	TSoftClassPtr<UFortRefundConfirmation> RefundConfirmationClass;

	UPROPERTY(EditDefaultsOnly, Category="FortPurchaseHistoryScreen")
	TSoftClassPtr<UCommonActivatableWidget> DirectPurchaseInfoModalClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPurchaseHistoryScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	UCommonAnimatedSwitcher* Switcher_MainContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPurchaseHistoryTreeView> TreeView_Purchases;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PostApproval;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_ReturnTypeInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Desc;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RefundCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ResultHeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ResultTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ResultDesc;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAnnualRefundTicket> RefundTicket_Left;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAnnualRefundTicket> RefundTicket_Center;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAnnualRefundTicket> RefundTicket_Right;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_CancelPurchaseInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_ReturnTicketInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_TokenlessRefundInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_NonRefundableInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_BundledPurchaseInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_BundledPurchaseTokenlessRefundInfo;

};

