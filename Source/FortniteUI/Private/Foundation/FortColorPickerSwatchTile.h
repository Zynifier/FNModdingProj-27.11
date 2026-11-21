// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "CommonButtonLegacy.h"
#include "FortColorPickerSwatchTile.generated.h"

class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortColorPickerSwatchTile : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSwatchColorSet(bool bInNullColor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSwatchLockedStateChanged(bool bSwatchLocked);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortColorPickerSwatchTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Color;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Locked;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_Selected;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPickerSwatchTile")
	FName ImageColorParam;

	UPROPERTY()
	FLinearColor SwatchColor;

};

