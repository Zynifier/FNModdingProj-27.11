// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "RebootRallyQRModalWidget.generated.h"

class UCommonButtonBase;
class UFortPopupModal;
class URebootRallyQRCode;

UCLASS(meta=(DisableNativeTick))
class URebootRallyQRModalWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRebootRallyEligibilityUpdated(bool bEligible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetIsInvite(bool bIsInvited);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UFortPopupModal* WBP_PopupModal;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* BackgroundCloseButton;

	UPROPERTY(Export, meta=(BindWIdget, EditInline="true"))
	TObjectPtr<URebootRallyQRCode> WBP_RebootRallyPopupModal_QRCode;

};

