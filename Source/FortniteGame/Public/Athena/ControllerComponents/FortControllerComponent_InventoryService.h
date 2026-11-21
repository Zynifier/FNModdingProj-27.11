// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_InventoryService.generated.h"

class AFortGameStateAthena;
class AFortPlayerControllerGameplay;
class AFortPlayerStateAthena;
class IFortInventoryOwnerInterface;
class UCurveTable;
class UFortControllerComponent_InventoryService;
class UFortItemDefinition;
class UFortPlaylist;
class UFortResourceItemDefinition;

UENUM(BlueprintType)
enum class EStashInventoryServiceSyncState : uint8
{
	Uninitialized = 0,
	Syncing = 1,
	Ready = 2,
};

USTRUCT(BlueprintType)
struct FFortGlobalCurrencyStash
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortGlobalCurrencyStash")
	int32 Count;

};

USTRUCT()
struct FGlobalCurrencyPhaseEndData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector PlayerPosition;

	UPROPERTY()
	float ServerMatchTime;

	UPROPERTY()
	int32 CurrencyBalance;

};

USTRUCT()
struct FGlobalCurrencyTransactionData
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	float ServerTime;

	UPROPERTY(NotReplicated)
	int32 Amount;

	UPROPERTY(NotReplicated)
	FString SourceType;

};

USTRUCT()
struct FGlobalCurrencyTrackedData
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	TArray<FGlobalCurrencyTransactionData> TransactionData;

	UPROPERTY(NotReplicated)
	TArray<FGlobalCurrencyPhaseEndData> CurrencyDataPerPhase;

	UPROPERTY()
	int32 TotalCurrencyEarnedInMatch;

};

USTRUCT()
struct FRepGlobalCurrencyStash
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EStashInventoryServiceSyncState SyncState;

	UPROPERTY()
	FFortGlobalCurrencyStash Currency;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_InventoryService : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Stash | Global Currency")
	static UCurveTable* GetDefaultCurrencyPayoutTable();

	UFUNCTION(BlueprintCallable, Category="Stash | Global Currency")
	static UFortResourceItemDefinition* GetDefaultGlobalCurrencyItemDefinition();

	UFUNCTION(BlueprintCallable, Category="Inventory Service Component")
	static UFortControllerComponent_InventoryService* GetInventoryServiceComponent(const AFortPlayerControllerGameplay* FortPC);

	UFUNCTION(BlueprintCallable, Category="Stash | Global Currency")
	static bool IsGlobalCurrencyWidgetEnabled();

protected:
	UPROPERTY(Transient)
	bool bBoundToRegisteredPlayerInfo;

private:
	UFUNCTION()
	void HandleOnItemCountChanged(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, UFortItemDefinition* Definition, int32 Delta);

	UFUNCTION()
	void HandlePlacementChanged(AFortPlayerStateAthena* FortPlayerState, int32 NewPlacement);

	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(Transient)
	FRepGlobalCurrencyStash GlobalCurrencyData;

	UPROPERTY(EditDefaultsOnly, Category="Stash | Global Currency")
	FScalableFloat ShouldDropCurrencyOnDeath;

	UPROPERTY(EditDefaultsOnly, Category="Stash | Global Currency")
	FScalableFloat NumDeathsThatDropCurrency;

	UPROPERTY(EditDefaultsOnly, Category="Stash | Global Currency")
	FScalableFloat InventoryServiceEnabled;

	UPROPERTY(Replicated)
	FGlobalCurrencyTrackedData GlobalCurrencyTrackedData;

};

