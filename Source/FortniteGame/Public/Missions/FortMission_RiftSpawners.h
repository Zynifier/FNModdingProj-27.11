// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "FortEncounterSettings.h"
#include "Missions/FortMission.h"
#include "FortMission_RiftSpawners.generated.h"

class AActor;
class ABuildingRift;
class AController;
class AFortAIPawn;
class AFortPlayerPawn;
class UFortAIEncounterInfo;
class UFortAIEncounterSequence;
class UPrimitiveComponent;

USTRUCT()
struct FFortRiftSpawnerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingRift> Rift;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> Encounter;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterSequence> EncounterSequence;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerPawn>> PlayersInRange;

	UPROPERTY()
	float TriggerDamagePercentage;

	UPROPERTY()
	TObjectPtr<AController> KillingInstigator;

	UPROPERTY()
	TObjectPtr<AActor> KillingDamageCauser;

	UPROPERTY()
	FTimerHandle DeactivationTimerHandle;

	UPROPERTY()
	FTimerHandle BurstFallbackTimerHandle;

	UPROPERTY()
	FFortEncounterSettings OverrideSettings;

	UPROPERTY()
	bool bUseOverrideSettings;

};

UCLASS(Abstract, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class AFortMission_RiftSpawners : public AFortMission
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy);

	UFUNCTION()
	void HandleRampStarted(UFortAIEncounterInfo* Encounter);

	UFUNCTION(BlueprintCallable)
	void SetCalendarAllowsActive(bool bInCanBeActive);

protected:
	UFUNCTION()
	void HandleRiftDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

private:
	UFUNCTION()
	void HandleEncounterAllBurstEnemiesSpawned(UFortAIEncounterInfo* Encounter);

	UFUNCTION()
	void OnActiveEventsChanged(const TArray<FString>& ActiveEventFlags);

	UFUNCTION()
	void OnFinalSpawnUsed(UFortAIEncounterInfo* Encounter);

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	bool bStartBasedOnAthenaGamePhases;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners", meta=(EditCondition="bStartBasedOnAthenaGamePhases"))
	EAthenaGamePhase StartingGamePhase;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	float StartingDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	bool bUseAthenaSafeZonePhases;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	bool bSynchronizeEncounterStartTimes;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners", meta=(EditCondition="bUseAthenaSafeZonePhases"))
	int32 MinEncounterIndex;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners", meta=(EditCondition="bUseAthenaSafeZonePhases"))
	int32 MaxEncounterIndex;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	FFortEncounterSettings EncounterSettings;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	bool bAllowRiftIntensification;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	FScalableFloat MinDamageTriggerPercentage;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	FScalableFloat MaxDamageTriggerPercentage;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	FGameplayTagQuery RequiredRiftTagsQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	FString RequiredEventFlag;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	TArray<FName> AssociatedSupplyDropIDs;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	float SpawnerShutdownCheckInterval;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	float BurstFallbackTime;

	UPROPERTY(EditDefaultsOnly, Category="FortMission_RiftSpawners")
	float CalendarRecheckInterval;

	UPROPERTY(Transient)
	TArray<FFortRiftSpawnerData> ActiveRiftSpawnerData;

	UPROPERTY(Transient)
	int32 CurrentEncounterIndex;

	UPROPERTY(Transient)
	bool bRiftSpawningInProgress;

	UPROPERTY(Transient)
	float SyncedEncounterStartTime;

	UPROPERTY(Transient)
	bool bCalendarAllowsSpawning;

};

