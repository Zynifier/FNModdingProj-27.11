// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Customization/CustomColorSwatchType.h"
#include "FortGender.h"
#include "CustomColorSwatch.generated.h"

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UCustomColorSwatch : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="ColorSwatch")
	TEnumAsByte<EFortCustomGender::Type> GenderPermitted;

protected:
	UPROPERTY(AssetRegistrySearchable)
	TEnumAsByte<EColorSwatchType> ColorSwatchType;

};

