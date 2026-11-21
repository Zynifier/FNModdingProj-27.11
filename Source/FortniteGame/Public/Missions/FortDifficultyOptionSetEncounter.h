// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortEncounterSpawnLocationPlacementMode.h"
#include "Missions/MissionSaving/MissionSavingTypes.h"
#include "FortDifficultyOptionSetEncounter.generated.h"

class UFortDifficultyOptionCategoryEncounter_Breathers;
class UFortDifficultyOptionCategoryEncounter_DirectionChange;
class UFortDifficultyOptionCategoryEncounter_DirectionNumber;
class UFortDifficultyOptionCategoryEncounter_Distance;
class UFortDifficultyOptionCategoryEncounter_IntensityCurveSequence;
class UFortDifficultyOptionCategoryEncounter_ModifierTags;
class UFortDifficultyOptionCategoryEncounter_PawnNumberCap;
class UFortDifficultyOptionCategoryEncounter_SpawnGroupProgression;
class UFortDifficultyOptionCategoryEncounter_SpawnLimitPawns;
class UFortDifficultyOptionCategoryEncounter_SpawnLimitPoints;
class UFortDifficultyOptionCategoryEncounter_SpawnPointsBurst;
class UFortDifficultyOptionCategoryEncounter_SpawnPointsCurve;
class UFortDifficultyOptionCategoryEncounter_SpawnPointsMultiplier;
class UFortDifficultyOptionCategoryEncounter_SpawnTiming;
class UFortDifficultyOptionCategoryEncounter_Time;
class UFortDifficultyOptionCategoryEncounter_TimedModifierTags;
class UFortDifficultyOptionCategoryEncounter_UtilitiesAdjustment;
class UFortDifficultyOptionCategoryEncounter_UtilitiesFree;
class UFortDifficultyOptionCategoryEncounter_UtilitiesLocked;

UCLASS(BlueprintType, Blueprintable)
class UFortDifficultyOptionSetEncounter : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Pacing")
	TEnumAsByte<EFortEncounterPacingMode::Type> PacingMode;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Pacing")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_IntensityCurveSequence> IntensityCurveSequenceCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Pacing")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_SpawnPointsCurve> SpawnPointsPercentageCurveSequenceCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Pacing")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_SpawnPointsBurst> SpawnPointsBurstCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Pacing")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_Breathers> BreathersCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Pacing")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_SpawnPointsMultiplier> SpawnPointsMultiplierCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Pacing")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_PawnNumberCap> PawnNumberCapCategory;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Instanced, Category="Pacing")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_SpawnTiming> OptionalSpawnTimingCategory;

	UPROPERTY(EditDefaultsOnly, Category="SpawnLimit")
	TEnumAsByte<EFortEncounterSpawnLimitType::Type> SpawnLimitMode;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="SpawnLimit")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_SpawnLimitPoints> SpawnPointsLimitCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="SpawnLimit")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_SpawnLimitPawns> PawnLimitCategory;

	UPROPERTY(EditDefaultsOnly, Category="Utilities")
	TEnumAsByte<EFortEncounterUtilitiesMode::Type> UtilitiesMode;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Utilities")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_UtilitiesLocked> LockedUtilitiesCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Utilities")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_UtilitiesFree> FreeUtilitiesCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Utilities")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_UtilitiesAdjustment> UtilitiesAdjustmentCategory;

	UPROPERTY(EditDefaultsOnly, Category="SpawnLocations")
	EFortEncounterSpawnLocationManagementMode SpawnLocationManagementMode;

	UPROPERTY(EditDefaultsOnly, Category="SpawnLocations")
	TEnumAsByte<EFortEncounterSpawnLocationPlacementMode::Type> SpawnLocationPlacementMode;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="SpawnLocations")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_DirectionNumber> DirectionNumberCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="SpawnLocations")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_DirectionChange> DirectionChangeCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="SpawnLocations")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_Distance> DistanceCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="SpawnGroups")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_SpawnGroupProgression> SpawnGroupProgressionCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Time")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_Time> TimeCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Tags")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_ModifierTags> OptionalModifierTagsCategory;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="MiniBoss")
	TObjectPtr<UFortDifficultyOptionCategoryEncounter_TimedModifierTags> OptionalMiniBossStartTimedTagsCategory;

};

