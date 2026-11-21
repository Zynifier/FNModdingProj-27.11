// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "StoreSelectionScreen.generated.h"

class IPurchaseChoiceRequesterInterface;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonLoadGuard;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortMtxOfferData;
class UFortRealMoneyOffer;
class UTexture2D;

UENUM()
enum class EOptionalLabel : uint8
{
	Label_DS = 0,
	Label_NM = 1,
	Max = 2,
};

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemData")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, Category="ItemData")
	FText Name;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortStoreSelectionScreen : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortStoreSelectionScreen", meta=(AllowPrivateAccess))
	TObjectPtr<UCommonButtonGroupLegacy> EntryBoxButtonGroup;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRealMoneyOffer> StoreOffer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> StoreOfferLoadGuard;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStoreSelectionScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Options;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Continue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_InitiallySelectedHint;

	UPROPERTY(Transient)
	TScriptInterface<IPurchaseChoiceRequesterInterface> PurchaseChoiceOwner;

	UPROPERTY(Transient)
	TArray<FItemData> StoreOptions;

	UPROPERTY(Transient)
	TSoftObjectPtr<UFortMtxOfferData> SoftDisplayAsset;

	UPROPERTY(EditAnywhere, Category="FortStoreSelectionScreen", meta=(ArraySizeEnum="/Script/GameSubCatalog.EAppStore"))
	FItemData ItemData[12];

	UPROPERTY(EditAnywhere, Category="FortStoreSelectionScreen", meta=(ArraySizeEnum="/Script/StoreSelectionUI.EOptionalLabel"))
	FText OptionalLabels[2];

};

