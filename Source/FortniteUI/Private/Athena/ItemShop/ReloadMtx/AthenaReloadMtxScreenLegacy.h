// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "Athena/ItemShop/ReloadMtx/AthenaReloadMtxScreenBaseLegacy.h"
#include "AthenaReloadMtxScreenLegacy.generated.h"

class UAthenaStarterKitOfferButtonLegacy;
class UCommonListView;
class UCommonVisibilitySwitcher;
class UOverlay;
class UWidget;

UCLASS(Abstract)
class UAthenaReloadMtxScreenLegacy : public UAthenaReloadMtxScreenBaseLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UWidget* GetWidgetToFocusFromOfferList(EUINavigation InNavigation = EUINavigation::Invalid) const;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaStarterKitOfferButtonLegacy> Button_StarterKitOption;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_MtxOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_AvailableOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_AvailableOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_NoOptions;

};

