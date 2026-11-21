// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "FortEncounterSpawnLocationPlacementMode.h"
#include "Missions/FortMissionGenerationCategory.h"
#include "Missions/MissionTypes.h"
#include "MissionSavingTypes.generated.h"

class AActor;
class AFortObjectiveBase;
class UFortDifficultyOptionCategoryEncounter;
class UFortDifficultyOptionCategoryMission;
class UFortDifficultyOptionEncounter;
class UFortDifficultyOptionMission;
class UFortMissionGenerator;
class UFortMissionInfo;

UENUM()
namespace EFortEncounterPacingMode
{
	enum Type
	{
		SpawnPointsPercentageCurve = 0,
		IntensityCurve = 1,
		Burst = 2,
		Fixed = 3,
	};
}

UENUM()
namespace EFortEncounterSpawnLimitType
{
	enum Type
	{
		NoLimit = 0 UMETA(DisplayName="No Limit"),
		NumPawnsLimit = 1 UMETA(DisplayName="Pawn Number Limit"),
		SpawnPointLimit = 2 UMETA(DisplayName="Spawn Point Limit"),
		UserDefined = 3 UMETA(DisplayName="Limit Specified by User"),
		MAX = 4 UMETA(Hidden),
	};
}

UENUM(BlueprintType)
enum class EFortEncounterSpawnLocationManagementMode : uint8
{
	Spawn = 0,
	Search = 1,
};

UENUM()
namespace EFortEncounterUtilitiesMode
{
	enum Type
	{
		LockedOnly = 0,
		LockedAndFree = 1,
	};
}

USTRUCT()
struct FFortEncounterModeSettings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<EFortEncounterPacingMode::Type> PacingMode;

	UPROPERTY()
	EFortEncounterSpawnLocationManagementMode SpawnLocationManagementMode;

	UPROPERTY()
	TEnumAsByte<EFortEncounterSpawnLocationPlacementMode::Type> SpawnLocationMode;

	UPROPERTY()
	TEnumAsByte<EFortEncounterUtilitiesMode::Type> UtilitiesMode;

	UPROPERTY()
	TEnumAsByte<EFortEncounterSpawnLimitType::Type> SpawnLimitMode;

};

USTRUCT()
struct FFortEncounterTransitionSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEncounterTransitionSettings")
	bool bShouldMaintainEncounterState;

};

USTRUCT()
struct FFortGeneratedEncounterOption
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortDifficultyOptionCategoryEncounter> EncounterOptionCategory;

	UPROPERTY()
	TSubclassOf<UFortDifficultyOptionEncounter> EncounterOption;

	UPROPERTY()
	TObjectPtr<UFortDifficultyOptionEncounter> EncounterOptionInstance;

	UPROPERTY()
	float RangeLerpValue;

	UPROPERTY()
	bool bChangedSinceLastVLog;

};

USTRUCT()
struct FFortGeneratedEncounterProfile
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float EncounterDifficultyLevel;

	UPROPERTY()
	TArray<FFortGeneratedEncounterOption> EncounterOptions;

	UPROPERTY()
	FFortEncounterModeSettings EncounterModeSettings;

	UPROPERTY()
	FGameplayTagContainer EncounterTypeTags;

	UPROPERTY()
	int32 DifficultyOptionPointsAvailableAtGeneration;

	UPROPERTY()
	int32 MinDifficultyOptionPointsToUse;

	UPROPERTY()
	bool bShouldReselectOptionsPerInstance;

	UPROPERTY()
	int32 GeneratedEncounterIndex;

};

USTRUCT()
struct FFortGeneratedEncounterSequence
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortEncounterTransitionSettings TransitionSettings;

	UPROPERTY()
	int32 StartingGeneratedEncounterProfileIndex;

	UPROPERTY()
	int32 NumEncountersInSequence;

	UPROPERTY()
	FGameplayTagContainer EncounterSequenceTags;

};

