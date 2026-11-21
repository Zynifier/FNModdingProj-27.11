// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "FortAthenaLivingWorldConditionContainer.h"
#include "FortAthenaLivingWorldEncounter.generated.h"

class AActor;
class AController;
class IFortAthenaLivingWorldPointProviderInterface;
class UDataTable;
class UFortAthenaLivingWorldEncounter;
class UFortAthenaLivingWorldEventData;
class UPrimitiveComponent;

USTRUCT()
struct FFortAthenaLivingWorldEncounterStage
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> EventTable;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat MaximumConcurrentNumberOfAI;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	bool bAllowRandomMaximumActorCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(EditCondition="bAllowRandomMaximumActorCount"))
	FScalableFloat MaximumConcurrentNumberOfAI_LowValue;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat MaxSpawnCountPerEventGeneration;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaLivingWorldEncounter : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat IntervalBetweenEventGeneration;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	TArray<FFortAthenaLivingWorldEncounterStage> Stages;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAthenaLivingWorldEncounterInstance : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorDestroyed, AActor*, DestroyedActor);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorDied, AActor*, DiedActor);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorSpawned, AActor*, SpawnedActor);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventSpawned, const TArray<AActor*>, SpawnedActors);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddAllowedPointProvider(const TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>& PointProvider);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AdvanceEncounterStage();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	int32 GetAliveSpawnedActorCount() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	int32 GetTotalActorCount() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool HasReachedMaxSpawnedCount() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool OwnsActor(AActor* Actor) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void PauseEncounter();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveAllowedPointProvider(const TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>& PointProvider);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RequestEventGeneration();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Reset();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ResumeEncounter();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StartEncounterStage(const int32 StageIndex);

	UPROPERTY(BlueprintAssignable)
	FOnActorSpawned OnActorSpawned;

	UPROPERTY(BlueprintAssignable)
	FOnActorSpawned OnFirstActorSpawned;

	UPROPERTY(BlueprintAssignable)
	FOnActorDestroyed OnActorDestroyed;

	UPROPERTY(BlueprintAssignable)
	FOnActorDestroyed OnLastActorDestroyed;

	UPROPERTY(BlueprintAssignable)
	FOnActorDied OnActorDied;

	UPROPERTY(BlueprintAssignable)
	FOnEventSpawned OnEventSpawned;

private:
	UFUNCTION()
	void OnEncounterActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(Transient)
	FFortAthenaLivingWorldConditionContainer ConditionContainer;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> AllowedPointProviders;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> RegisteredPointProviders;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAthenaLivingWorldEventData>> RuntimeCreatedEventDatas;

	UPROPERTY(Transient)
	TSoftObjectPtr<UFortAthenaLivingWorldEncounter> EncounterDefinition;

	UPROPERTY(Transient)
	TObjectPtr<AActor> ActorDensityReservoir;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaLivingWorldEncounterInstance", meta=(AllowPrivateAccess="TRUE"))
	TArray<TObjectPtr<AActor>> SpawnedActors;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaLivingWorldEncounterInstance", meta=(AllowPrivateAccess="TRUE"))
	int32 CurrentStageIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaLivingWorldEncounterInstance", meta=(AllowPrivateAccess="TRUE"))
	int32 CurrentStageMaxActorCount;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaLivingWorldEncounterInstance", meta=(AllowPrivateAccess="TRUE"))
	bool bIsPaused;

};

