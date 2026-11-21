// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "Items/FortVictoryCrownAccountItem.h"
#include "FortControllerComponent_VictoryCrowns.generated.h"

class AController;
class AFortPlayerControllerAthena;
class APawn;
class UDataTable;
class UFortItem;
class UFortMontageItemDefinitionBase;
class UFortVictoryCrownAccountItemDefinition;
class UFortWorldItem;
class UFortWorldItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHasWonCrownInMatch);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHasWonRoyalRoyale);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVictoryCrownStatusChanged, AFortPlayerControllerAthena*, FortPlayerControllerAthena, const UFortItem*, CrownItem);

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_VictoryCrowns : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly)
	bool AuthorityHasDroppedCrownItem(const UFortItem* CrownItem) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly)
	bool AuthorityHasHeldCrownItem(const UFortItem* CrownItem) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly)
	bool AuthorityHasSquadDroppedCrownItem(const UFortItem* CrownItem) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly)
	bool AuthorityHasSquadHeldCrownItem(const UFortItem* CrownItem) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly)
	bool AuthoritySquadHasSeenCrownItem(const UFortItem* CrownItem, const bool bDropped) const;

	UFUNCTION(Exec)
	void DebugForceSetRoyalRoyaleAchievedCount(int32 NewRoyalRoyaleCount);

	UFUNCTION(BlueprintPure)
	const UFortWorldItem* GetCrownInPlayerInventory() const;

	UFUNCTION(BlueprintPure)
	const int32 GetRoyalRoyaleAchievedCount() const;

	UFUNCTION(BlueprintPure)
	const int32 GetVictoryCrownsBestowedCount() const;

	UFUNCTION(BlueprintPure)
	bool HasWonCrownInMatch() const;

	UFUNCTION(BlueprintPure)
	bool HasWonRoyalRoyale() const;

	UFUNCTION(BlueprintPure)
	bool IsCrownInPlayerInventory() const;

	UPROPERTY(BlueprintAssignable)
	FOnVictoryCrownStatusChanged OnVictoryCrownStatusChanged;

	UPROPERTY(BlueprintAssignable)
	FOnHasWonCrownInMatch OnHasWonCrownInMatch;

	UPROPERTY(BlueprintAssignable)
	FOnHasWonRoyalRoyale OnHasWonRoyalRoyale;

protected:
	UFUNCTION()
	void HandleEnterAircraft();

	UFUNCTION()
	void HandleExitAircraft(AController* ExitingController);

	UFUNCTION()
	void HandlePawnChanged(APawn* OldPawn, APawn* NewPawn);

	UFUNCTION()
	void OnEnterAircraft(AController* EnteringController);

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_VictoryCrowns")
	TSoftObjectPtr<UFortWorldItemDefinition> CrownInventoryItemClass;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_WonCrownInMatch)
	bool bWonCrownInMatch;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_WonRoyalRoyale)
	bool bWonRoyalRoyale;

private:
	UFUNCTION()
	void CacheAccountItemData();

	UFUNCTION()
	void OnAthenaProfileInitialized();

	UFUNCTION()
	void OnRep_VictoryCrownAccountData();

	UFUNCTION()
	void OnRep_WonCrownInMatch();

	UFUNCTION()
	void OnRep_WonRoyalRoyale();

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_VictoryCrowns")
	TObjectPtr<UFortVictoryCrownAccountItemDefinition> VictoryCrownAccountItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_VictoryCrowns")
	TSoftObjectPtr<UFortMontageItemDefinitionBase> RoyalRoyaleEmoteItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_VictoryCrowns", meta=(RowType="/Script/VictoryCrownsRuntime.VictoryCrownPlaylistData"))
	TObjectPtr<UDataTable> VictoryCrownPlaylistData;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_VictoryCrowns")
	FGameplayTagContainer SourceTagsForRoyalRoyale;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_VictoryCrownAccountData)
	FVictoryCrownAccountData VictoryCrownAccountData;

	UPROPERTY(EditDefaultsOnly, Category="FortControllerComponent_VictoryCrowns")
	FScalableFloat InitialGrantDelay;

	UPROPERTY(Transient)
	bool bKillFeedBroadcastReady;

};

