// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory/FortInventorySerializationTypes.h"
#include "Inventory/FortPersistenceTypes.h"
#include "FortCreativePersistenceComponent.generated.h"

class AFortMinigame;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class AFortPlayerState;
class APlayerState;
class UFortItemDefinition;
class UFortMinigameStatFilter;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDataLoaded, AFortPlayerControllerAthena*, FortPlayerController);

UCLASS(Config=Game, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCreativePersistenceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearAllPlayersSpecificData(AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ClearPlayerRelatedData(APlayerState* PlayerState, AFortMinigame* Minigame) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ClearPlayerSpecificData(APlayerState* PlayerState, AFortMinigame* Minigame) const;

	UFUNCTION(BlueprintCallable)
	void DeinitializeAutoSave();

	UFUNCTION(BlueprintCallable)
	void DisableAutoSave(AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable)
	void EnableAutoSave(AFortMinigame* Minigame);

	UFUNCTION(BlueprintPure)
	static float GetAutoSaveInterval();

	UFUNCTION(BlueprintPure)
	TArray<UFortMinigameStatFilter*> GetPersistentStatFilterList() const;

	UFUNCTION(BlueprintCallable)
	void InitializeAutoSave(AFortMinigame* Minigame, bool bShouldEnableAutoSave);

	UFUNCTION(BlueprintCallable)
	void LoadPlayerDataNeededAfterSpawn(AFortPlayerState* FortPlayerState, AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable)
	void LoadPlayerDataNeededBeforeSpawn(AFortPlayerState* FortPlayerState, AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable)
	void LoadPlayerRelatedData(APlayerState* PlayerState, AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable)
	void LoadPlayersDataNeededAfterSpawn(AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable)
	void LoadPlayersDataNeededBeforeSpawn(AFortMinigame* Minigame);

	UFUNCTION(BlueprintCallable)
	void OnMinigameEnded(AFortMinigame* Minigame);

	UFUNCTION()
	void OnPlayerPawnFinishedTeleported(AFortPlayerPawn* FortPlayerPawn);

	UFUNCTION(BlueprintCallable)
	void RemovePendingToApplyData(AFortPlayerState* FortPlayerState, bool bShowsLog = false);

	UFUNCTION(BlueprintCallable)
	void StoreAllMinigamePlayersData(AFortMinigame* Minigame, bool bPostGameSave = false);

	UFUNCTION(BlueprintCallable)
	bool StorePlayerRelatedData(APlayerState* PlayerState, AFortMinigame* Minigame, bool bPostGameSave = false);

	UPROPERTY(BlueprintAssignable)
	FOnPlayerDataLoaded OnPlayerDataLoaded;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativePersistenceComponent")
	FFortInventory_SaveEntrySettings SaveEntrySettings;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativePersistenceComponent")
	FSaveRestrictions SaveRestrictions;

	UPROPERTY(Config)
	TArray<TSoftClassPtr<UFortItemDefinition>> ConfigurableItemClassesNotToSave;

};

