// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Subscriptions/SubscriptionContentInterface.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortProgressiveContentContainer.generated.h"

class UCommonActivatableWidgetSwitcher;
class UFortProgressiveItemScreen;
class UFortProgressiveTableOfContentsScreen;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortProgressiveContentContainer : public UCommonActivatableWidget, public IFortSubscriptionContentInterface, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_PrimaryContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressiveTableOfContentsScreen> Widget_ProgressiveTableOfContentsScreen;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressiveItemScreen> Widget_ProgressiveItemScreen;

};

