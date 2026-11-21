// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "TieredWaveSet.generated.h"

class UFortDifficultyOptionEncounter_DirectionNumber;
class UFortDifficultyOptionEncounter_Distance;
class UFortDifficultyOptionEncounter_ModifierTags;
class UFortDifficultyOptionEncounter_SpawnGroupProgression;
class UFortDifficultyOptionEncounter_SpawnPointsCurve;
class UFortDifficultyOptionEncounter_SpawnPointsMultiplier;
class UFortDifficultyOptionEncounter_TimedModifierTags;
class UFortDifficultyOptionEncounter_UtilitiesAdjustment;
class UFortDifficultyOptionEncounter_UtilitiesFree;
class UFortDifficultyOptionEncounter_UtilitiesLocked;
class UFortMissionInfo;

UENUM(BlueprintType)
enum class EWaveRules : uint8
{
	KillAllEnemies = 0,
	Timed = 1,
	KillPoints = 2,
	KillSpecificEnemy = 3,
	Mission = 4 UMETA(Tooltip="The wave will spawn 1 or more missions. The wave will be completed once all of those missions are completed"),
	DestroyRifts = 5,
};

USTRUCT(BlueprintType)
struct FTieredWaveSetData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	int32 EDOIdx;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	float BreatherBetweenWaves;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	EWaveRules WaveRules;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	FGameplayTag EnemyTypeToKillMod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TArray<TSoftObjectPtr<UFortMissionInfo>> WaveMissions;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	float WaveLengthMod;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	float NumKillsMod;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	float KillPointsMod;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	float DifficultyAddMod;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	int32 TargetNumPillarsToSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	bool bDeferTemporaryModifiers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnPointsMultiplier> OverrideSpawnPointsMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnPointsCurve> OverrideSpawnPointsCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnGroupProgression> OverrideSpawnProgression;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_UtilitiesAdjustment> OverrideUtilitiesAdjustment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_UtilitiesFree> OverrideUtilitiesFree;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_UtilitiesLocked> OverrideUtilitiesLocked;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_Distance> OverrideDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_DirectionNumber> OverrideDirectionNumber;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_ModifierTags> OverrideModifierTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortDifficultyOptionEncounter_TimedModifierTags> OverrideTimedModifierTags;

};

USTRUCT()
struct FTieredWaveSet : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Data")
	TArray<FTieredWaveSetData> WaveData;

};

