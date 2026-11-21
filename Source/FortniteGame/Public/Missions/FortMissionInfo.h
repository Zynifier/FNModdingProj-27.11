// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "FortMultiSize.h"
#include "Missions/FortEncounterProfile.h"
#include "Missions/FortMissionConfigDataParams.h"
#include "Missions/FortMissionPerDifficultyProperties.h"
#include "Missions/MissionTypes.h"
#include "FortMissionInfo.generated.h"

class AActor;
class ABuildingFoundation;
class AFortMission;
class AFortObjectiveBase;
class UAthenaAIService;
class UCurveTable;
class UEnvQuery;
class UFortBadgeItemDefinition;
class UFortDifficultyOptionSetMission;
class UFortMissionWeightedRewards;
class UFortWorldItemDefinition;
class UMediaSource;

UENUM()
enum class EFortOptionGenerationResult : uint8
{
	NoOptionsGenerated = 0,
	NewOptionsGenerated = 1,
	ExistingOptionsGenerated = 2,
};

USTRUCT()
struct FFortMissionPlacementActorItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	FGameplayTagContainer ItemIdentifyingTags;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	FGameplayTagContainer TagsToAddToChosenPlacementActor;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	TObjectPtr<UEnvQuery> PlacementQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	TSoftClassPtr<AActor> ActorToPlace;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	int32 NumLocationsToFind;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	bool bSpawnActorAutomatically;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	bool bShouldReserveLocations;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	bool bSnapToGrid;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	bool bAdjustPlacementForFloors;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FortMissionPlacementActorItem", meta=(ShowOnlyInnerProperties))
	bool bDontCreateSpawnRiftsNearby;

};

USTRUCT()
struct FFortMissionPlacementFoundationItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementFoundationItem", meta=(ShowOnlyInnerProperties))
	FGameplayTagContainer ItemIdentifyingTags;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementFoundationItem", meta=(ShowOnlyInnerProperties))
	FGameplayTagContainer TagsToAddToChosenPlacementActorOrFoundationActor;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementFoundationItem", meta=(ShowOnlyInnerProperties))
	TObjectPtr<UEnvQuery> PlacementQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementFoundationItem", meta=(ShowOnlyInnerProperties))
	TSoftClassPtr<ABuildingFoundation> BuildingFoundationToPlace;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementFoundationItem", meta=(ShowOnlyInnerProperties))
	int32 NumLocationsToFind;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementFoundationItem", meta=(ShowOnlyInnerProperties))
	bool bAdjustFoundationPlacementForFloors;

};

USTRUCT()
struct FFortMissionPlacementItems
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementItems", meta=(ShowOnlyInnerProperties))
	FGameplayTagContainer TagsToAddToChosenPlacementActors;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementItems", meta=(ShowOnlyInnerProperties))
	TArray<FFortMissionPlacementFoundationItem> AdditionalWorldFoundations;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementItems", meta=(ShowOnlyInnerProperties))
	TArray<FFortMissionPlacementActorItem> ActorsAndLocations;

};

USTRUCT(BlueprintType)
struct FFortMissionPopupWidgetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	bool bShowDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FSlateBrush DescriptionIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FSlateBrush AvailableIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FSlateBrush UnavailableIcon;

};

USTRUCT(BlueprintType)
struct FFortMissionTaggedRewards
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TaggedRewards")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TaggedRewards")
	TArray<TSoftObjectPtr<UFortWorldItemDefinition>> WorldItemDefinitions;

};

USTRUCT()
struct FFortObjectiveEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Setup")
	TObjectPtr<UFortBadgeItemDefinition> ObjectiveRewardBadge;

	UPROPERTY(EditDefaultsOnly, Category="Setup")
	TEnumAsByte<EFortObjectiveRequirement::Type> MissionRequirement;

	UPROPERTY(EditDefaultsOnly, Category="Setup")
	FGameplayTagContainer ObjectiveHandle;

private:
	UPROPERTY(EditDefaultsOnly, Category="Setup", meta=(DisplayName="Objective"))
	TSoftClassPtr<AFortObjectiveBase> ObjectiveRef;

};

