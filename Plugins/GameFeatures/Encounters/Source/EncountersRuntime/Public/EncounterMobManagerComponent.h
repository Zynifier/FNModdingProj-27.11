// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "EncounterMobManagerData.h"
#include "EncounterMobManagerComponent.generated.h"

class AActor;
class AController;
class ALivingWorldEncounterPrefab;
class UPrimitiveComponent;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UEncounterMobManagerComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEncounterActorDead, FGameplayTag, MobIdentifier, AActor*, DamagedActor, AActor*, DamageCauser);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEncounterActorSpawned, FGameplayTag, MobIdentifier, AActor*, SpawnedActor);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterEnded, FGameplayTag, MobIdentifier);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterPaused, FGameplayTag, MobIdentifier);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterResumed, FGameplayTag, MobIdentifier);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterStarted, FGameplayTag, MobIdentifier);

public:
	UEncounterMobManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Mob Encounter | Event")
	void EndAndCleanupAllMobEncounters();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Mob Encounter | Event")
	void EndMobEncounter(const FGameplayTag& MobIdentifier);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Mob Encounter | Event")
	void PauseMobEncounter(const FGameplayTag& MobIdentifier);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Mob Encounter | Event")
	void ResumeMobEncounter(const FGameplayTag& MobIdentifier);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Mob Encounter | Event")
	bool StartMobEncounter(const FGameplayTag& MobIdentifier);

	UPROPERTY(BlueprintAssignable, Category="Mob Encounter | Delegate")
	FOnEncounterStarted OnEncounterStarted;

	UPROPERTY(BlueprintAssignable, Category="Mob Encounter | Delegate")
	FOnEncounterPaused OnEncounterPaused;

	UPROPERTY(BlueprintAssignable, Category="Mob Encounter | Delegate")
	FOnEncounterResumed OnEncounterResumed;

	UPROPERTY(BlueprintAssignable, Category="Mob Encounter | Delegate")
	FOnEncounterActorSpawned OnEncounterActorSpawned;

	UPROPERTY(BlueprintAssignable, Category="Mob Encounter | Delegate")
	FOnEncounterActorDead OnEncounterActorDead;

	UPROPERTY(BlueprintAssignable, Category="Mob Encounter | Delegate")
	FOnEncounterEnded OnEncounterEnded;

protected:
	UPROPERTY(EditAnywhere, Category="Mob Encounter | Data")
	TArray<FEncounterMobSpawnData> MobEncounterSpawnData;

	UPROPERTY(EditAnywhere, Category="Mob Encounter | Spawn")
	FEncounterMobSpawnInfo DefaultMobSpawnInfo;

	UPROPERTY(EditAnywhere, Category="Mob Encounter | Density")
	FScalableFloat LWMDensityWeight;

	UPROPERTY(EditAnywhere, Category="Mob Encounter | Density")
	FScalableFloat LWMDensityRange;

private:
	UFUNCTION()
	void OnMobActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnMobActorSpawn(AActor* SpawnedActor);

	UFUNCTION()
	void OnMobPawnEndPlay(AActor* Mob, EEndPlayReason::Type EndPlayReason);

	UPROPERTY(Transient)
	TArray<FEncounterMobInstance> SpawnedMobs;

	UPROPERTY(Transient)
	TWeakObjectPtr<ALivingWorldEncounterPrefab> EncounterPrefab;

};

