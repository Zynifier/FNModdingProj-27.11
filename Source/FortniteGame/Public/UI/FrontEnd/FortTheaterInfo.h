// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"
#include "FortMultiSize.h"
#include "FortReleaseVersion.h"
#include "FortRequirementsInfo.h"
#include "FortSubGameTypes.h"
#include "UI/FrontEnd/FortRegionInfo.h"
#include "FortTheaterInfo.generated.h"

class AWorldMapPin;
class UFortGameplayModifierItemDefinition;
class UFortQuestItemDefinition;
class UFortRegionInfo;
class UFortZoneTheme;
class USlateBrushAsset;
class UTexture2D;

UENUM(BlueprintType)
enum class EFortTheaterMapTileType : uint8
{
	// Tile behaves normally and will potentially be cycled active/inactive

	Normal = 0,
	// Critical mission tile, always active with special ramifications for matchmaking

	CriticalMission = 1,
	// Tile is always active/available on the hex map and does not count against the mission quota

	AlwaysActive = 2,
	// Tile is always active, but not directly accessible from the hex map

	Outpost = 3,
	// Tile that never has missions useful for artistic only tiles

	NonMission = 4,
	// PvP "forward operating base"

	PvPFOB = 5,
};

UENUM(BlueprintType)
enum class EFortTheaterType : uint8
{
	// Normal PvE session with persistence

	Standard = 0,
	// Non-normal PvE sessions with varying degrees of persistence

	Elder = 1,
	// Entirely PvP theater, only available with pvp credentials

	PvP = 2,
	PvP2 = 3,
	// Tutorial theater, only available during tutorial

	Tutorial = 4,
	TutorialGate = 5,
	Max_None = 6 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FEventDependentTag
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EventDependentTag")
	FString RequiredEventFlag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="EventDependentTag")
	FGameplayTag RelatedTag;

};

USTRUCT()
struct FFortEditorTheaterMapRegionColor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortEditorTheaterMapRegionColor")
	TObjectPtr<UFortRegionInfo> Region;

	UPROPERTY(EditAnywhere, Category="FortEditorTheaterMapRegionColor", meta=(IgnoreForMemberInitializationTest))
	FLinearColor RegionColor;

};

USTRUCT(BlueprintType)
struct FFortLinkedQuest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLinkedQuest")
	TObjectPtr<UFortQuestItemDefinition> QuestDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLinkedQuest")
	FDataTableRowHandle ObjectiveStatHandle;

};

USTRUCT()
struct FFortMissionAlertAvailableData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMissionAlertAvailableData")
	FName MissionAlertCategoryName;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionAlertAvailableData")
	int32 NumMissionAlertsAvailable;

};

USTRUCT()
struct FFortMissionAlertRegionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMissionAlertRegionData")
	TArray<FString> RegionUniqueIds;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionAlertRegionData")
	TArray<FFortMissionAlertAvailableData> AvailabilityDataPerCategory;

};

USTRUCT(BlueprintType)
struct FFortMissionAlertRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMissionAlertRuntimeData")
	FName MissionAlertCategoryName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMissionAlertRuntimeData")
	bool bRespectTileRequirements;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMissionAlertRuntimeData")
	bool bAllowQuickplay;

};

USTRUCT(BlueprintType)
struct FFortTheaterColorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterColorInfo")
	bool bUseDifficultyToDetermineColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterColorInfo")
	FSlateColor Color;

};

USTRUCT(BlueprintType)
struct FFortTheaterGameplayModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTheaterGameplayModifier")
	FString EventFlagName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTheaterGameplayModifier")
	TObjectPtr<UFortGameplayModifierItemDefinition> GameplayModifier;

};

USTRUCT(BlueprintType)
struct FFortTheaterMapRegionData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapRegionData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMapRegionData")
	FName UniqueId;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapRegionData")
	FGameplayTagContainer RegionTags;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapRegionData")
	TArray<int32> TileIndices;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapRegionData")
	TSoftObjectPtr<USlateBrushAsset> RegionThemeIcon;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMapRegionData")
	FFortTheaterMapMissionData MissionData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapRegionData")
	FFortRequirementsInfo Requirements;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapRegionData")
	TArray<FFortMissionAlertRequirementsInfo> MissionAlertRequirements;

};

