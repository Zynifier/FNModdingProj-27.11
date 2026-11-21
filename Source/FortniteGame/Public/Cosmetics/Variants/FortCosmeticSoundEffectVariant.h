// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCosmeticSoundEffectVariant.generated.h"

USTRUCT()
struct FSoundEffectVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SoundEffectVariantDef")
	TArray<FSoundEffectVariant> SoundEffects;

};

UCLASS()
class UFortCosmeticSoundEffectVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetic Variant", meta=(TitleProperty="VariantName"))
	TArray<FSoundEffectVariantDef> SoundEffectOptions;

};

