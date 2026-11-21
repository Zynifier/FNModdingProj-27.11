// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "FortInitializationInterface.h"
#include "McpSharedTypes.h"
#include "UI/FrontEnd/FortTheaterInfo.h"
#include "FortTheaterMapViewer.generated.h"

class AFortTheaterMapTile;
class UFortItemDefinition;
class UFortMissionGenerator;

UENUM(BlueprintType)
enum class EFortMapNavigationDirection : uint8
{
	North = 0,
	NorthEast = 1,
	East = 2,
	SouthEast = 3,
	South = 4,
	SouthWest = 5,
	West = 6,
	NorthWest = 7,
	Invalid = 8 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortMissionQuestValidityResult : uint8
{
	Invalid = 0,
	InvalidNotPlayable = 1,
	ValidLinked = 2,
	ValidObjectiveCondition = 3,
	ValidFallback = 4,
};

USTRUCT()
struct FFortAvailableMissionAlertData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString CategoryName;

	UPROPERTY()
	FString SpreadDataName;

	UPROPERTY()
	FString MissionAlertGuid;

	UPROPERTY()
	int32 TileIndex;

	UPROPERTY()
	FDateTime AvailableUntil;

	UPROPERTY()
	FDateTime RefreshSpreadAt;

	UPROPERTY()
	FMcpLootResult MissionAlertRewards;

	UPROPERTY()
	FMcpLootResult MissionAlertModifiers;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> ItemDefinitionRefCache;

};

USTRUCT()
struct FFortAvailableMissionAlerts
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TheaterId;

	UPROPERTY()
	TArray<FFortAvailableMissionAlertData> AvailableMissionAlerts;

	UPROPERTY()
	FDateTime NextRefresh;

};

USTRUCT()
struct FFortAvailableMissionData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString MissionGuid;

	UPROPERTY()
	FMcpLootResult MissionRewards;

	UPROPERTY()
	FMcpLootResult BonusMissionRewards;

	UPROPERTY()
	TSoftClassPtr<UFortMissionGenerator> MissionGenerator;

	UPROPERTY()
	FDataTableRowHandle MissionDifficultyInfo;

	UPROPERTY()
	int32 TileIndex;

	UPROPERTY()
	FDateTime AvailableUntil;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> ItemDefinitionRefCache;

};

USTRUCT()
struct FFortAvailableTheaterMissions
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TheaterId;

	UPROPERTY()
	TArray<FFortAvailableMissionData> AvailableMissions;

	UPROPERTY()
	FDateTime NextRefresh;

};

USTRUCT()
struct FFortFoundQuestMissions
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TheaterId;

	UPROPERTY()
	bool bIsValidForAllPlayableMissions;

	UPROPERTY()
	TArray<FFortAvailableMissionData> LinkedMissions;

	UPROPERTY()
	TArray<FFortAvailableMissionData> TagMatchingMissions;

	UPROPERTY()
	TArray<FFortAvailableMissionData> FallbackMatchingMissions;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "Actor", "Advanced", "Navigation", "Rendering", "Replication", "Input"))
class AFortTheaterMapViewer : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleMarkedQuestsChanged();

	UPROPERTY()
	TArray<FFortAvailableTheaterMissions> MissionAvailabilityList;

	UPROPERTY()
	TArray<FFortAvailableMissionAlerts> MissionAlertAvailabilityList;

	UPROPERTY()
	FBox HexMapSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Tile")
	float HexTileWidth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Tile")
	float HexTileHeight;

protected:
	UPROPERTY()
	TArray<TObjectPtr<AFortTheaterMapTile>> HexMap;

	UPROPERTY()
	FString CurrentTheaterId;

	UPROPERTY(Transient)
	TArray<bool> LeaderTileAccessStates;

	UPROPERTY(Transient)
	TObjectPtr<AFortTheaterMapTile> CurrentSelectedTile;

	UPROPERTY(Transient)
	TObjectPtr<AFortTheaterMapTile> CurrentFocusedTile;

	UPROPERTY()
	TArray<FFortTheaterMapData> TheaterList;

	UPROPERTY()
	int32 NumValidHexMapTiles;

	UPROPERTY()
	int32 CurrentTileIndex;

	UPROPERTY()
	bool bDisplayTheaterComplete;

};

