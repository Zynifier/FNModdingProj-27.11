// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_BlockEmotes.generated.h"

UCLASS(Config=Game, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_BlockEmotes : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Replicated, Category="FortAthenaMutator_BlockEmotes")
	bool bGlobalEmoteBlock;

	UPROPERTY(EditDefaultsOnly, Config, Replicated, Category="FortAthenaMutator_BlockEmotes")
	FGameplayTagContainer BlockEmotesWithTags;

	UPROPERTY(EditDefaultsOnly, Config, Replicated, Category="FortAthenaMutator_BlockEmotes")
	TArray<FPrimaryAssetId> SpecificEmotesToBlock;

};

