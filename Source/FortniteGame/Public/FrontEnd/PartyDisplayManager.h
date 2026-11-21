// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/OnlineReplStructs.h"
#include "InputCoreTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/Guid.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "PartyDisplayManager.generated.h"

class AActor;
class AFortPlayerPawn;
class APartyDisplayManager;
class UFortAsyncAction_PartyDisplayManager_SetupPrefabVisuals;
class UFortItem;
class UFortItemDefinition;
class UMaterialInstance;
class UMeshComponent;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FClickedPartyPlayerDelegate, int32, PlayerIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPrefabForCurrentlyDisplayedItemChanged, AActor*, NewPrefab, UFortItem*, NewItem);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPrefabForCurrentlyDisplayedItemReady, AFortPlayerPawn*, Pawn);

USTRUCT()
struct FHeroSlotInfo
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(ChildCanTick))
class APartyDisplayManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="PartyDisplayManager")
	void BeginLoadingAssetsForItem(UFortItem* ItemToView, const TArray<TSoftObjectPtr<UObject>>& AssetsToLoad, const FGuid& RequestId);

	UFUNCTION(BlueprintImplementableEvent)
	void CharacterCustomizationFinished(AFortPlayerPawn* Pawn);

	UFUNCTION(BlueprintPure, Category="PartyDisplayManager")
	FFortAthenaLoadout GetCosmeticLoadoutForCurrentDisplayedItem() const;

	UFUNCTION(BlueprintCallable, Category="Party Display Manager")
	AFortPlayerPawn* GetHeroPlayerPawnForCurrentDisplayedItem();

	UFUNCTION(BlueprintImplementableEvent, Category="PartyDisplayManager")
	void GetMeshForCurrentDisplayedItem(UMeshComponent*& OutDisplayedMesh);

	UFUNCTION(BlueprintPure)
	bool GetPartyMemberIndexByPlayerPawn(const AFortPlayerPawn* PlayerPawn, int32& OutPlayerIndex) const;

	UFUNCTION(BlueprintImplementableEvent, Category="PartyDisplayManager")
	AActor* GetPrefabActorForCurrentDisplayedItem() const;

	UFUNCTION()
	void HandleCharacterCustomizationFinished(AFortPlayerPawn* Pawn);

	UFUNCTION(BlueprintCallable, Category="PartyDisplayManager")
	void HandleItemsShown(const TArray<UFortItem*>& ItemShown, const FGuid& RequestId);

	UFUNCTION(BlueprintImplementableEvent, Category="PartyDisplayManager")
	void HandleLoadingAssetsForItemCompleted(UFortItem* ItemWhoseAssetsWereLoaded, const TArray<UObject*>& LoadedAssets, const FGuid& RequestId);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMeshLODStreamingFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerPawnAddedToLobby(AFortPlayerPawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent, Category="PartyDisplayManager")
	void PlayEvolutionEffect();

	UFUNCTION(BlueprintImplementableEvent, Category="PartyDisplayManager")
	void PlayLevelUpEffect();

	UFUNCTION(BlueprintImplementableEvent)
	void ResOutPawnFromLobby(AFortPlayerPawn* Pawn, int32 PartyIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="PartyDisplayManager")
	void SetupPrefabVisuals();

	UFUNCTION(BlueprintImplementableEvent, Category="PartyDisplayManager")
	void ShowItem(const UFortItem* ItemToView, const FGuid& RequestId);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	TArray<TObjectPtr<AActor>> PlacementActors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	TObjectPtr<AActor> VaultPlacementActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	TObjectPtr<AActor> VaultWeaponPlacementActor;

	UPROPERTY(BlueprintAssignable, Category="PartyDisplayManager")
	FClickedPartyPlayerDelegate OnClickedPartyPlayer;

	UPROPERTY(BlueprintAssignable, Category="PartyDisplayManager")
	FClickedPartyPlayerDelegate OnBeginCursorOverPartyPlayer;

	UPROPERTY(BlueprintAssignable, Category="PartyDisplayManager")
	FClickedPartyPlayerDelegate OnEndCursorOverPartyPlayer;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="PartyDisplayManager")
	FOnPrefabForCurrentlyDisplayedItemReady OnItemDisplayReady;

	UPROPERTY(BlueprintAssignable, Category="PartyDisplayManager")
	FOnPrefabForCurrentlyDisplayedItemChanged OnPrefabForCurrentlyDisplayedItemChanged;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Material FX")
	TObjectPtr<UMaterialInstance> PlayerInMatchHoloMaterial;

	UPROPERTY(BlueprintReadWrite, Category="Properties")
	bool IsPlayingCelebrateFX;

protected:
	UFUNCTION(BlueprintPure)
	FUniqueNetIdRepl GetPlayerIdFromPartyMemberIndex(int32 PartyMemberIndex) const;

	UFUNCTION(BlueprintCallable)
	void NotifyPrefabChanged(AActor* PrefabActor, UFortItem* CurrentItem);

	UFUNCTION()
	void OnPawnBeginCursorOver(AActor* TouchedActor);

	UFUNCTION()
	void OnPawnClicked(AActor* TouchedActor, FKey ButtonPressed);

	UFUNCTION()
	void OnPawnEndCursorOver(AActor* TouchedActor);

	UFUNCTION()
	void OnPawnTouchReleased(ETouchIndex::Type FingerIndex, AActor* TouchedActor);

	UPROPERTY(Transient)
	TMap<int32, FHeroSlotInfo> HeroPlayerPawns;

	UPROPERTY()
	FFortAthenaLoadout CurrentlyDisplayedCosmeticLoadout;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> CurrentContentOnDemandItemDefs;

};

UCLASS()
class UFortAsyncAction_PartyDisplayManager_SetupPrefabVisuals : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegate, UFortItem*, Item, FGuid, RequestId);

public:
	UFUNCTION(BlueprintCallable, Category="PartyDisplayManager", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_PartyDisplayManager_SetupPrefabVisuals* SetupPrefabVisuals(const APartyDisplayManager* Target, const UFortItem* Item, const FGuid& RequestId);

	UPROPERTY(BlueprintAssignable)
	FDelegate Completed;

private:
	UFUNCTION()
	void OnItemDisplayReady(AFortPlayerPawn* Pawn);

	UFUNCTION()
	void OnPreviousCustomizationComplete(AFortPlayerPawn* Pawn);

	UFUNCTION()
	void OnRequestedCustomizationComplete(AFortPlayerPawn* Pawn);

	UPROPERTY()
	TObjectPtr<UFortItem> Item;

};

