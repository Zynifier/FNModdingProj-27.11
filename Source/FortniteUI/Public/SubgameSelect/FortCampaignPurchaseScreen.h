// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCampaignPurchaseScreen.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortMtxStoreRootBase_Legacy;
class UImage;
class UTexture2D;
class UWidgetAnimation;

UCLASS(Abstract, Config=Game, MinimalAPI, meta=(DisableNativeTick))
class UFortCampaignPurchaseScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnImageCycleTimeElapsed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStoreScreenCreated(UFortMtxStoreRootBase_Legacy* StoreScreen);

private:
	UPROPERTY(EditAnywhere, Category="FortCampaignPurchaseScreen")
	TArray<TObjectPtr<UTexture2D>> ImageCycle;

	UPROPERTY(EditAnywhere, Category="FortCampaignPurchaseScreen")
	float ImageCycleTime;

	UPROPERTY(Config)
	bool bAllowCodeRedemption;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCampaignPurchaseScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> BoundAnim_Intro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCampaignPurchaseScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> BoundAnim_Outro;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ProductLogo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Tagline;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Purchase;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_RedeemCode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCampaignPurchaseScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_UpsellImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> ActivatableSwitcher_PreviewOrStore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCampaignPurchaseScreen", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UFortMtxStoreRootBase_Legacy> StoreScreenClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMtxStoreRootBase_Legacy> StoreScreenInstance;

};

