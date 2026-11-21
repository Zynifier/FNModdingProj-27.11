// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator_CustomCharacterParts.h"
#include "FortAthenaMutator_CustomCharacterPartsByKills.generated.h"

USTRUCT(BlueprintType)
struct FCustomCharacterPartsByKillOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CustomCharacterPartsByKillOverrideData")
	FScalableFloat KillThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CustomCharacterPartsByKillOverrideData")
	FScalableFloat Weight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CustomCharacterPartsByKillOverrideData")
	TArray<FPartOverrideData> PartOverrideData;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Base", "Override", "Customizations", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CustomCharacterPartsByKills : public AFortAthenaMutator_CustomCharacterParts
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Skins")
	TArray<FCustomCharacterPartsByKillOverrideData> PartOverrideByKillsCustomizations;

};