USTRUCT(BlueprintType)
struct FFortTheaterMapTileData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	EFortTheaterMapTileType TileType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TSoftClassPtr<UFortZoneTheme> ZoneTheme;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapTileData")
	FFortRequirementsInfo Requirements;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	TArray<FFortLinkedQuest> LinkedQuests;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	int32 XCoordinate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	int32 YCoordinate;

	UPROPERTY(EditAnywhere, Category="Zone")
	TArray<FFortTheaterMissionWeight> MissionWeightOverrides;

	UPROPERTY(EditAnywhere, Category="Zone")
	TArray<FFortTheaterDifficultyWeight> DifficultyWeightOverrides;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	bool CanBeMissionAlert;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zone")
	bool bDisallowQuickplay;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapTileData")
	FGameplayTagContainer TileTags;

};

USTRUCT(BlueprintType)
struct FFortTheaterRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	EFortTheaterType TheaterType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	FGameplayTagContainer TheaterTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	TArray<FEventDependentTag> EventDependentTheaterTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	FFortRequirementsInfo TheaterVisibilityRequirements;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	FFortRequirementsInfo Requirements;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	ESubGame RequiredSubGameForVisibility;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	bool bOnlyMatchLinkedQuestsToTiles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	TSubclassOf<AWorldMapPin> WorldMapPinClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	TObjectPtr<UTexture2D> TheaterImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	FFortMultiSizeBrush TheaterImages;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	FFortTheaterColorInfo TheaterColorInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	FName Socket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	FFortRequirementsInfo MissionAlertRequirements;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	TArray<FFortMissionAlertRuntimeData> MissionAlertCategoryRequirements;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterRuntimeData")
	TArray<FFortTheaterGameplayModifier> GameplayModifierList;

	UPROPERTY(Transient)
	float HighestDifficulty;

};

USTRUCT(BlueprintType)
struct FFortTheaterMapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	FText DisplayName;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	FString UniqueId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	int32 TheaterSlot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	int32 TheaterUIOrder;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	bool bIsTestTheater;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	bool bHideLikeTestTheater;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	FString RequiredEventFlag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	FName MissionRewardNamedWeightsRowName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	FText ThreatDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	FFortTheaterRuntimeData RuntimeInfo;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	TArray<FFortTheaterMapTileData> Tiles;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="FortTheaterMapData")
	TArray<FFortTheaterMapRegionData> Regions;

};

USTRUCT()
struct FFortTheaterMapMissionAlertData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMapMissionAlertData")
	TArray<FFortMissionAlertRegionData> AvailabilityDataPerRegion;

};

USTRUCT()
struct FFortTheaterTileEditorData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 XCoordinate;

	UPROPERTY()
	int32 YCoordinate;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterTileEditorData")
	TSubclassOf<UFortZoneTheme> ZoneTheme;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterTileEditorData")
	TObjectPtr<UFortRegionInfo> Region;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterTileEditorData")
	FFortRequirementsInfo Requirements;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterTileEditorData")
	TArray<FFortLinkedQuest> LinkedQuests;

	UPROPERTY()
	EFortTheaterMapTileType TileType;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterTileEditorData")
	FGameplayTagContainer TileTags;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterTileEditorData")
	TArray<FFortTheaterMissionWeight> MissionWeightOverrides;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterTileEditorData")
	TArray<FFortTheaterDifficultyWeight> DifficultyWeightOverrides;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterTileEditorData")
	bool bCanBeMissionAlert;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterTileEditorData")
	bool bDisallowQuickplay;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortTheaterInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FString UniqueId;

	UPROPERTY()
	int32 SaveVersion;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterInfo")
	FFortTheaterMapData TheaterData;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterInfo")
	FFortTheaterMapMissionData Missions;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterInfo")
	FFortTheaterMapMissionAlertData MissionAlerts;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortTheaterInfo")
	FFortReleaseVersion ReleaseVersion;
#endif

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterInfo")
	bool bForceIncludeInCookIfReferenced;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	TSubclassOf<UFortZoneTheme> SelectedZoneTheme;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	TObjectPtr<UFortRegionInfo> SelectedZoneRegion;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	EFortTheaterMapTileType SelectedTileType;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	FGameplayTagContainer SelectedTileTags;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	FFortRequirementsInfo SelectedTileRequirements;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	TArray<FFortLinkedQuest> SelectedLinkedQuests;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	TArray<FFortTheaterMissionWeight> SelectedMissionWeightOverrides;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	TArray<FFortTheaterDifficultyWeight> SelectedDifficultyWeightOverrides;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	bool bCanSelectedTileHaveMissionAlert;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Tiles")
	bool bShouldSelectedTileDisallowQuickplay;

	UPROPERTY(VisibleAnywhere, Category="FortTheaterInfo")
	TArray<FFortEditorTheaterMapRegionColor> RegionColors;

	UPROPERTY()
	TArray<FFortTheaterTileEditorData> EditorTiles;

	UPROPERTY()
	int32 TheaterWidth;

	UPROPERTY()
	int32 TheaterHeight;

};

