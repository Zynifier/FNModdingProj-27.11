// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/FortSafeZoneIndicator.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_EQSActorProviderInterface.h"
#include "Athena/Modifiers/FortAthenaMutator_EQSProviderInterface.h"
#include "FortAthenaMutator_EQSActorSpawner.generated.h"

class AActor;
class AFortAthenaMutator_EQSActorSpawner;
class AFortPickup;
class APawn;
class UEQSActorSpawner;
class UEQSActorSpawnerHelperDestroyActorsInArea;
class UEnvQuery;
class UEnvQueryInstanceBlueprintWrapper;
class UFortAthenaAISpawnerData;
class UFortItemDefinition;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EEQSActorSpawnerSpawnType : uint8
{
	/** A normal actor, no special actions are taken to initialize the actor */
	Actor = 0,
	/** A pawn that an AI is attached to */
	AIPawn = 1,
	/** A pickup actor that contains an item */
	Pickup = 2,
};

UENUM()
enum class EEQSActorSpawnerStopSpawningReason : uint8
{
	/** The actor spawner has successfully spawned the requested number of actors.  */
	Success = 0,
	/** The actor spawner has been manually asked to stop spawning through a function call. */
	ManualStop = 1,
	/** The actor spawner was requeued to start spawning a new set of actors.*/
	Requeued = 2,
	/** The actor spawner has failed to spawn the requested number of actors and has ran out of retry attempts. */
	RanOutOfRetries = 3,
};

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EEQSActorSpawnerTriggerType : uint8
{
	/** Has to be manually triggered in code or blueprint */
	Manual = 0,
	/** Spawns occur during the specified safe zone phase and index */
	SafeZoneState = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEQSActorSpawnerAISpawned, APawn*, SpawnedPawn, const UFortAthenaAISpawnerData*, AISpawnerData, const UEQSActorSpawner*, EQSActorSpawner);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEQSActorSpawnerActorSpawned, AActor*, SpawnedActor, const UEQSActorSpawner*, EQSActorSpawner);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEQSActorSpawnerPrepareEQS, const UEQSActorSpawner*, EQSActorSpawner, UEnvQueryInstanceBlueprintWrapper*, EQSInstance);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEQSActorSpawningPhaseEnded, const UEQSActorSpawner*, EQSActorSpawner);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEQSActorSpawningPhaseStarted, const UEQSActorSpawner*, EQSActorSpawner, int32, ActivationIndex);

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FEQSActorSpawnerClassToSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EQSActorSpawnerClassToSpawnData")
	FName SharedAssetID;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerClassToSpawnData")
	FScalableFloat Weight;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerClassToSpawnData")
	EEQSActorSpawnerSpawnType SpawnActorType;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerClassToSpawnData", meta=(EditCondition="SpawnActorType == EEQSActorSpawnerSpawnType::Actor"))
	TSubclassOf<AActor> ActorClassToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerClassToSpawnData", meta=(EditCondition="SpawnActorType == EEQSActorSpawnerSpawnType::Actor"))
	float AdjustSpawnedActorToGroundLocationTraceZOffset;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerClassToSpawnData", meta=(EditCondition="SpawnActorType == EEQSActorSpawnerSpawnType::AIPawn"))
	TSubclassOf<UFortAthenaAISpawnerData> AISpawnerData;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerClassToSpawnData", meta=(EditCondition="SpawnActorType == EEQSActorSpawnerSpawnType::Pickup"))
	TSubclassOf<AFortPickup> PickupClassToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerClassToSpawnData", meta=(EditCondition="SpawnActorType == EEQSActorSpawnerSpawnType::Pickup"))
	TObjectPtr<UFortItemDefinition> PickupItemDefinition;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FEQSActorSpawnerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EQSActorSpawnerData")
	FName NameId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EQSActorSpawnerData")
	bool bEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EQSActorSpawnerData")
	EEQSActorSpawnerTriggerType SpawningTrigger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger == EEQSActorSpawnerTriggerType::SafeZoneState"))
	EFortSafeZoneState SafeZoneStateToStartSpawning;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(ClampMin="-1", EditCondition="SpawningTrigger == EEQSActorSpawnerTriggerType::SafeZoneState"))
	int32 SafeZoneIndexToSpawnIn;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger != EEQSActorSpawnerTriggerType::SafeZoneState || SafeZoneIndexToSpawnIn >= 0"))
	FScalableFloat DelayBeforeSpawning;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger != EEQSActorSpawnerTriggerType::SafeZoneState || SafeZoneIndexToSpawnIn >= 0"))
	FScalableFloat TimeBetweenSpawns_Min;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger != EEQSActorSpawnerTriggerType::SafeZoneState || SafeZoneIndexToSpawnIn >= 0"))
	FScalableFloat TimeBetweenSpawns_Max;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger != EEQSActorSpawnerTriggerType::SafeZoneState || SafeZoneIndexToSpawnIn >= 0"))
	FScalableFloat TotalActorsToSpawn_Min;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger != EEQSActorSpawnerTriggerType::SafeZoneState || SafeZoneIndexToSpawnIn >= 0"))
	FScalableFloat TotalActorsToSpawn_Max;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger == EEQSActorSpawnerTriggerType::SafeZoneState && SafeZoneIndexToSpawnIn < 0"))
	FScalableFloat DelayBeforeSpawning_BySafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger == EEQSActorSpawnerTriggerType::SafeZoneState && SafeZoneIndexToSpawnIn < 0"))
	FScalableFloat TimeBetweenSpawns_Min_BySafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger == EEQSActorSpawnerTriggerType::SafeZoneState && SafeZoneIndexToSpawnIn < 0"))
	FScalableFloat TimeBetweenSpawns_Max_BySafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger == EEQSActorSpawnerTriggerType::SafeZoneState && SafeZoneIndexToSpawnIn < 0"))
	FScalableFloat TotalActorsToSpawn_Min_BySafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(EditCondition="SpawningTrigger == EEQSActorSpawnerTriggerType::SafeZoneState && SafeZoneIndexToSpawnIn < 0"))
	FScalableFloat TotalActorsToSpawn_Max_BySafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	FScalableFloat bSpawnInCenterOfBuildingGridCell;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	FVector SpawnLocationOffset;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	TArray<TSubclassOf<UEQSActorSpawnerHelperDestroyActorsInArea>> SpawnerHelperDestroyActorsInAreaClasses;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	FScalableFloat TotalRetryAttemptsOnSpawnFailure;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	bool bAvoidRepeatClassSpawning;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	TArray<FEQSActorSpawnerClassToSpawnData> SpawnClassesData;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	TObjectPtr<UEnvQuery> BasePlacementQuery;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	TObjectPtr<UEnvQuery> SpawnActorPlacementQuery;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	bool bIncludeMutatorBasePlacementQueryResults;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	TArray<FEnvNamedValue> SpawnActorPlacementQueryParams;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData")
	TObjectPtr<UEnvQuery> SpawnedActorRemovalQuery;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(ClampMin="0.001000", UIMin="0.000000"))
	float BaseQueryingAttemptIntervalTimeSeconds;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerData", meta=(ClampMin="0.010000", UIMin="0.000000"))
	float SpawnedActorRemovalQueryInterval;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_EQSActorSpawner : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	UEQSActorSpawner* GetEQSActorSpawnerByNameId(const FName& NameId);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool StartSpawningManually(const FName& NameId, int32 OptionalActivationId = -1);

	UPROPERTY(BlueprintAssignable)
	FOnEQSActorSpawningPhaseStarted OnEQSActorSpawningPhaseStarted;

	UPROPERTY(BlueprintAssignable)
	FOnEQSActorSpawningPhaseEnded OnEQSActorSpawningPhaseEnded;

	UPROPERTY(BlueprintAssignable)
	FOnEQSActorSpawnerActorSpawned OnActorSpawnedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnEQSActorSpawnerAISpawned OnAISpawnedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnEQSActorSpawnerPrepareEQS OnPrepareEQS;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActorSpawned(AActor* SpawnedActor, const FEQSActorSpawnerData& EQSActorSpawnerData, const UEQSActorSpawner* EQSActorSpawner);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorSpawnPhaseEnded(const FEQSActorSpawnerData& EQSActorSpawnerData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnActorSpawnPhaseStarted(const FEQSActorSpawnerData& EQSActorSpawnerData, int32 ActivationIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrepareEQSRequest(const UEQSActorSpawner* EQSActorSpawner, UEnvQueryInstanceBlueprintWrapper* EQSInstanceWrapper);

	UFUNCTION(BlueprintNativeEvent)
	bool ShouldOverrideClassesToSpawn(TArray<FEQSActorSpawnerClassToSpawnData>& OutOverrideClassesToSpawn, const FEQSActorSpawnerData& SpawnerData);

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_EQSActorSpawner")
	TObjectPtr<UEnvQuery> MutatorBasePlacementQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_EQSActorSpawner", meta=(ClampMin="0.001000", UIMin="0.000000"))
	float MutatorBaseQueryingAttemptIntervalTimeSeconds;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_EQSActorSpawner")
	TArray<FEQSActorSpawnerData> ActorSpawningDatas;

	UPROPERTY()
	TArray<TObjectPtr<UEQSActorSpawner>> ActorSpawners;

private:
	UPROPERTY()
	TMap<int32, TObjectPtr<UEQSActorSpawner>> AIPawnSpawnRequestIdToEQSActorSpawnerMap;

};

UCLASS(BlueprintType)
class UEQSActorSpawner : public UObject, public IFortAthenaMutator_EQSProviderInterface, public IFortAthenaMutator_EQSActorProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FEQSActorSpawnerData GetSpawnerData();

protected:
	UFUNCTION()
	void OnFindActorSpawnLocationQueryFinished(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus);

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaMutator_EQSActorSpawner> OwningActorSpawnerMutator;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> SpawnedActors;

	UPROPERTY()
	TArray<TObjectPtr<UEQSActorSpawnerHelperDestroyActorsInArea>> SpawnerHelperDestroyActorsInAreaList;

};

UCLASS(BlueprintType, Blueprintable)
class UEQSActorSpawnerHelperDestroyActorsInArea : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void EQSActorSpawnerHelperDestroyActorsInArea(TArray<AActor*>& OutDestroyedActors, const FTransform& Transform);

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerHelperDestroyActorsInArea")
	FVector OverlapCheckExtent;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerHelperDestroyActorsInArea")
	TArray<TSubclassOf<AActor>> ActorClassesToDestroy;

	UPROPERTY(EditDefaultsOnly, Category="EQSActorSpawnerHelperDestroyActorsInArea")
	bool bDestroyBuildingActorsOnSpawn;

};

