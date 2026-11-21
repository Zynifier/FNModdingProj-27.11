// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterBodyPartData.h"
#include "CustomCharacterHeadData.generated.h"

class UCustomHairColorSwatch;
class UCustomSkinColorSwatch;
class UFortMontageLookupTable;

UCLASS()
class UCustomCharacterHeadData : public UCustomCharacterBodyPartData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Animation")
	TSoftObjectPtr<UFortMontageLookupTable> RootSkeletonDefaultMontageLookupTable;

	UPROPERTY(EditAnywhere, Category="Animation")
	TSoftObjectPtr<UFortMontageLookupTable> RootSkeletonOverrideMontageLookupTable;

	UPROPERTY(EditAnywhere, Category="MaterialTweaks")
	TSoftObjectPtr<UCustomSkinColorSwatch> SkinColorSwatch;

	UPROPERTY(EditAnywhere, Category="MaterialTweaks", meta=(DeprecationMessage="We don't currently use this (although it works if desired).  See skin color swatch."))
	TSoftObjectPtr<UCustomHairColorSwatch> HairColorSwatch;

	UPROPERTY(EditAnywhere, Category="HatMorphs")
	TArray<FName> CapMorphTargets;

	UPROPERTY(EditAnywhere, Category="HatMorphs")
	TArray<FName> HelmetMorphTargets;

	UPROPERTY(EditAnywhere, Category="HatMorphs")
	TArray<FName> MaskMorphTargets;

	UPROPERTY(EditAnywhere, Category="HatMorphs")
	TArray<FName> HatMorphTargets;

};

