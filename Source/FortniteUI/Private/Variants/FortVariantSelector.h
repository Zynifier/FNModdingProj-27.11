// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variants/FortVariantEditorWidgetBase.h"
#include "FortVariantSelector.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UVariantObject;

UCLASS(meta=(Category="Fortnite UI"))
class UFortVariantSelector : public UFortVariantEditorWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleItemHovered(UCommonButtonLegacy* AssociatedButton, int32 ButtonIndex);

	UFUNCTION()
	void HandleItemSelected(UCommonButtonLegacy* AssociatedButton, int32 ButtonIndex);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_VariantOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VariantName;

	UPROPERTY()
	TObjectPtr<UVariantObject> CurrentSelectedVariant;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupLegacy> Tile_ButtonGroup;

};

