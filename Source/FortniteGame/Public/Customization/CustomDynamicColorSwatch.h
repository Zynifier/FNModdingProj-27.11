// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Customization/CustomCharacterPart.h"
#include "Customization/CustomColorSwatch.h"
#include "CustomDynamicColorSwatch.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FColorSwatchPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ColorSwatch")
	FName ColorName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ColorSwatch")
	FLinearColor ColorValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ColorSwatch")
	FText ColorDisplayName;

};

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UCustomDynamicColorSwatch : public UCustomColorSwatch
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ColorSwatch")
	TArray<FColorSwatchPair> ColorPairs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ColorSwatch")
	TArray<FCustomPartTextureParameter> TextureParameters;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ColorSwatch")
	TMap<FName, TSoftObjectPtr<UTexture2D>> SpecificIconography;

};

