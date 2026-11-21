// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Online/FortMcpTypes.h"
#include "Store/PurchaseChoiceRequestInterface.h"
#include "AthenaGiftingConfirmationScreen.generated.h"

class UAthenaGiftConfirmedPanel;
class UAthenaGiftingErrorsPanel;
class UAthenaGiftingPurchasePanel;
class UAthenaGiftingWrapOptionsPanel;
class UCommonButtonBase;
class UFortStoreFrontOfferInfo;
enum class EGiftingPresentationMode : uint8;

UENUM(BlueprintType)
enum class EGiftingPresentationMode : uint8
{
	ConfirmPurchase = 0,
	WrapOptions = 1,
	GiftingProcess = 2,
	GiftingError = 3,
	GiftConfirmed = 4,
	None = 5,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaGiftingConfirmationScreen : public UCommonActivatableWidget, public IPurchaseChoiceRequesterInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPresentationModeChanged(EGiftingPresentationMode NewMode);

private:
	UFUNCTION(BlueprintCallable)
	void Dismiss(const bool bGiftConfirmed = false);

	UFUNCTION()
	void HandleGiftSent(bool bSuccess, const TArray<FString>& IneligibleAccounts, const TArray<FString>& ErrorCodes);

	UFUNCTION()
	void HandleTokenOfferPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems);

	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> PresentedGiftableOfferInfo;

	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> PresentedOptionalTokenOfferInfo;

	UPROPERTY(EditAnywhere, Category="AthenaGiftingConfirmationScreen")
	float MinGiftSubmissionDelay;

	UPROPERTY(EditAnywhere, Category="AthenaGiftingConfirmationScreen")
	float MaxGiftSubmissionDelay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_WrapOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MtxWallet;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGiftingConfirmationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGiftingPurchasePanel> Panel_GiftingPurchase;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGiftingConfirmationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGiftingWrapOptionsPanel> Panel_WrapOptions;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGiftingConfirmationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGiftConfirmedPanel> Panel_GiftConfirmed;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGiftingConfirmationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGiftingErrorsPanel> Panel_GiftingErrors;

};

