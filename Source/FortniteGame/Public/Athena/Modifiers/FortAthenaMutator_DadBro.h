// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortAthenaMutator_DadBro.generated.h"

class AFortAIPawn;
class AFortPawn;
class AFortPickup;
class IFortTimeOfDayManagerInterface;
class UFortAIEncounterInfo;
class UFortDifficultyEncounterSettings;

UENUM()
enum class EDadBroState : int32
{
	NotYet = 0,
	Initializing = 1,
	Active = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDadBroSpawned, AFortAIPawn*, DadBro);

USTRUCT()
struct FFortDadbroPickupDespawnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float DespawnTime;

	UPROPERTY()
	TObjectPtr<AFortPickup> Pickup;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_DadBro : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void DespawnIdleEffects();

	UFUNCTION(BlueprintCallable)
	void DespawnPickupsForAoE(float InstantDespawnRange, float MaxDespawnRange, float DespawnTravelSpeed);

	UFUNCTION(BlueprintPure)
	FRotator GetDesiredDadBroRotation() const;

	UFUNCTION(BlueprintPure)
	float GetTimeSinceDadBroStart() const;

	UFUNCTION(BlueprintCallable)
	void ResetBackToStartSafeZone();

	UFUNCTION(BlueprintImplementableEvent)
	void SpawnIdleEffects(const FVector& Location);

	UFUNCTION(BlueprintCallable)
	void StartNextSafeZonePhase();

private:
	UFUNCTION(NetMulticast, Reliable)
	void DoDebugSphereForImpulse();

	UFUNCTION()
	void HandleAIDied(UFortAIEncounterInfo* Encounter, AFortAIPawn* DyingEnemy);

	UFUNCTION()
	void HandleAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy);

	UFUNCTION()
	void HandleNewTimeOfDayManager(TScriptInterface<IFortTimeOfDayManagerInterface> NewTodManager) const;

	UFUNCTION()
	void ListenedPawnLanded(const FHitResult& Hit);

	UFUNCTION()
	void OnRep_DadBroCodeState();

	UFUNCTION()
	void OnRep_DadBroPawn();

	UPROPERTY(EditDefaultsOnly, Category="AI")
	TObjectPtr<UFortDifficultyEncounterSettings> DadBroEncounter;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_DadBro")
	FVector DadBroSpawnLocation;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> DadBroEncounterInstance;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DadBroPawn)
	TObjectPtr<AFortAIPawn> DadBroPawn;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnDadBroSpawned OnDadBroSpawnedDelegate;

	UPROPERTY()
	TArray<FFortDadbroPickupDespawnData> PendingPickupDespawns;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_DadBro")
	int32 MaxPickupsToDespawnAtOnce;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_DadBro")
	float PickupTimeRangeToDespawnAtOnce;

	UPROPERTY(ReplicatedUsing=OnRep_DadBroCodeState)
	EDadBroState DadBroCodeState;

	UPROPERTY(Replicated)
	float ServerTimeDadBroStarted;

	UPROPERTY(Replicated)
	float TimeTakenToDefeatDadBro;

	UPROPERTY()
	TObjectPtr<AFortPawn> ListeningPawn;

	UPROPERTY(EditAnywhere, Category="Config|Warning")
	FGameplayTag InitialLandingCueTag;

	UPROPERTY(EditAnywhere, Category="Config")
	FFortRespawnLogicData RespawnLogicData;

	UPROPERTY(EditAnywhere, Category="Config")
	FScalableFloat UseLevelsForSizeModes;

	UPROPERTY(EditAnywhere, Category="Config|Time")
	FScalableFloat OverrideTimeOfDay;

	UPROPERTY(EditAnywhere, Category="Config|Time")
	FScalableFloat OverriddenTimeOfDay;

	UPROPERTY(EditAnywhere, Category="Config|Time")
	FScalableFloat OverriddenTimeOfDayRate;

	UPROPERTY(EditAnywhere, Category="Config|GameOver")
	FScalableFloat DelayGameOverOnPlayerWin;

	UPROPERTY(EditAnywhere, Category="Config|GameOver")
	FScalableFloat DelayGameOverOnDadBroWin;

	UPROPERTY(EditAnywhere, Category="Config")
	FScalableFloat DadBroFirstSafeZoneIndex;

	UPROPERTY(EditAnywhere, Category="Config")
	FScalableFloat HideSafeZoneCircles;

	UPROPERTY(EditAnywhere, Category="Config|Spawning")
	FScalableFloat DadBroDelayBeforeSpawning;

	UPROPERTY(EditAnywhere, Category="Config|Spawning")
	FScalableFloat DadBroApplySpawnImpulse;

	UPROPERTY(EditAnywhere, Category="Config|Spawning")
	FScalableFloat DadBroImpulseForce;

	UPROPERTY(EditAnywhere, Category="Config|Spawning")
	FScalableFloat DadBroImpulseRadius;

	UPROPERTY(EditAnywhere, Category="Config|Spawning")
	FScalableFloat DadBroVerticalImpulseOffset;

	UPROPERTY(EditAnywhere, Category="Config|PickUps")
	FScalableFloat OverridePickUpDespawnTime;

};

