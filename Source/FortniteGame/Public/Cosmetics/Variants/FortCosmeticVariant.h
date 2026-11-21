// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortCosmeticVariant.generated.h"

class UMaterialInterface;

UCLASS(Abstract, EditInlineNew, MinimalAPI)
class UFortCosmeticVariant : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API FGameplayTagContainer GetAllVariantTags() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API virtual FText GetVariantChannelText() const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API virtual FText GetVariantText(FGameplayTag InVariantTag) const;

	UFUNCTION(BlueprintPure, Category="Cosmetics")
	FORTNITEGAME_API virtual FText GetVariantUnlockRequirement(FGameplayTag InVariantTag) const;

protected:
	UPROPERTY(EditAnywhere, Category="Display Data")
	TSoftObjectPtr<UMaterialInterface> CustomPreviewTileMaterial;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant", meta=(Categories="Cosmetics.Variant.Channel"))
	FGameplayTag VariantChannelTag;

	UPROPERTY(EditAnywhere, Category="Display Data")
	FText VariantChannelName;

	UPROPERTY(Transient)
	FGameplayTag ActiveVariantTag;

};

UCLASS(Abstract, MinimalAPI)
class UFortCosmeticVariantBackedByArray : public UFortCosmeticVariant
{
	GENERATED_BODY()

};

