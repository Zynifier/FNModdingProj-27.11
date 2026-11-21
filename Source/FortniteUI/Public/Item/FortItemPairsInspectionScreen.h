// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "FortItemQuantityPair.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "UIManager/AthenaFrontendFlowInterruptInterface.h"
#include "FortItemPairsInspectionScreen.generated.h"

class UAthenaCosmeticUnlockingInfo;
class UCommonActivatableWidgetSwitcher;
class UCommonButtonBase;
class UFortItemBaseWidget;
class UFortItemDefinition;
class UFortItemListPreviewWidget;
class UFortStoreSkinDetailsPopup;
class UFortVariantListPreviewWidget;
class UWidget;
enum class EPresentationMode : uint8;

UENUM(BlueprintType)
enum class EPresentationMode : uint8
{
	ItemList = 0,
	VariantList = 1,
};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortItemPairsInspectionScreen : public UFortItemPreviewScreen, public IAthenaFrontendFlowInterruptInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BlockScreenContent(const bool bBlockScreen, const FText& ContentBlockedText);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnInputTypeChanged(ECommonInputType InputType);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnItemsSet(const TArray<FFortItemQuantityPair>& ItemQuantityPairs);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_UpdatePresentationMode(EPresentationMode NewMode);

	UFUNCTION(BlueprintPure)
	UFortItemBaseWidget* GetItemInfoHeader() const;

	UFUNCTION(BlueprintImplementableEvent)
	void PlayIntroAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void SetupInfoHeader(bool bShouldShowCard);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortItemPairsInspectionScreen", meta=(EditInline="true"))
	TObjectPtr<UWidget> ContentPurchasedFocusWidget;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortItemPairsInspectionScreen")
	float DefaultVariantCyclingDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortItemPairsInspectionScreen")
	float TimeBetweenVariants;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> PresentedItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="FortItemPairsInspectionScreen", meta=(AllowPrivateAccess="TRUE"))
	EPresentationMode PresentationMode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchBack;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_PresentationMode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemListPreviewWidget> Widget_ItemList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVariantListPreviewWidget> Widget_VariantList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemBaseWidget> Widget_ItemInfoHeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortStoreSkinDetailsPopup> ItemPopup_Details;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaCosmeticUnlockingInfo> UnlockingInfo;

};

