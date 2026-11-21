// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Valkyrie/FortExposedAssetProviderInterface.h"
#include "FortRandomColorPropPalette.generated.h"

class UBuildingTextureData;

UCLASS(BlueprintType, Blueprintable)
class UFortRandomColorPropPalette : public UObject, public IFortExposedAssetProvider
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swatch")
	TArray<TObjectPtr<UBuildingTextureData>> Swatch_Palette;

};

