// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Valkyrie.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Valkyrie : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Spawn")
	FVector DefaultSpawnRangeStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Spawn")
	FVector DefaultSpawnRangeEnd;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Valkyrie")
	FGameplayTagContainer LobbySpawnTag;

};

