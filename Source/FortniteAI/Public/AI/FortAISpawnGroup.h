// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortAISpawnGroup.generated.h"

class UFortAIPawnVariant;

USTRUCT()
struct FFortSpawnGroupEncounterTypeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortSpawnGroupEncounterTypeData")
	FGameplayTagContainer EncounterTypeTags;

	UPROPERTY(EditAnywhere, Category="Spawning")
	FCurveTableRowHandle MaxGroupCategoryPopulationDensityCurve;

	UPROPERTY(EditAnywhere, Category="Spawning")
	FCurveTableRowHandle RespawnDelayCurve;

};

USTRUCT(BlueprintType)
struct FSpawnGroupEnemy
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Enemy")
	TSubclassOf<UFortAIPawnVariant> EnemyVariantClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Enemy")
	bool bOverrideVariantSpawnPointValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Enemy", meta=(EditCondition="bOverrideVariantSpawnPointValue"))
	int32 SpawnValue;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAISpawnGroup : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AISpawnGroup")
	TSubclassOf<UFortAIPawnVariant> GetEnemy(int32 EnemyIndex) const;

	UFUNCTION(BlueprintPure, Category="AISpawnGroup")
	int32 GetNumberOfEnemies() const;

	UFUNCTION(BlueprintPure, Category="AISpawnGroup")
	bool IsLargeSpawnGroup() const;

	UFUNCTION(BlueprintPure, Category="AISpawnGroup")
	bool IsPrototype() const;

	UFUNCTION(BlueprintPure, Category="AISpawnGroup")
	bool IsValidForEnemySpawners() const;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(ArraySizeEnum="/Script/FortniteGame.EFortAIUtility"))
	float EnemyUtilities[16];

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning")
	TArray<FSpawnGroupEnemy> EnemiesToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning", meta=(ScriptName="IsPrototypeValue"))
	bool bIsPrototype;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EnemySpawner", meta=(ScriptName="IsValidForEnemySpawnersValue"))
	bool bIsValidForEnemySpawners;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LargeSpawnGroup", meta=(ScriptName="IsLargeSpawnGroupValue"))
	bool bIsLargeSpawnGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LargeSpawnGroup", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float MaxDiscountRatio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	bool bUseWeightSystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning")
	FScalableFloat Weight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning")
	FScalableFloat MinNumber;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning")
	FScalableFloat MaxNumber;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	FCurveTableRowHandle MaxGroupCategoryPopulationDensityCurve;

	UPROPERTY(EditAnywhere, Category="Spawning")
	TArray<FFortSpawnGroupEncounterTypeData> EncounterTypeData;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer SpawnGroupGameplayTags;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagQuery RequiredTagQuery;

};

