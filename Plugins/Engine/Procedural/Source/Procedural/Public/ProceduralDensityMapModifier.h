// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralDensityModifier.h"
#include "ProceduralDensityMapModifier.generated.h"

class UProceduralFloatDataMap;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"), AutoExpandCategories=("Modifier"))
class UProceduralDensityMapModifier : public UProceduralDensityModifier
{
	GENERATED_BODY()

public:
	/** Density Map.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Modifier")
	TObjectPtr<UProceduralFloatDataMap> Map;

};

