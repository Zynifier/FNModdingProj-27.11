// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "UObject/PrimaryAssetId.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCustomizableObjectSprayVariant.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FCustomizableObjectSprayVariantFixedProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projector Settings")
	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projector Settings")
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projector Settings")
	FVector UpDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projector Settings")
	FVector BaseScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projector Settings")
	float BaseRotation;

};

USTRUCT()
struct FCustomizableObjectSprayVariantMCPPayload
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FPrimaryAssetId TextureAssetID;

	UPROPERTY()
	uint16 CompactSaturation;

	UPROPERTY()
	uint16 CompactWear;

	UPROPERTY()
	uint16 CompactScale;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectSprayVariantPayloadClamps
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FFloatRange Saturation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FFloatRange Wear;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FFloatRange Scale;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectSprayVariantSelectablePayload : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Customizable Values")
	FPrimaryAssetId TextureSource;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Customizable Values")
	float Saturation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Customizable Values")
	float Wear;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Customizable Values")
	float Scale;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectSprayVariantSlotImageProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UTexture2D> SprayNotAssignedImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display Data", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UTexture2D> SprayAssignedImage;

};

UCLASS(MinimalAPI)
class UFortCustomizableObjectSprayVariant : public UFortCosmeticVariant
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetic Variant", meta=(Categories="Cosmetics.Variant.Property"))
	FGameplayTag ActiveSelectionTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Name Strings")
	FString EnabledParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Name Strings")
	FString ProjectorParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Name Strings")
	FString TextureParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Name Strings")
	FString SaturationParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Name Strings")
	FString WearParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Name Strings")
	FString ScaleParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Projector Settings")
	FGameplayTagQuery TagQueryForShouldOverrideCODefaultsWithFixedLocationParameters;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Projector Settings", meta=(ShowOnlyInnerProperties))
	FCustomizableObjectSprayVariantFixedProperties FixedSprayLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Spray Options")
	FCustomizableObjectSprayVariantSelectablePayload DefaultSprayCustomization;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Spray Options")
	FCustomizableObjectSprayVariantPayloadClamps SprayNumericConstraints;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Texture Transform Settings")
	float TextureBaseScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SprayVariant|Spray Options")
	FCustomizableObjectSprayVariantSlotImageProperties SpraySlotImageProperties;

};

