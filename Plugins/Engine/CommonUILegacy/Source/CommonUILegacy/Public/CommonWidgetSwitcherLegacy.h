// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonAnimatedSwitcher.h"
#include "CommonWidgetSwitcherLegacy.generated.h"

class UCommonActivatablePanelLegacy;
class UWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveWidgetChanged, UWidget*, ActiveWidget, int32, ActiveWidgetIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveWidgetDeactivated, UCommonActivatablePanelLegacy*, DeactivatedWidget);

/** 
 * A widget switcher with a few extra bells a whistles.
 * - Automatically activates and deactivates any contained UCommonActivatableWidgets
 * - Has built-in transition animations for switching between active indices
 */
UCLASS()
class COMMONUILEGACY_API UCommonWidgetSwitcherLegacy : public UCommonAnimatedSwitcher
{
	GENERATED_BODY()

public:
	UCommonWidgetSwitcherLegacy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	/**
	 *	Helper to activate an Activatable Panel if it is the active
	 *	widget on the widget switcher 
	 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	virtual void ActivateWidget();

	/**
	 *	Helper to deactivate an Activatable Panel if it is the active
	 *	widget on the widget switcher
	 */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	virtual void DeactivateWidget();

	/** Activates the widget and makes it the active index. */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	void SetActiveWidget_Advanced(UWidget* Widget, const bool AttemptActivationChange);

	/** Activates the widget and makes it the active index. */
	UFUNCTION(BlueprintCallable, Category="Common Widget Switcher")
	void SetActiveWidgetIndex_Advanced(const int32 Index, const bool AttemptActivationChange);

	/** Fires when the currently active widget is deactivated */
	UPROPERTY(BlueprintAssignable, Category="Common Widget Switcher")
	FOnActiveWidgetDeactivated OnActiveWidgetDeactivated;

	/** Fires when the active widget is changed */
	UPROPERTY(BlueprintAssignable, Category="Common Widget Switcher")
	FOnActiveWidgetChanged OnActiveWidgetChanged;

private:
	UFUNCTION()
	void HandleActiveWidgetDeactivated(UCommonActivatablePanelLegacy* DeactivatedPanel);

	UPROPERTY(EditAnywhere, Category="Common Widget Switcher")
	bool bWidgetActivationEnabled;

	UPROPERTY(EditAnywhere, Category="Common Widget Switcher")
	bool bOutroPanelBelow;

};

