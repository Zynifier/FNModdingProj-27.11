// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Math/Color.h"
#include "Foundation/FortColorPickerConfiguration.h"
#include "FortColorPicker.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UFortColorPickerComponent;
class UFortColorPickerSwatchTile;
class UMaterialInterface;
class UUniformGridPanel;
enum class EColorPickerType : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortColorPicker : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnSwapColorPickerType(bool bToSwatch);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupColorPicker(EColorPickerType InColorPickerType);

private:
	UFUNCTION()
	void HandleSwatchColorSelected(UCommonButtonLegacy* AssociatedButton, int32 ButtonIndex);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UUniformGridPanel> GridPanel_Swatches;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	TSubclassOf<UFortColorPickerSwatchTile> SwatchTileClass;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_Swatches;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CustomColor;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortColorPickerSwatchTile> Swatch_CustomColor;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortColorPickerComponent> ColorComponent_Component1;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortColorPickerComponent> ColorComponent_Component2;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortColorPickerComponent> ColorComponent_Component3;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SaveColor;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortColorPickerSwatchTile> Swatch_CustomColorPreview;

	UPROPERTY()
	TArray<FLinearColor> Swatches;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	bool bNullOptionAvailable;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	bool bAutoSelectColorOnInitialize;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker", meta=(ArraySizeEnum="/Script/FortniteUI.EColorPickerColorRepresentation"))
	FLinearColor StartingCustomColor[2];

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	int32 SwatchRowCount;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	FLinearColor NullOptionColor;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	EColorPickerType ColorPickerType;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	bool bInitializeCustomColorFromSelectedSwatch;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	EColorPickerColorRepresentation CustomColorRepresentation;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	TObjectPtr<UMaterialInterface> HueMaterial;

	UPROPERTY(EditAnywhere, Category="FortColorPicker")
	FName HueMaterialParam;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	TObjectPtr<UMaterialInterface> SaturationMaterial;

	UPROPERTY(EditAnywhere, Category="FortColorPicker")
	FName SaturationMaterialParam;

	UPROPERTY(EditDefaultsOnly, Category="FortColorPicker")
	TObjectPtr<UMaterialInterface> ValueMaterial;

	UPROPERTY(EditAnywhere, Category="FortColorPicker")
	FName ValueMaterialParam;

	UPROPERTY(Transient)
	FLinearColor CurrentColor;

};

