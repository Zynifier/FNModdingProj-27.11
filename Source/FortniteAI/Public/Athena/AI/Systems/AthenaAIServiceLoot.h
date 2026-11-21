// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/Systems/AthenaAIService.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "AthenaAIServiceLoot.generated.h"

class AActor;
class ABuildingProp;
class AFortAthenaSupplyDrop;
class AFortPickup;
class UDataRegistry;
class UDataTable;
class UFortWorldItem;

USTRUCT()
struct FCachedSupplyDrop
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	AFortAthenaSupplyDrop* SupplyDrop;

	UPROPERTY(Transient)
	bool bInOctree;

	UPROPERTY(Transient)
	FVector LastLocation;

};

USTRUCT()
struct FClusterLoot
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FBox ClusterBox;

	UPROPERTY(Transient)
	int32 Weight;

};

USTRUCT()
struct FFortBotClusterLootWeightDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot Clustering")
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loot Clustering", meta=(UIMin="0"))
	int32 Weight;

};

USTRUCT()
struct FMovingLootInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector LastLocationInOctree;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UAthenaAIServiceLoot : public UAthenaAIService
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void K2_AddGameplayTagToLoot(const AActor* LootActor, const FGameplayTag& GameplayTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	void K2_RemoveGameplayTagFromLoot(const AActor* LootActor, const FGameplayTag& GameplayTag);

private:
	UFUNCTION()
	void UpdateMovingLoots();

	UFUNCTION()
	void UpdateSupplyDropStatus();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Octree", meta=(AllowPrivateAccess="true"))
	FVector LootOctreeCenter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Octree", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootOctreeRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot", meta=(AllowPrivateAccess="true"))
	FScalableFloat SupplyDropStatusUpdateRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot", meta=(AllowPrivateAccess="true"))
	FScalableFloat RemoveInvalidChestFromOctreeProbability;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot", meta=(AllowPrivateAccess="true"))
	FScalableFloat MovingLootTrackingEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot", meta=(AllowPrivateAccess="true"))
	FScalableFloat MovingLootUpdateRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot", meta=(AllowPrivateAccess="true"))
	FScalableFloat MovingLootOctreeUpdateDistanceThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Harvest", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<ABuildingProp>> HarvestableActorClassList;

	UPROPERTY(EditDefaultsOnly, Category="Loot Clustering", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootClusteringEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Loot Clustering", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootClusteringNeighborDistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="Loot Clustering", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootClusteringNeighborhoodCountMin;

	UPROPERTY(EditDefaultsOnly, Category="Loot Clustering")
	TObjectPtr<UDataRegistry> LootClusteringItemWeightDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Loot Clustering", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootClusteringDefaultWeight;

	UPROPERTY(EditDefaultsOnly, Category="Loot Clustering", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootClusteringExpandByBoxX;

	UPROPERTY(EditDefaultsOnly, Category="Loot Clustering", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootClusteringExpandByBoxY;

	UPROPERTY(EditDefaultsOnly, Category="Loot Clustering", meta=(AllowPrivateAccess="true"))
	FScalableFloat LootClusteringExpandByBoxZ;

	UPROPERTY(Transient)
	TMap<TWeakObjectPtr<AFortPickup>, FMovingLootInfo> MovingLoots;

	UPROPERTY(Transient)
	TArray<FCachedSupplyDrop> CachedSupplyDrops;

	UPROPERTY(Transient)
	UFortWorldItem* CachedWorldItem;

	UPROPERTY(EditDefaultsOnly, Category="Building Containers")
	UDataTable* BotBuildingContainerExcludeListDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Loot Clustering")
	EAthenaGamePhaseStep LootClusterCalculationGamePhase;

	UPROPERTY(Transient)
	TArray<FFortBotClusterLootWeightDataTableRow> CachedLootClusteringItemWeightTable;

};

