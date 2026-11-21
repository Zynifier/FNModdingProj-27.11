// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "Components/FortControllerComponent.h"
#include "Items/FortPlayerAugmentsAccountItem.h"
#include "FortControllerComponent_PlayerAugmentPersistence.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerStateAthena;
class UFortCollectionData;
class UFortCollectionDataPlayerAugment;
class UFortCollectionsDataTable;
class UFortPlayerAugmentItemDefinition;

USTRUCT(BlueprintType)
struct FCarryOverPlayerAugment
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="CarryOverPlayerAugment")
	FPrimaryAssetId AugmentAssetId;

	UPROPERTY(BlueprintReadWrite, Category="CarryOverPlayerAugment")
	FName SourcePlaylistName;

};

USTRUCT(BlueprintType)
struct FPlayerAugmentLockStatus
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PlayerAugmentLockStatus")
	TObjectPtr<UFortPlayerAugmentItemDefinition> PlayerAugmentItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="PlayerAugmentLockStatus")
	bool bIsLocked;

	UPROPERTY(BlueprintReadOnly, Category="PlayerAugmentLockStatus")
	bool bWasCollectedInThisMatch;

	UPROPERTY(BlueprintReadOnly, Category="PlayerAugmentLockStatus")
	TObjectPtr<AFortPlayerStateAthena> SharedFromPlayer;

};

USTRUCT()
struct FReplicatedSharedPlayerAugment
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PlayerAugmentIndex;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerStateAthena> SharedFromPlayer;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_PlayerAugmentPersistence : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AuthoritySetCarryOverPlayerAugments(const TArray<FCarryOverPlayerAugment>& NewCarryOverPlayerAugments);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AuthoritySetRollCountSinceLastRandomUnlock(int32 NewRollCount);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AuthorityUnlockPlayerAugment(UFortPlayerAugmentItemDefinition* PlayerAugmentToUnlock);

	UFUNCTION(BlueprintPure)
	void GetCarryOverPlayerAugments(TArray<FCarryOverPlayerAugment>& OutCarryOverPlayerAugments) const;

	UFUNCTION(BlueprintPure)
	void GetLockedList(TArray<FPlayerAugmentLockStatus>& OutLockedList, bool bIncludeSharedAugments) const;

	UFUNCTION(BlueprintPure)
	FPlayerAugmentLockStatus GetLockStatus(UFortPlayerAugmentItemDefinition* PlayerAugmentItemDefinition) const;

	UFUNCTION(BlueprintPure)
	void GetLockStatusForAll(TArray<FPlayerAugmentLockStatus>& OutLockStatusArray) const;

	UFUNCTION(BlueprintPure)
	int32 GetRollCountSinceLastRandomUnlock() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortControllerComponent_PlayerAugmentPersistence")
	FScalableFloat Enabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortControllerComponent_PlayerAugmentPersistence")
	FScalableFloat LockMissingCollectionAugmentsEnabled;

private:
	UFUNCTION()
	void HandleCollectionDataLoaded(TSoftObjectPtr<UFortCollectionData> BaseCollectionDataSoftPtr);

	UFUNCTION()
	void HandleCollectionDataTableLoaded(TSoftObjectPtr<UFortCollectionsDataTable> CollectionsDataTableSoftPtr);

	UFUNCTION()
	void HandleMcpProfilesInitialized();

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerControllerAthena> PlayerController;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionDataPlayerAugment> CollectionData;

	UPROPERTY(VisibleInstanceOnly, Transient, Replicated, Category="FortControllerComponent_PlayerAugmentPersistence")
	FPlayerAugmentsPersistenceData LivePlayerAugmentsPersistenceData;

	UPROPERTY(VisibleInstanceOnly, Transient, Category="FortControllerComponent_PlayerAugmentPersistence")
	TSet<UFortPlayerAugmentItemDefinition*> AugmentsCollectedThisMatch;

	UPROPERTY(VisibleInstanceOnly, Transient, Replicated, Category="FortControllerComponent_PlayerAugmentPersistence")
	TArray<FReplicatedSharedPlayerAugment> ReplicatedSharedPlayerAugments;

};