USTRUCT()
struct FFortGeneratedMissionOption
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortDifficultyOptionCategoryMission> MissionOptionCategory;

	UPROPERTY()
	TSubclassOf<UFortDifficultyOptionMission> MissionOption;

	UPROPERTY()
	float RangeLerpValue;

};

USTRUCT()
struct FFortGeneratedDifficultyOptions
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float GameDifficultyAtGeneration;

	UPROPERTY()
	int32 DifficultyOptionPointsAvailableAtGeneration;

	UPROPERTY()
	int32 MaxEncounterSpawnPointsAtGeneration;

	UPROPERTY()
	int32 MinDifficultyOptionPointsToUse;

	UPROPERTY()
	TArray<FFortGeneratedEncounterSequence> GeneratedEncounterSequences;

protected:
	UPROPERTY()
	TArray<FFortGeneratedMissionOption> MissionOptions;

	UPROPERTY()
	TArray<FFortGeneratedEncounterProfile> GeneratedEncounterProfiles;

};

USTRUCT()
struct FFortMissionPlacementItemLookupData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FGameplayTagContainer ItemIdentifyingTags;

	UPROPERTY(Transient)
	FGameplayTagContainer TagsAddedToPlacementActors;

	UPROPERTY(Transient)
	TSubclassOf<AActor> ActorToPlace;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ActorToUseForSpawnLocation;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> SpawnedActorWeak;

	UPROPERTY(Transient)
	FVector SpawnLocation;

	UPROPERTY(Transient)
	FRotator SpawnRotation;

	UPROPERTY(Transient)
	uint8 bDontCreateSpawnRiftsNearby : 1;

	UPROPERTY(Transient)
	uint8 bShouldFreeLocationsOnDeath : 1;

};

USTRUCT()
struct FFortMissionEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMissionEntry")
	float Weight;

	UPROPERTY(EditAnywhere, Category="FortMissionEntry")
	int32 WorldMinLevel;

	UPROPERTY(EditAnywhere, Category="FortMissionEntry")
	int32 WorldMaxLevel;

	UPROPERTY(EditAnywhere, Category="FortMissionEntry")
	FDataTableRowHandle MinDifficultyInfoRow;

	UPROPERTY(EditAnywhere, Category="FortMissionEntry")
	TObjectPtr<UFortMissionGenerator> MissionGenerator;

	UPROPERTY(EditAnywhere, Category="FortMissionEntry")
	TObjectPtr<UFortMissionInfo> MissionInfo;

	UPROPERTY(EditAnywhere, Category="FortMissionEntry")
	TEnumAsByte<EMissionGenerationCategory::Type> GenerationCategory;

	UPROPERTY()
	FFortGeneratedDifficultyOptions GeneratedDifficultyOptions;

private:
	UPROPERTY(Transient)
	TArray<FFortMissionPlacementItemLookupData> BlueprintLookupData;

};

USTRUCT()
struct FFortObjectiveRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<AFortObjectiveBase> ObjectiveClass;

	UPROPERTY()
	TArray<uint8> ObjectiveData;

};

USTRUCT()
struct FFortMissionRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortMissionEntry MissionEntry;

	UPROPERTY(Transient)
	TObjectPtr<UFortMissionGenerator> MissionGenerator;

	UPROPERTY(Transient)
	FFortGeneratedDifficultyOptions GeneratedMissionOptions;

	UPROPERTY()
	int32 DayGenerated;

	UPROPERTY()
	int32 UIIndex;

	UPROPERTY()
	FUniqueNetIdRepl QuestOwnerAccount;

	UPROPERTY()
	EFortMissionStatus MissionStatus;

	UPROPERTY()
	TArray<FFortObjectiveRecord> ObjectiveRecords;

	UPROPERTY()
	TArray<uint8> MissionData;

private:
	UPROPERTY(meta=(IgnoreForMemberInitializationTest))
	FGuid MissionGuid;

};

