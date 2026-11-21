// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_PlayerAbilitiesOnGamePhase.generated.h"

class UFortAbilitySet;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FPlayerAbilitiesOnGamePhaseAbilityList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PlayerAbilitiesOnGamePhaseAbilityList")
	TArray<TObjectPtr<UFortAbilitySet>> AbilitySetsToAdd;

	UPROPERTY(EditDefaultsOnly, Category="PlayerAbilitiesOnGamePhaseAbilityList")
	TArray<TObjectPtr<UFortAbilitySet>> AbilitySetsToRemove;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PlayerAbilitiesOnGamePhase : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PlayerAbilitiesOnGamePhase")
	TMap<EAthenaGamePhase, FPlayerAbilitiesOnGamePhaseAbilityList> AbilitySetsToGiveOnGamePhaseMap;

};

