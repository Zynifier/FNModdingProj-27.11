// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "CommonButtonLegacy.h"
#include "SpatialCustomizationChoiceButton.generated.h"

class UAthenaSpatialCustomizationChoice;
class UFortLazyImage;
class UObject;
enum class ESpatialCustomizationCategoryState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpatialCustomizationChoiceButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupChoice(ESpatialCustomizationCategoryState CategoryState, const FLinearColor& CategoryStateColor);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationChoiceButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialCustomizationChoice> Choice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_Selected;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationChoiceButton", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.Material,/Script/Engine.MaterialInstance"))
	TSoftObjectPtr<UObject> SelectedImage;

};

