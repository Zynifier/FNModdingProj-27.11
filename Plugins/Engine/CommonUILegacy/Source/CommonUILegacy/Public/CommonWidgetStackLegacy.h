// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonVisibilitySwitcher.h"
#include "CommonWidgetStackLegacy.generated.h"

class UWidget;

/** A widget stack, only shows the top widget - Automatically activates and deactivates UCommonActivatableWidgets */
UCLASS(Config=CommonUI, DefaultConfig)
class COMMONUILEGACY_API UCommonWidgetStackLegacy : public UCommonVisibilitySwitcher
{
	GENERATED_BODY()

public:
//This is to maintain blueprint functionality for UCommonWidgetStackLegacy in StW. Do not use.

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveWidgetChangedLegacy, UWidget*, InActiveWidget, int32, InActiveWidgetIndex);

public:
	/** Pop a widget off of the stack. */
	UFUNCTION(BlueprintCallable, Category="Common Widget Stack")
	UWidget* PopWidget();

	/** Push a new widget onto the stack. */
	UFUNCTION(BlueprintCallable, Category="Common Widget Stack")
	void PushWidget(UWidget* InWidget);

protected:
	/** Legacy StW Blueprint support. Do not use. */
	UFUNCTION(BlueprintCallable, Category="Common Widget Stack")
	void ActivateWidget();

	UFUNCTION(BlueprintCallable, Category="Common Widget Stack")
	void DeactivateWidget();

	UPROPERTY(BlueprintAssignable, Category="Legacy")
	FOnActiveWidgetChangedLegacy OnActiveWidgetChangedLegacyEvent;

};

