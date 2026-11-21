// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/CommonBoundActionButtonInterface.h"
#include "UIKit/Buttons/UIKitModularButton.h"
#include "FortCTAButton.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UFortCTAButton : public UUIKitModularButton, public ICommonBoundActionButtonInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Common Button|Getters")
	float GetRequiredHoldTime() const;

	UFUNCTION(BlueprintPure, Category="Common Button|Getters")
	bool GetRequiresHold() const;

	UFUNCTION(BlueprintCallable)
	void SetAutoUpdateFromInputAction(bool bInAutoUpdateFromInputAction);

	UFUNCTION(BlueprintCallable, Category="Common Button|Setters")
	void SetRequiresHold(bool bInRequiresHold);

	UFUNCTION(BlueprintCallable)
	void SetSecondaryText(const FText& ButtonSecondaryText);

	UFUNCTION(BlueprintCallable)
	void SetText(const FText& ButtonText);

	UFUNCTION(BlueprintCallable)
	void SetUseNaturalNavigation(bool bInUseNaturalNavigation);

	virtual void SetRepresentedAction(FUIActionBindingHandle InBindingHandle) override;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnInputActionUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetSecondaryText(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetText(const FText& Text);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCTAButton")
	bool bAutoUpdateFromInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCTAButton")
	bool bUseNaturalNavigation;

};