USTRUCT(BlueprintType)
struct FFortObjectiveBlock
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Objectives")
	TArray<FFortObjectiveEntry> ObjectiveEntries;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortMissionInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Data")
	TEnumAsByte<EFortMissionType::Type> MissionType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Mission Data")
	FGameplayTagContainer MissionTags;

	UPROPERTY(EditDefaultsOnly, Category="Mission Data", meta=(ClampMax="10.0", ClampMin="-1.0"))
	float TimeOfDaySpeed;

	UPROPERTY(EditDefaultsOnly, Category="Mission Data", meta=(ClampMin="0"))
	float ZoneEndDelay;

	UPROPERTY(EditDefaultsOnly, Category="Mission Data")
	float ZoneEndDelayOverrideForFailure;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	TObjectPtr<UFortBadgeItemDefinition> MissionRewardBadge;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	FName MissionRewardItemsLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	int32 MaxRewardLootTierPoints;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards", meta=(ClampMin="0"))
	int32 ParTime;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	TObjectPtr<UFortBadgeItemDefinition> UnderParBadge;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	int32 MaxMissionPoints;

	UPROPERTY(EditDefaultsOnly, Category="Mission Data")
	bool bVictoryTileRequired;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Description")
	FText MissionDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Description")
	FFortMultiSizeBrush MissionIcons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
	TObjectPtr<UMediaSource> EndOfMissionMediaSource;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	bool bSkipEndOfMissionVideo;

	UPROPERTY(EditDefaultsOnly, Category="Mission Data")
	int32 DaysToLive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objectives")
	TArray<FFortObjectiveBlock> ObjectiveBlocks;

	UPROPERTY(EditDefaultsOnly, Category="Mission Data")
	bool bShowMinimapIconsOnlyIfFocused;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Data")
	float ExpectedCompletionTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Data")
	float MissionEncounterTime;

	UPROPERTY(EditDefaultsOnly, Category="Mission Setup")
	FFortMissionPlacementItems MissionPlacementInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Setup - Old System", meta=(ClampMin="0.0"))
	float MinDistanceToOtherMissions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Setup - Old System", meta=(ClampMin="0.0"))
	float MinDistanceToAllowSpawnPad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mission Setup - Old System")
	FFortPlacementActorFinderInfo PlacementActorInfo;

	UPROPERTY(EditDefaultsOnly, Category="Mission Setup")
	bool bStartPlayingOnLoad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Setup")
	bool bRequiresActivation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Setup")
	int32 BluGloActivationRequirement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mission Setup")
	bool bAllowDifficultyIncrease;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	FText RewardsTitleText;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	FText RewardsDescriptionText;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	FText NonParticipationRewardsDescriptionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FFortMissionPopupWidgetData PopupWidgetData;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	TObjectPtr<UFortMissionWeightedRewards> WeightedRewards;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Difficulty and Rewards")
	bool bIsGroupContent;

	UPROPERTY()
	bool bUseRRV;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped", EditCondition="MissionType == EFortMissionType::Primary", EditConditionHides))
	TSoftObjectPtr<UCurveTable> GameData;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Description")
	FText MissionName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Description")
	bool bShouldDisplayMissionName;

	UPROPERTY(EditDefaultsOnly, Category="AIEncounters")
	TArray<FFortEncounterProfile> EncounterProfiles;

	UPROPERTY(EditDefaultsOnly, Category="AIEncounters")
	TArray<FFortEncounterSequenceSettings> EncounterSequences;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DifficultyOptions")
	TSoftObjectPtr<UFortDifficultyOptionSetMission> MissionOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DifficultyOptions")
	FGameplayTagContainer MissionDifficultyOptionTags;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty and Rewards")
	TArray<FFortMissionTaggedRewards> TaggedRewards;

	UPROPERTY(EditDefaultsOnly, Category="PerDifficultyProperties")
	TArray<FMissionPerDifficultyProperties> PerDifficultyProperties;

	UPROPERTY(EditDefaultsOnly, Category="Configuration Parameters")
	FFortMissionConfigDataParams ConfigParams;

private:
	UPROPERTY(EditDefaultsOnly, Category="Mission Setup", meta=(DisplayName="Mission Class"))
	TSoftClassPtr<AFortMission> MissionRef;

	UPROPERTY(EditAnywhere, Category="AI Services", meta=(AllowPrivateAccess="true", EditCondition="MissionType == EFortMissionType::Primary", EditConditionHides))
	TArray<TSubclassOf<UAthenaAIService>> AIServices;

};

