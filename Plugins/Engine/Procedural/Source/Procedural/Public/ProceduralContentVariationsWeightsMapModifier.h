// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralContentVariationsWeightsModifier.h"
#include "ProceduralContentVariationsWeightsMapModifier.generated.h"

class UProceduralFloatDataMap;

USTRUCT(BlueprintType)
struct FProceduralContentVariationMap
{
	GENERATED_BODY()

public:
	/** Content Variation Index. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier", meta=(ClampMin="0", UIMin="0"))
	int32 VariationIndex;

	/** Content Variation Map.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Modifier")
	TObjectPtr<UProceduralFloatDataMap> Map;

	/** Content Variation Weight. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier")
	float Weight;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"), AutoExpandCategories=("Modifier"))
class UProceduralContentVariationsWeightsMapModifier : public UProceduralContentVariationsWeightsModifier
{
	GENERATED_BODY()

public:
	/** Content Variations Maps.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Modifier")
	TArray<FProceduralContentVariationMap> VariationsMaps;

};

