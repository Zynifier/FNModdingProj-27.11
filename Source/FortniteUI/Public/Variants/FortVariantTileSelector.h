// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variants/FortVariantEditorWidgetBase.h"
#include "FortVariantTileSelector.generated.h"

class UCommonTextBlock;
class UCommonTileView;
class UVariantObject;

UCLASS(meta=(Category="Fortnite UI"))
class UFortVariantTileSelector : public UFortVariantEditorWidgetBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantTileSelector", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> TileView_VariantOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VariantName;

	UPROPERTY()
	TObjectPtr<UVariantObject> CurrentSelectedVariant;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantTileSelector")
	bool bHandleMouseButtonDownEvent;

};

