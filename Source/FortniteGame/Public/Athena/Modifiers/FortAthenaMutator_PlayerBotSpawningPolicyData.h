// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator_SpawningPolicyData.h"
#include "FortAthenaMutator_PlayerBotSpawningPolicyData.generated.h"

class AFortGameModeAthena;
class AFortPlayerPawnAthena;
class UDataTable;
class UFortAthenaAIBotCosmeticData;
class UFortAthenaAIBotInventoryItems;
class UFortAthenaAIBotSkillSet;
class UFortAthenaAISpawnerData;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaMutator_PlayerBotSpawningPolicyData : public UFortAthenaMutator_SpawningPolicyData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Transient, Category="Debug")
	bool bUseCustomizationInEditor;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	TSubclassOf<AFortPlayerPawnAthena> PlayerBotPawn;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	FScalableFloat Skill;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UFortAthenaAIBotSkillSet>> SkillSetOverrideClasses;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Spawning", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortAthenaAIBotInventoryItems> StartupInventory;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameModeAthena> CachedGameMode;

	UPROPERTY(EditDefaultsOnly, Category="Placement", meta=(AllowPrivateAccess="true"))
	float MaxTraceHeight;

	UPROPERTY(EditDefaultsOnly, Category="Placement", meta=(AllowPrivateAccess="true"))
	float MinTraceHeight;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	float InitialSpawnDelay;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	float SpawnDelay;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UFortAthenaAIBotCosmeticData> CosmeticCustomizationData;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic")
	FScalableFloat DefaultCosmeticLibraryWeight;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> CosmeticLibraryWeightRegionOverride;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	TSoftClassPtr<UFortAthenaAISpawnerData> AISpawnerData;

};

