// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Frontend/Spatial/SpatialNavigationButton.h"
#include "SpatialCustomizationCategoryEntry.generated.h"

class UAthenaSpatialCustomizationChoice;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortTokenType;
enum class ESpatialCustomizationCategoryState : uint8;

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable)
class UAthenaSpatialCustomizationCategoryEntry : public UAthenaSpatialNavigationButton
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCategoryStateSet(ESpatialCustomizationCategoryState State, FLinearColor StateColor);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationCategoryEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialCustomizationChoice> Choice_SelectedChoice;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationCategoryEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_EntryName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationCategoryEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_EntryName_Big;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationCategoryEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_StateDescription;

	UPROPERTY(EditInstanceOnly, Category="AthenaSpatialCustomizationCategoryEntry")
	TObjectPtr<UFortTokenType> CategoryKey;

	UPROPERTY(EditInstanceOnly, Category="AthenaSpatialCustomizationCategoryEntry")
	bool bUseColorPicker;

	UPROPERTY(EditInstanceOnly, Category="AthenaSpatialCustomizationCategoryEntry")
	bool bCategoryDefaultColorIsNull;

	UPROPERTY(EditInstanceOnly, Category="AthenaSpatialCustomizationCategoryEntry", meta=(EditCondition="bUseColorPicker"))
	float LowerClampingColorBound;

};

