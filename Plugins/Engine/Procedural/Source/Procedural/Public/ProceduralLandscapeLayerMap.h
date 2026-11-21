// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralDataMap.h"
#include "ProceduralLandscapeLayerMap.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object", "Object"), AutoExpandCategories=("Landscape", "DataMapping"))
class UProceduralLandscapeLayerMap : public UProceduralFloatDataMap
{
	GENERATED_BODY()

public:
	/** Landscape Paint Layer Name */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Landscape")
	FName LandscapeLayerName;

	/** Landscape Edit Layer Name */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Landscape")
	FName LandscapeEditLayerName;

};

