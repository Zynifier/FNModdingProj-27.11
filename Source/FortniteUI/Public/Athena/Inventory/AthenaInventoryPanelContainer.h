// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "AthenaInventoryPanelContainer.generated.h"

class UCommonButtonBase;
class UCommonWidgetSwitcherLegacy;
class UFortTabListWidgetBase_Legacy;
class UWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaInventoryPanelContainer : public UCommonActivatableWidget, public IFortTabInterface
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleInventoryTabChanged(UWidget* NewActiveWidget, int32 WidgetIndex);

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FName TabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryPanelContainer")
	TSubclassOf<UCommonButtonBase> TabButtonClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryPanelContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> TabList;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryPanelContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_Tabs;

};

