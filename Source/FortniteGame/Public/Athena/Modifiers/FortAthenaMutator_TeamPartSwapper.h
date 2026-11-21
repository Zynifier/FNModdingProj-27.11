// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_TeamPartSwapper.generated.h"

class UCustomCharacterPart;

USTRUCT()
struct FPartSwapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PartSwapData")
	TArray<TObjectPtr<UCustomCharacterPart>> PartsToSwapIn;

};

UCLASS(HideCategories=("Tick", "Mutator", "Replication", "Actor", "LOD", "Cooking", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_TeamPartSwapper : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<uint8> TeamNums;

	UPROPERTY(EditAnywhere, Category="Part Data")
	TArray<FPartSwapData> SwapData;

};

