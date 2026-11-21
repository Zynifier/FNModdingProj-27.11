// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "FortSupplyDropInfo.generated.h"

class AFortAthenaSupplyDrop;

UENUM(BlueprintType)
enum class ESupplyDropItemTrackType : uint8
{
	// track special actors in the SpecialActorSystem located in the GameState

	SpecialActors = 0,
};

UENUM(BlueprintType)
enum class ESupplyDropSpawnType : uint8
{
	// spawning is automatic and based on data configured on a per SafeZone basis

	SafeZoneDriven = 0,
	// spawning is automatic, is responsible for dropping an item into the world and
// to maintain some number of said item across the game

	ItemDeliveryManagement = 1,
	// Spawning is controlled entirely by mutators

	MutatorManaged = 2,
};

USTRUCT(BlueprintType)
struct FFortSupplyDropSubPhaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSupplyDropSubPhaseData")
	FScalableFloat SupplyDropMinCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSupplyDropSubPhaseData")
	FScalableFloat SupplyDropMaxCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSupplyDropSubPhaseData")
	FScalableFloat SupplyDropCap;

};

USTRUCT(BlueprintType)
struct FFortSupplyDropGamePhaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	EAthenaGamePhase GamePhase;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropMinPlacementHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropMaxPlacementHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropTimeInterval;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropTimeDeviation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropSpawnMinWaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropSpawnMaxWaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropMinSpawnHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropMaxSpawnHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropMinSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FScalableFloat SupplyDropMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSupplyDropGamePhaseData")
	FFortSupplyDropSubPhaseData SubPhaseData;

};

UCLASS()
class UFortSupplyDropInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSupplyDropInfo")
	FName SupplyDropID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSupplyDropInfo")
	TSubclassOf<AFortAthenaSupplyDrop> SupplyDropClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSupplyDropInfo")
	ESupplyDropSpawnType SpawnType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSupplyDropInfo")
	bool bIgnoreBlueprintOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SpecialActor")
	FGameplayTag SpecialActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush SpecialActorCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D SpecialActorCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	bool bShouldDrawCompassIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ZoneSpawning")
	TArray<FFortSupplyDropGamePhaseData> GamePhaseData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	ESupplyDropItemTrackType ItemTrackType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemDelivery")
	EAthenaGamePhase GamePhaseToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemDelivery")
	int32 SafeZoneIndexToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FGameplayTagContainer SupplyDropTrackingTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	bool bShouldMaintainItemCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FScalableFloat NumDeliveryItemsToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FScalableFloat MinInitialDeliveryDelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FScalableFloat MaxInitialDeliveryDelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FScalableFloat MinTimeBetweenDrops;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FScalableFloat MaxTimeBetweenDrops;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FScalableFloat MinRespawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FScalableFloat MaxRespawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FScalableFloat MinTraceHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ItemDelivery")
	FScalableFloat MaxTraceHeight;

};

