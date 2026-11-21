// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "Athena/ItemShop/ReloadMtx/AthenaReloadMtxScreenBaseLegacy.h"
#include "AthenaDynamicReloadMtxScreenLegacy.generated.h"

class UAthenaDynamicMtxOfferButtonLegacy;
class UAthenaReloadMtxScreenLegacy;
class UAthenaStarterKitOfferButtonLegacy;
class UAthenaStaticMtxOfferButtonLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UOverlay;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaDynamicReloadMtxScreenLegacy : public UAthenaReloadMtxScreenBaseLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UWidget* GetMtxRequiredButtonToFocus(EUINavigation InNavigation = EUINavigation::Invalid) const;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TotalNeeded;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CurrentBalance;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_DynamicOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaStarterKitOfferButtonLegacy> Button_StarterKitOption;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_MtxRequired;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_StarterKit;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaDynamicMtxOfferButtonLegacy> Button_MtxRequiredOption;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaStaticMtxOfferButtonLegacy> Button_MtxOtherOption;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_MoreOptions;

	UPROPERTY(EditAnywhere, Category="AthenaDynamicReloadMtxScreenLegacy")
	TArray<FName> StorefrontNames;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaReloadMtxScreenLegacy> StaticReloadMtxScreen;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> MtxRequiredButtonToFocus;

};

