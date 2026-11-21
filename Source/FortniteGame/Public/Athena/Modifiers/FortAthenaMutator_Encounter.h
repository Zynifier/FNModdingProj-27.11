// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Encounter.generated.h"

class AActor;
class ABuildingRift;
class AController;
class AFortAIPawn;
class UAnimationSharingSetup;
class UFortAIEncounterInfo;
class UFortDifficultyEncounterSettings;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Encounter : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy);

	UFUNCTION()
	void HandleRiftDying(UFortAIEncounterInfo* Encounter, ABuildingRift* Rift, AController* Controller, AActor* DamageActor);

	UPROPERTY(EditDefaultsOnly, Category="Encounter")
	FScalableFloat ShouldSpawnEncounter;

	UPROPERTY(EditDefaultsOnly, Category="Encounter")
	TObjectPtr<UFortDifficultyEncounterSettings> EncounterSettings;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIEncounterInfo> CurrentEncounter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AnimationSharing")
	bool bUsesAnimationSharing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AnimationSharing", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UAnimationSharingSetup> AnimationSharingSetup;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Loot Tier")
	FName LootTierGroupOverride;

};

