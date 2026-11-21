// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variants/FortVariantSelector.h"
#include "Variants/FortVariantTileButton.h"
#include "FortVariantRichColorPicker.generated.h"

class UAthenaCosmeticItemDefinition;
class UCustomColorSwatch;
class UFortCosmeticRichColorVariant;

UCLASS()
class UFortRichColorVariantListObject : public UVariantObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText ColorName;

};

UCLASS()
class UFortVariantRichColorPicker : public UFortVariantSelector
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortCosmeticRichColorVariant> CachedCosmeticVariant;

	UPROPERTY()
	TObjectPtr<UAthenaCosmeticItemDefinition> ItemDef;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UCustomColorSwatch>> ColorSwatches;

};

