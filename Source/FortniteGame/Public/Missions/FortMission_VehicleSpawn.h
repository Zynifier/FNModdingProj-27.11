// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Missions/FortMission.h"
#include "FortMission_VehicleSpawn.generated.h"

class AActor;
class AFortAthenaVehicle;
class UEnvQuery;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct FMissionVehicleSpawnSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Vehicle Spawn Set")
	TSubclassOf<AFortAthenaVehicle> VehicleClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Vehicle Spawn Set")
	int32 MinSpawnCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Vehicle Spawn Set")
	int32 MaxSpawnCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Vehicle Spawn Set")
	FVector SpawnOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Vehicle Spawn Set")
	TSubclassOf<UGameplayEffect> OccupiedLocationGameplayEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Vehicle Spawn Set")
	int32 OccupiedLocationGameplayEffectLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Vehicle Spawn Set")
	FGameplayTagContainer OccupiedLocationAdditionalContextTags;

};

USTRUCT()
struct FVehiclePlacementInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> PlacementActor;

	UPROPERTY()
	FActiveGameplayEffectHandle AppliedGameplayEffectHandle;

};

UCLASS(BlueprintType, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class AFortMission_VehicleSpawn : public AFortMission
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void VehicleDestroyed(AActor* InVehicle);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle Spawn Mission")
	TArray<FMissionVehicleSpawnSet> SpawnSets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Vehicle Spawn Mission")
	TObjectPtr<UEnvQuery> SpawnLocationQuery;

};

