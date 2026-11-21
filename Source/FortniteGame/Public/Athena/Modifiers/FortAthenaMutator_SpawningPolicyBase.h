// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_SpawningPolicyBase.generated.h"

class AActor;
class UFortAthenaMutator_SpawningPolicyData;

USTRUCT(BlueprintType)
struct FObjectiveSpecialActorContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> TheSpawnedObjective;

};

USTRUCT()
struct FSpawningInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaMutator_SpawningPolicyData> ItemSpawnData;

};

UCLASS(Abstract, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SpawningPolicyBase : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FObjectiveSpecialActorContainer> SpecialActorIDList;

	UPROPERTY(Transient)
	int32 CachedSpecialActorIdx;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning Delay", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinRespawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning Delay", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxRespawnTime;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SpawningPolicyBase", meta=(AllowPrivateAccess="true"))
	float SpawnFailureLockoutTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	EAthenaGamePhase GamePhaseToStartSpawning;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SpawningPolicyBase", meta=(AllowPrivateAccess="true"))
	uint8 bShouldCenterGroundCheckAtFoundLocation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	uint8 bShouldMaintainItemCount : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	uint8 bAllowedDespawnToMaintainItemCount : 1;

	UPROPERTY(EditDefaultsOnly, Category="Base Query", meta=(AllowPrivateAccess="true"))
	uint8 bWaitForNavmeshToBeLoaded : 1;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaMutator_SpawningPolicyData> ItemDataRemovalQueryPending;

	UPROPERTY(Transient)
	TArray<FSpawningInfo> QueuedSpawnInfo;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UFortAthenaMutator_SpawningPolicyData>, int32> QueuedSpawnInfoCount;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UFortAthenaMutator_SpawningPolicyData>, float> NextSpawnTime;

};

