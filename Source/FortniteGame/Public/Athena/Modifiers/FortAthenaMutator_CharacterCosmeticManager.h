// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_CharacterCosmeticManager.generated.h"

UCLASS(HideCategories=("Actor", "Cooking", "FortAthenaMutator", "LOD", "Mutator", "Replication", "Tick", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CharacterCosmeticManager : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_CharacterCosmeticManager", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EManagedCosmeticType"))
	int32 BlockManagedCosmeticTypes;

};

