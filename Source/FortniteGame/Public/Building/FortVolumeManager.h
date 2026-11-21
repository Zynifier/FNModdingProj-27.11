// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Building/FortVolumeUsers.h"
#include "Creative/FortCreativeTypes.h"
#include "Evaluator/FortEvaluator.h"
#include "FortVolumeManager.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortMinigame;
class AFortPawn;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerState;
class AFortVolume;
class AFortVolumeManager;
class APawn;
class APlayerState;
class UActorComponent;
class UCreativeAssetCostDirectory;
class UFortCreativeGeneralThrottleManager;
class UFortPlaysetItemDefinition;
class UObject;
class UPrimitiveComponent;
enum class ESpatialLoadingState : uint8;
enum class EVolumeValidityResult : uint8;

UENUM(BlueprintType)
enum class EVolumeValidityResult : uint8
{
	Valid = 0,
	Invalid = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClientEnterVolume, APlayerState*, Client, AFortVolume*, Volume);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClientExitVolume, APlayerState*, Client, AFortVolume*, Volume);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClientStartExitingVolume, APlayerState*, Client, AFortVolume*, Volume);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClientStopExitingVolume, APlayerState*, Client, AFortVolume*, Volume);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnClientVolumeRestrictionStateChanged, AFortVolume*, Volume, bool, bRestrictionEnabled);

UCLASS(Config=Game, DefaultConfig, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortVolumeManager : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="VolumeManager")
	bool ActorsAreInSameVolume(const AActor* Left, const AActor* Right) const;

	UFUNCTION()
	bool AreIslandsLoading() const;

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	static bool CanCreatePlayset(AFortPlayerPawn* Thrower, const FVector& StartLocation, const FRotator& PlaysetRotation, UFortPlaysetItemDefinition* NewPlayset);

	UFUNCTION()
	void DecrementUserIslandLoading();

	UFUNCTION()
	void DestroyBuildingWhenNotInSameVolumeAsPlayerController(AFortPlayerController* PlayerController, ABuildingActor* TestBuildingActor);

	UFUNCTION()
	FEvaluationResult DoesThermometerHaveBudgetForActor(const AActor* InstigatorActor, AActor* TestActor, const FVector& Location, const FRotator& Rotation) const;

	UFUNCTION(BlueprintCallable, Category="VolumeManager")
	void EnterReadOnlyForVolume(AFortVolume* Volume);

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	TArray<AController*> GetAllPlayersInVolume(AFortVolume* Volume) const;

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	TArray<APlayerState*> GetAllPlayerStatesInVolume(const AFortVolume* Volume) const;

	UFUNCTION(BlueprintCallable, Category="VolumeManager")
	static AFortMinigame* GetMinigameForPlayerState(const APlayerState* PlayerState);

	UFUNCTION(BlueprintCallable, Category="VolumeManager")
	static AFortMinigame* GetMinigameForVolume(const AActor* Volume);

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	AFortMinigame* GetMinigameFromVolume(const AActor* Actor) const;

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	AFortVolume* GetNearestIslandVolumeForLocation(const FVector Location, FVector& OutNearestPoint, const float Padding = 0.000000f) const;

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	const AFortPlayerState* GetPlayerStateFromNetID(const FUniqueNetIdRepl& UniqueNetId) const;

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	AFortVolume* GetVolumeForActor(const AActor* Actor) const;

	UFUNCTION(BlueprintCallable, Category="VolumeManager")
	AFortVolume* GetVolumeForActorWithComponent(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentType, TArray<UActorComponent*>& OutComponents, const bool bUseActorBounds = true);

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	AFortVolume* GetVolumeForLocation(FVector Location) const;

	UFUNCTION(BlueprintCallable, Category="VolumeManager")
	AFortVolume* GetVolumeForLocationWithComponent(FVector Location, const TSubclassOf<UActorComponent>& ComponentType, TArray<UActorComponent*>& OutComponents);

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	AFortVolume* GetVolumeForPlayerState(const APlayerState* PlayerState) const;

	UFUNCTION(BlueprintCallable, Category="Volume", meta=(ExpandEnumAsExecs="OutIsValid", WorldContext="WorldContextObject"))
	static void GetVolumeManager(const UObject* WorldContextObject, AFortVolumeManager*& OutVolumeManager, EVolumeValidityResult& OutIsValid);

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	int32 GetVolumePlayerCount(const AFortVolume* Volume) const;

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	bool GetVolumesForActor(const AActor* Actor, TArray<AFortVolume*>& Volumes, const bool bUseActorBounds = true) const;

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	bool GetVolumesForLocation(FVector Location, TArray<AFortVolume*>& Volumes) const;

	UFUNCTION()
	void HandlePlayerPawnPossessed(APawn* Pawn);

	UFUNCTION()
	void IncrementUserIslandLoading();

	UFUNCTION(BlueprintCallable, Category="VolumeManager")
	void ResetVolumeAndLevelRecord(AFortVolume* Volume, AFortPlayerController* RequestingFortPC);

	UFUNCTION(BlueprintCallable, Category="VolumeManager")
	AFortVolume* SpawnVolume(const TSubclassOf<AFortVolume>& VolumeActor, AActor* VolumeOwner, const UFortPlaysetItemDefinition* Playset, const FVector& Location, const FRotator& Rotation);

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	bool VolumeContainsUser(const APlayerState* PlayerState, const AFortVolume* Volume) const;

	UFUNCTION(BlueprintPure, Category="VolumeManager")
	bool WillVolumeDeleteAfterActorSpawn(AFortVolume* Volume) const;

	UPROPERTY(BlueprintAssignable)
	FOnClientEnterVolume OnClientEnterVolume;

	UPROPERTY(BlueprintAssignable)
	FOnClientExitVolume OnClientExitVolume;

	UPROPERTY(BlueprintAssignable)
	FOnVolumeStateChanged OnVolumeStateChanged;

	UPROPERTY(BlueprintReadOnly, Category="FortVolumeManager")
	TObjectPtr<UFortCreativeGeneralThrottleManager> FortCreativeGeneralThrottleManager;

	UPROPERTY(BlueprintAssignable)
	FOnClientVolumeRestrictionStateChanged OnClientVolumeUGCViewableStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnClientVolumeRestrictionStateChanged OnServerVolumeUGCViewableStateChanged;

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortVolume>> VolumeObjects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="VolumeManager")
	TSoftObjectPtr<UCreativeAssetCostDirectory> AssetCostDirectory;

private:
	UFUNCTION()
	void AddOrRemovePawn(AFortPawn* FortPawn);

	UFUNCTION()
	void AddOrRemovePawnAfterVehicleChange(AFortPlayerPawn* FortPawn, AActor* NewVehicle, AActor* OldVehicle);

	UFUNCTION()
	void AttemptAddToVolumeAfterDelay(AActor* Actor);

	UFUNCTION()
	void HandleActorHealthChanged(AActor* Actor, float NewHealth);

	UFUNCTION()
	void HandleSpatialLoadingStateChanged(ESpatialLoadingState NewState, AFortVolume* Volume);

	UFUNCTION()
	void HandleVolumeReset(AFortVolume* VolumeResetting);

	UFUNCTION()
	void RemovePawnNotRespawningInsideVolume(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(Replicated)
	FFortVolumeActiveUsers VolumeActivePlayers;

	UPROPERTY(Replicated)
	uint8 bInSpawningStartup : 1;

	UPROPERTY(Transient)
	TArray<FVolumePlayerStateInfo> PendingPlayers;

};

