// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortConversationScreen.h"
#include "MobileConversationScreen.generated.h"

class UButton;
class UCommonButtonBase;
class UCommonVisibilitySwitcher;

UCLASS(Abstract, meta=(DisableNativeTick))
class UMobileConversationScreen : public UFortConversationScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnHandleConfirmClicked();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="MobileConversationScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UButton> MobileButtonConfirm;

	UPROPERTY(BlueprintReadOnly, Export, Category="MobileConversationScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UButton> MobileButtonTouchInformation;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> MobileCloseButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_CenteredDetails;

};

