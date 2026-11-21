// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Fonts/SlateFontInfo.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"
#include "FortBrushSize.h"
#include "FortMultiSize.generated.h"

USTRUCT(BlueprintType)
struct FFortMultiSizeBrush
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateBrush Brush_XXS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateBrush Brush_XS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateBrush Brush_S;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateBrush Brush_M;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateBrush Brush_L;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateBrush Brush_XL;

};

USTRUCT(BlueprintType)
struct FFortMultiSizeFont
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateFontInfo Font_XXS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateFontInfo Font_XS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateFontInfo Font_S;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateFontInfo Font_M;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateFontInfo Font_L;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FSlateFontInfo Font_XL;

};

USTRUCT(BlueprintType)
struct FFortMultiSizeMargin
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FMargin Margin_XXS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FMargin Margin_XS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FMargin Margin_S;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FMargin Margin_M;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FMargin Margin_L;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemCategory")
	FMargin Margin_XL;

};

UCLASS()
class UFortBrushSizeFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Brush Size")
	static EFortBrushSize::Type GrowBrushSize(const EFortBrushSize::Type OriginalBrushSize, const int32 Steps = 1);

	UFUNCTION(BlueprintPure, Category="Brush Size")
	static EFortBrushSize::Type ShrinkBrushSize(const EFortBrushSize::Type OriginalBrushSize, const int32 Steps = 1);

};

UCLASS(MinimalAPI, BlueprintType)
class UFortMultiSizeBrushAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMultiSizeBrushAsset", meta=(ShowOnlyInnerProperties))
	FFortMultiSizeBrush Brush;

};

