// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavAgentInterface.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAIEncounterInfo.h"
#include "AI/FortAIEncounterInfoOwnerInterface.h"
#include "Building/BuildingRift.h"
#include "FortEncounterDirectionEnum.h"
#include "FortEncounterEnvironmentQueryInfo.h"
#include "FortEncounterSettings.h"
#include "Missions/MissionSaving/MissionSavingTypes.h"
#include "FortAIEncounterRiftManager.generated.h"

class AActor;
class ABuildingRift;
class AFortAIDirector;
class AFortMission;
class UFortAIEncounterInfo;
class UFortPathCostEstimator;

USTRUCT()
struct FFortAIEncounterQueryDirectionTracker
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bHasTriedPreviousDirections;

	UPROPERTY()
	TArray<TEnumAsByte<EFortEncounterDirection::Type>> PreviousQueryDirections;

	UPROPERTY()
	TArray<TEnumAsByte<EFortEncounterDirection::Type>> ChosenDirections;

	UPROPERTY()
	TArray<TEnumAsByte<EFortEncounterDirection::Type>> FailedDirections;

	UPROPERTY()
	TArray<TEnumAsByte<EFortEncounterDirection::Type>> AvailableDirections;

};

USTRUCT()
struct FFortAIEncounterRift
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 QueryID;

	UPROPERTY()
	FVector RiftLocation;

	UPROPERTY()
	TObjectPtr<ABuildingRift> RiftActor;

	UPROPERTY()
	FFortRiftReservationHandle RiftReservationHandle;

};

USTRUCT()
struct FFortAIEncounterRiftManagerInitializationData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> EncounterInfo;

	UPROPERTY()
	FFortEncounterSettings EncounterSettings;

	UPROPERTY()
	FEncounterEnvironmentQueryInfo CurrentEnvironmentQueryInfo;

	UPROPERTY()
	FEncounterEnvironmentQueryInfo FallbackEnvironmentQueryInfo;

	UPROPERTY()
	TSubclassOf<ABuildingRift> RiftClassTemplate;

	UPROPERTY()
	int32 NumRiftsToUse;

	UPROPERTY()
	int32 MinRiftsToUse;

	UPROPERTY()
	float UpdateIntervalTimeSeconds;

};

USTRUCT()
struct FFortAIEncounterSpawnArea
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FEncounterEnvironmentQueryInstance> QueryInstances;

	UPROPERTY()
	TArray<FFortAIEncounterRift> PendingRifts;

	UPROPERTY()
	TArray<FFortAIEncounterRift> Rifts;

	UPROPERTY()
	TArray<FVector> UsedRiftLocations;

	UPROPERTY()
	TArray<TObjectPtr<UFortPathCostEstimator>> PathEstimators;

	UPROPERTY()
	bool bIsActive;

	UPROPERTY()
	bool bUsingFallbackQuery;

	UPROPERTY()
	EFortEncounterSpawnLocationManagementMode SpawnLocationManagementMode;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAIEncounterRiftManager : public UObject, public INavAgentInterface, public IFortAIEncounterInfoOwnerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mission")
	AFortMission* GetAssociatedMission() const;

	UFUNCTION()
	void OnRiftDestroyed(AActor* Rift);

	UPROPERTY(Transient)
	TObjectPtr<UFortAIEncounterInfo> MyEncounter;

	UPROPERTY(Transient)
	TObjectPtr<AFortAIDirector> AIDirector;

	UPROPERTY()
	FFortAIEncounterSpawnArea CurrentSpawnArea;

	UPROPERTY()
	FFortAIEncounterSpawnArea FutureSpawnArea;

	UPROPERTY()
	float UpdateIntervalTimeSeconds;

	UPROPERTY()
	int32 NumRiftsToUse;

	UPROPERTY()
	int32 MinRiftsToUse;

	UPROPERTY()
	FFortEncounterSettings EncounterSettings;

	UPROPERTY(meta=(ClampMin="0.0"))
	float ExtraSpawnLocationPercentage;

	UPROPERTY()
	FEncounterEnvironmentQueryInfo CurrentEnvironmentQueryInfo;

	UPROPERTY()
	FEncounterEnvironmentQueryInfo FallbackEnvironmentQueryInfo;

	UPROPERTY()
	FFortAIEncounterQueryDirectionTracker EncounterQueryDirectionTracker;

	UPROPERTY()
	TSubclassOf<ABuildingRift> RiftClassTemplate;

	UPROPERTY(Transient)
	float LastObjectiveBatchPathCostUpdateTime;

	UPROPERTY(Transient)
	float LastPlayerBatchPathCostUpdateTime;

};

