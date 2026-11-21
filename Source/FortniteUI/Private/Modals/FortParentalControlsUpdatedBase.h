// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortParentalControlsUpdatedBase.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortParentalControlsUpdatedBase : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	virtual void ExitModal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBackout();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* Button_CloseTouch;

};

