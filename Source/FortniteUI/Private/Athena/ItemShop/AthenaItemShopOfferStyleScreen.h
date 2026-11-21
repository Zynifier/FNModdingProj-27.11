// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "Athena/ItemShop/AthenaItemShopOfferDetailsWidgetBase.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "AthenaItemShopOfferStyleScreen.generated.h"

class UAthenaCosmeticUnlockingInfo;
class UCommonButtonBase;
class UCommonTextBlock;
class UFortItemDefinition;
class UFortItemPreviewScreen;
class UFortVariantPicker;
class ULockerConfirmationModal;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaItemShopOfferStyleScreen : public UAthenaItemShopOfferDetailsWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanEquipItem() const;

	UFUNCTION(BlueprintCallable)
	void Dismiss();

	UFUNCTION(BlueprintCallable)
	void EquipItem();

	UFUNCTION(BlueprintPure)
	bool IsItemEquipped() const;

	UFUNCTION(BlueprintCallable)
	void SetTriggeringItemDefinition(const UFortItemDefinition* TriggeringItemDef);

protected:
	UFUNCTION()
	void HandleInputMethodChanged(ECommonInputType InputType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemEquipped(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewUpdated();

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopOfferStyleScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackAction;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferStyleScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortItemPreviewScreen> ItemPreview_Widget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferStyleScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StyleDisclaimer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferStyleScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortVariantPicker> Picker_VariantSelector;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferStyleScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Previous;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferStyleScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Next;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferStyleScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferStyleScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaCosmeticUnlockingInfo> Info_LockedNotification;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> TriggeringItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopOfferStyleScreen")
	TSoftClassPtr<ULockerConfirmationModal> LockerConfirmationModalClass;

	UPROPERTY(Config)
	bool bVariantZoomUsesSnap;

	UPROPERTY()
	FDisplayManagerVariantData VariantData;

	UPROPERTY(BlueprintReadOnly, Category="AthenaItemShopOfferStyleScreen", meta=(AllowPrivateAccess))
	TArray<int32> OfferIndicesWithVariants;

};

