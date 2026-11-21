// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CollisionProfile.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "Items/FortItemEntry.h"
#include "FortAthenaSupplyDrop.generated.h"

class AAthenaFillFloor;
class AController;
class AFortGameModePickup;
class AFortPawn;
class AFortPickup;
class AFortPlayerController;
class UAudioComponent;
class UFortSpectateClickableMapIcon;
class UFortWorldItemDefinition;
class USceneComponent;
class USoundCue;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAthenaSupplyDrop : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="GroundCollision")
	FVector FindGroundLocationAt(const FVector& InLocation);

	UFUNCTION(BlueprintCallable, Category="SpawnData")
	void GetSupplyDropSpawnData(float& MinSpawnHeight, float& MaxSpawnHeight);

	UFUNCTION(BlueprintCallable, Category="SpawnData")
	void GetSupplyDropSpeedData(float& MinSpeed, float& MaxSpeed);

	UFUNCTION(BlueprintPure, Category="GroundCollision")
	bool GroundTrace(const FVector& TraceStart, const FVector& TraceEnd, FHitResult& OutHit) const;

	UFUNCTION(BlueprintPure)
	bool IsClientCollisionReductionEnabled() const;

	UFUNCTION(BlueprintPure)
	bool IsPlayingAReplay() const;

	UFUNCTION()
	void OnDespawnDueToStorm();

	UFUNCTION(BlueprintCallable)
	void SpawningLootOnDestruction(AController* EventInstigator);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GroundCollision")
	FCollisionProfileName GroundCollsionProfile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundCue> WaveSpawnSoundCue;

protected:
	UFUNCTION(BlueprintCallable)
	void EnableArrivedNearDestinationEvent(USceneComponent* CrateComponent, USceneComponent* DestinationComponent, float EventDistance);

	UFUNCTION()
	void HandlePickedUpForAnalyticsEvent(AFortPickup* SelfActor, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* WorldItemDefinition, FVector PickupLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnArrivedNearDestination();

	UFUNCTION()
	void OnCheckForBeingInStorm();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void OnLootSpawned();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTouchedFillFloor(AAthenaFillFloor* FillFloorActor);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly, Category="Analytics")
	void SendSpawnLootAnalytics(AFortPlayerController* FortPC, const TArray<FFortItemEntry>& ItemsToSpawn) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetLootTableNameOverride(FName TableNameToUse);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	AFortGameModePickup* SpawnGameModePickup(UFortWorldItemDefinition* ItemDefinition, TSubclassOf<AFortGameModePickup> PickupClass, int32 NumberToSpawn, AFortPawn* TriggeringPawn, FVector Position, FVector Direction);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	AFortPickup* SpawnPickup(UFortWorldItemDefinition* ItemDefinition, int32 NumberToSpawn, AFortPawn* TriggeringPawn, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000));

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	AFortPickup* SpawnPickupFromItemEntry(UFortWorldItemDefinition* ItemDefinition, const FFortItemEntry& InItemEntry, int32 NumberToSpawn, AFortPawn* TriggeringPawn, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaSupplyDrop")
	FName LootTableNameOverride;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaSupplyDrop")
	FHitResult LastGroundLocationHitResult;

	UPROPERTY(EditDefaultsOnly, Category="GroundCollision")
	float SpawnOffsetZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TObjectPtr<USoundCue> SearchingSoundCueLoop;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	bool bReplicateLongUseNotifies;

	UPROPERTY(EditDefaultsOnly, Category="Ability System")
	bool bDisableAbilitySystemReplication;

	UPROPERTY(Transient)
	int32 CachedSpecialActorIdx;

	UPROPERTY(Transient, Replicated)
	FName SpecialActorID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaSupplyDrop")
	FScalableFloat InStormDespawnTimeInSeconds;

	UPROPERTY(Transient)
	float CachedInStormDespawnTimeInSeconds;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> LongInteractAudioComponent;

	UPROPERTY(EditDefaultsOnly, Export, Category="Spectate", meta=(EditInline="true"))
	TObjectPtr<UFortSpectateClickableMapIcon> SpectatorMapIcon;

private:
	UFUNCTION()
	void OnRep_NumPlayersInteracting();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_NumPlayersInteracting)
	int32 NumPlayersInteracting;

	UPROPERTY(Config)
	bool bVisualizePlayerInteractionChanges;

};

