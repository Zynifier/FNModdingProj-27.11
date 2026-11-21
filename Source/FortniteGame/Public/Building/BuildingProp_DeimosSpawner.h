// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp_AISpawner.h"
#include "BuildingProp_DeimosSpawner.generated.h"

class AAthenaCreativeRift;
class AController;
class UEnvQuery;
class UFortDifficultyOptionEncounter_PawnNumberCap;
class UFortDifficultyOptionEncounter_SpawnGroupProgression;
class UFortDifficultyOptionEncounter_SpawnLimitPawns;
class UFortDifficultyOptionEncounter_SpawnTiming;
class UFortGameplayReceiverMessageComponent;
class UFortGameplayTriggerMessageComponent;

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_DeimosSpawner : public ABuildingProp_AISpawner
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void MinigameStarted();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomizeOptions")
	TArray<TSubclassOf<AAthenaCreativeRift>> DeimosSpawnerOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomizeOptions")
	TArray<TSoftClassPtr<UFortDifficultyOptionEncounter_PawnNumberCap>> PawnNumberCapOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomizeOptions")
	TArray<TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnGroupProgression>> SpawnGroupOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomizeOptions")
	TArray<TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnTiming>> SpawnTimingOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomizeOptions")
	TArray<TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnLimitPawns>> SpawnLimitOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomizeOptions")
	TArray<TSoftObjectPtr<UEnvQuery>> EQSQueryOptions;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	TSoftClassPtr<UFortDifficultyOptionEncounter_PawnNumberCap> SelectedPawnNumberCap;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnGroupProgression> SelectedSpawnGroup;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnTiming> SelectedSpawnTiming;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnLimitPawns> SelectedSpawnLimit;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	TSoftObjectPtr<UEnvQuery> SelectedEQSQuery;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	float SpawnTimingOverrideValue;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	bool bSpawnTimingOverrideEnabled;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	bool bNoSpawnLimitEnabled;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	bool bDamageBuildingsOnSpawn;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	bool bInvulnerable;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	bool bVisible;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	bool bHideVFX;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	float OverrideQueryRadius;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	bool bSortSlotsByBestScore;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_DeimosSpawner")
	bool bEnabledOnMinigameStart;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="BuildingProp_DeimosSpawner", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayReceiverMessageComponent> TurnOnReceiverComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="BuildingProp_DeimosSpawner", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayReceiverMessageComponent> TurnOffReceiverComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="BuildingProp_DeimosSpawner", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayReceiverMessageComponent> KillAllAIReceiverComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="BuildingProp_DeimosSpawner", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayReceiverMessageComponent> KillSpawnerReceiverComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="BuildingProp_DeimosSpawner", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayTriggerMessageComponent> OnKilledMessagerComponent;

private:
	UFUNCTION(BlueprintCallable)
	void OnKillAIReceived(AController* TriggerInstigator);

	UFUNCTION(BlueprintCallable)
	void OnKillRiftReceived(AController* TriggerInstigator);

	UFUNCTION(BlueprintCallable)
	void OnTurnOffReceived(AController* TriggerInstigator);

	UFUNCTION(BlueprintCallable)
	void OnTurnOnReceived(AController* TriggerInstigator);

	UPROPERTY(Config)
	bool bEnableCreativeCreatureSpawners;

};

