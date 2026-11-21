// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "AI/FortAISpawnGroupUpgradeUIData.h"
#include "Pawns/FortAIPawn.h"
#include "FortPendingSpawnInfo.generated.h"

class AActor;
class AFortAIPawn;
class AFortPlayerController;
class UFortAIEncounterInfo;
class UFortAISpawnGroup;
class UFortAbilitySet;
class UFortGameplayModifierItemDefinition;

USTRUCT()
struct FPendingSpawnInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<AFortAIPawn> PawnClassToSpawn;

	UPROPERTY()
	TObjectPtr<AActor> SpawnPoint;

	UPROPERTY()
	FVector SpawnLocation;

	UPROPERTY()
	FRotator SpawnRotation;

	UPROPERTY()
	TObjectPtr<AActor> SpawnSource;

	UPROPERTY()
	bool bSpawnedFromExternalSpawner;

	UPROPERTY()
	EFortressAIType AIType;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> TargetPlayer;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> EncounterInfo;

	UPROPERTY()
	float DifficultyLevel;

	UPROPERTY()
	TObjectPtr<UFortAISpawnGroup> SpawnGroup;

	UPROPERTY()
	FGuid SpawnGroupGuid;

	UPROPERTY()
	int32 EnemyIndexInSpawnGroup;

	UPROPERTY()
	float TimeToSpawn;

	UPROPERTY(meta=(IgnoreForMemberInitializationTest))
	FGuid PendingSpawnInfoGuid;

	UPROPERTY()
	bool bIgnoreCollision;

	UPROPERTY()
	bool bKillBuildingActorsAtSpawnLocation;

	UPROPERTY()
	float EncounterAILifespan;

	UPROPERTY()
	float ScoreMultiplier;

	UPROPERTY()
	bool bDebugSpawnedAI;

	UPROPERTY()
	TArray<TObjectPtr<UFortAbilitySet>> AbilitySetsToGrantOnSpawn;

	UPROPERTY()
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> ModifiersToApplyOnSpawn;

	UPROPERTY()
	FFortAISpawnGroupUpgradeUIData UpgradeUIData;

	UPROPERTY()
	FFortAIPawnLootDropData LootDropData;

};

