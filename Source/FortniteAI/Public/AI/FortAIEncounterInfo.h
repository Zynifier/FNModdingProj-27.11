// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavAgentInterface.h"
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAIDirector.h"
#include "AI/FortAISpawnGroupUpgrade.h"
#include "AI/FortAISpawnGroupUpgradeUIData.h"
#include "FortAIUtility.h"
#include "FortEncounterDirectionEnum.h"
#include "FortEncounterEnvironmentQueryInfo.h"
#include "FortEncounterSettings.h"
#include "Missions/Generation/FortDifficultyOptionEncounter_TimedModifierTags.h"
#include "Missions/MissionSaving/MissionSavingTypes.h"
#include "Missions/MissionTypes.h"
#include "Modifiers/GameplayMutatorRegistryInterface.h"
#include "FortAIEncounterInfo.generated.h"

class AActor;
class ABuildingRift;
class AController;
class AFortAIDirector;
class AFortAIDirectorDataManager;
class AFortAIPawn;
class AFortGameplayMutator_AIEncounterModifierTags;
class AFortGameplayMutator_AILevelVariance;
class UCurveFloat;
class UCurveTable;
class UFortAIAssignment;
class UFortAIAssignmentSettings;
class UFortAIEncounterInfo;
class UFortAIEncounterRiftManager;
class UFortAISpawnGroup;
class UFortAISpawnGroupProgressionInfo;
class UFortAbilitySet;
class UFortGameplayModifierItemDefinition;
class UFortIntensityCurveSequence;
class UFortIntensityCurveSequenceProgression;
class UFortSpawnPointsPercentageCurveSequence;
class UPrimitiveComponent;

UENUM()
namespace EFortAIWaveProgressSection
{
	enum Type
	{
		SectionOne = 0,
		// Ramp

		SectionTwo = 1,
		// Peak/Fade

		Max_None = 2,
	};
}

UENUM()
namespace EFortEncounterPacingState
{
	enum Type
	{
		Ramp = 0,
		Peak = 1,
		Fade = 2,
		Rest = 3,
		Max_None = 4,
	};
}

UENUM()
namespace EFortEncounterState
{
	enum Type
	{
		Uninitialized = 0,
		// The starting state at creation

		InitializingProperties = 1,
		// Initializing rift properties

		InitializingRiftManager = 2,
		// Initializing rifts and running their EQS queries to find nearby spawn locations.  Not used if scripted spawning is being done.

		AwaitingActivation = 3,
		// Awaiting activation by timer or manual activation request

		Active = 4,
		// This encounter is active and running through its pacing states

		ReplacingRifts = 5,
		// Rerunning rift queries to get new rifts

		Max_None = 6,
	};
}

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnBuildingRiftBlockedShouldDie, UFortAIEncounterInfo*, Encounter, ABuildingRift*, Rift, AController*, EventInvestigator, AActor*, DamageCauser);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterAllBurstEnemiesSpawned, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterAllEnemiesKilled, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterCombatParticipation, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEncounterCompleted, UFortAIEncounterInfo*, Encounter, bool, bSuccessfullyCompleted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterEnemySpawnFailed, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEncounterEnemySpawned, UFortAIEncounterInfo*, Encounter, AFortAIPawn*, SpawnedEnemy);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterFadeStarted, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterOptionsChanged, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEncounterPawnDied, UFortAIEncounterInfo*, Encounter, AFortAIPawn*, DeadPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterPeakStarted, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterRampStarted, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterRestStarted, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEncounterRiftSpawned, UFortAIEncounterInfo*, Encounter, ABuildingRift*, Rift);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterSpawnDirectionsChosen, UFortAIEncounterInfo*, Encounter);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEncounterSpawnedFinalEnemy, UFortAIEncounterInfo*, Encounter);

USTRUCT()
struct FAIEncounterSpawnGroupWeights
{
	GENERATED_BODY()

};

USTRUCT()
struct FCurrentIntensityAnalyticsBucket
{
	GENERATED_BODY()

};

USTRUCT()
struct FEncounterEnvironmentQueryInstance
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FEncounterEnvironmentQueryInfo EnvironmentQueryInfo;

	UPROPERTY()
	int32 QueryID;

	UPROPERTY()
	bool bIsWaitingForQueryResults;

	UPROPERTY()
	TEnumAsByte<EFortEncounterDirection::Type> ChosenDirection;

	UPROPERTY()
	TArray<FVector> QueryLocations;

	UPROPERTY()
	TArray<TWeakObjectPtr<ABuildingRift>> FoundRifts;

	UPROPERTY()
	int32 NumTimesUsed;

};

USTRUCT()
struct FFortAIEncounterWaveProgressEstimation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float SectionProgressEstimate;

	UPROPERTY()
	float SectionStartTime;

	UPROPERTY()
	float LastWaveProgressUpdateTime;

	UPROPERTY()
	float PeakAndFadeWavePercentage;

	UPROPERTY()
	float MaxAdjustmentPerSecond;

	UPROPERTY()
	TEnumAsByte<EFortAIWaveProgressSection::Type> CurrentSection;

	UPROPERTY()
	int32 NumberOfWaveSegments;

};

USTRUCT()
struct FFortSpawnAIRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid SpawnGroupInstanceGuid;

	UPROPERTY()
	int32 EnemyIndex;

	UPROPERTY()
	FVector SpawnLocation;

	UPROPERTY()
	FRotator SpawnRotation;

	UPROPERTY()
	TObjectPtr<AActor> SpawnPoint;

	UPROPERTY()
	TArray<TObjectPtr<UFortAbilitySet>> AbilitySetsToGrantOnSpawn;

	UPROPERTY()
	bool bIgnoreCollisionWhenSpawning;

	UPROPERTY()
	float SpawnDelay;

};

USTRUCT(BlueprintType)
struct FFortAISpawnerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid SpawnGroupInstanceGuid;

	UPROPERTY()
	FFortSpawnAIRequest ReservedSpawnRequest;

};

USTRUCT()
struct FFortCurveSequenceInstanceInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortEncounterAIDirectorFactor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float CurrentValue;

	UPROPERTY()
	float AccumulatedPeriodValue;

	UPROPERTY()
	float TotalPeriodTime;

};

USTRUCT()
struct FFortGoalActorEncounterDataManagerPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> GoalActor;

	UPROPERTY()
	TObjectPtr<AFortAIDirectorDataManager> EncounterDataManager;

};

USTRUCT()
struct FFortIntensityCurve : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	TObjectPtr<UCurveTable> IntensityCurveTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	FName IntensityCurveTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float LowPlayerPerformancePeakIntensityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float NormalPlayerPerformancePeakIntensityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float HighPlayerPerformancePeakIntensityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float MaxRampTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float FadeEndIntensityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float StartIntensityOffsetFloor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float EndIntensityOffsetFloor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float StartIntensityOffsetCeiling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float EndIntensityOffsetCeiling;

};

USTRUCT()
struct FFortIntensityCurveSequenceInstanceInfo : public FFortCurveSequenceInstanceInfo
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortIntensityCurveSequence> IntensityCurveSequence;

};

USTRUCT()
struct FFortSpawnPointsPercentageCurve : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	TObjectPtr<UCurveTable> SpawnPointsPercentageCurveTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	FName SpawnPointsPercentageCurveTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntensityCurve")
	float MaxRampTime;

};

USTRUCT()
struct FFortSpawnPointsPercentageCurveSequenceInstanceInfo : public FFortCurveSequenceInstanceInfo
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortSpawnPointsPercentageCurveSequence> SpawnPointsPercentageCurveSequence;

};

USTRUCT()
struct FSpawnGroupInstanceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortAISpawnGroup> SpawnGroup;

	UPROPERTY()
	int32 NumActiveAlive;

	UPROPERTY()
	int32 TotalGroupCost;

	UPROPERTY()
	int32 SpawnPointsUsed;

	UPROPERTY()
	int32 NumEngaged;

	UPROPERTY()
	bool bReadyToSpawn;

	UPROPERTY()
	bool bFinishedSpawning;

	UPROPERTY()
	FGuid GroupGuid;

	UPROPERTY()
	int32 EnemySpawnDataIndex;

	UPROPERTY()
	float TimeSelected;

	UPROPERTY()
	int32 NextEnemyToSpawnIndex;

	UPROPERTY()
	FGameplayTagContainer UpgradeTags;

	UPROPERTY()
	FFortAISpawnGroupUpgradeUIData UpgradeUIData;

	UPROPERTY()
	TArray<FFortAIPawnUpgradeData> PawnUpgrades;

	UPROPERTY()
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> ModifiersForAllPawns;

	UPROPERTY()
	TArray<TObjectPtr<AFortAIPawn>> PawnList;

	UPROPERTY()
	TArray<TObjectPtr<AFortAIPawn>> LifespanExpiredList;

};

USTRUCT()
struct FSpawnGroupProgression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Spawning")
	TObjectPtr<UFortAISpawnGroup> SpawnGroup;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortAIEncounterInfo : public UObject, public INavAgentInterface, public IGameplayMutatorObserverInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Encounter")
	UFortAIAssignment* CreateEncounterAssignment(UFortAIAssignmentSettings* AssignmentSettings, AActor* GoalActor);

	UFUNCTION(BlueprintCallable, Category="Encounter")
	void DespawnPendingAndCurrentAI();

	UFUNCTION(BlueprintPure, Category="AISpawner")
	bool EncounterHasReservedSpawnRequestForEnemySpawner(AActor* EnemySpawner) const;

	UFUNCTION(BlueprintPure, Category="Spawning")
	bool GetCurrentSpawnAreaDirections(TArray<TEnumAsByte<EFortEncounterDirection::Type>>& OutDirections) const;

	UFUNCTION(BlueprintPure)
	void GetEncounterAssignmentGoalActors(TArray<AActor*>& OutGoalActors) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="FortAIDirectorDataManager")
	AFortAIDirectorDataManager* GetEncounterDataManager();

	UFUNCTION(BlueprintPure, Category="FortAIEncounterInfo")
	void GetEncounterGameplayTags(FGameplayTagContainer& OutEncounterTags) const;

	UFUNCTION(BlueprintPure)
	AActor* GetEncounterQueryActor() const;

	UFUNCTION(BlueprintPure)
	void GetEncounterRifts(TArray<ABuildingRift*>& OutRifts) const;

	UFUNCTION(BlueprintCallable, Category="Encounter")
	float GetEncounterTimeSeconds();

	UFUNCTION(BlueprintPure, Category="Encounter")
	int32 GetPawnNumberLimit() const;

	UFUNCTION(BlueprintCallable, Category="AISpawner")
	bool GroupHasAIRemainingToSpawn(const FFortAISpawnerData& FortAISpawnerData);

	UFUNCTION()
	void NotifyRiftDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintImplementableEvent, Category="Encounter")
	void OnFadeStarted();

	UFUNCTION()
	void OnGoalTakeDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintImplementableEvent, Category="Encounter")
	void OnPeakStarted();

	UFUNCTION(BlueprintImplementableEvent, Category="Encounter")
	void OnRampStarted();

	UFUNCTION(BlueprintImplementableEvent, Category="Encounter")
	void OnRestStarted();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AISpawner")
	void RegisterAISpawner(AActor* InAISpawner);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="EncounterActivation")
	void RequestActivation(int32 ActivationDelay = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="EncounterActivation")
	void SetEncounterActivationState(bool bEncounterActivityState);

	UFUNCTION(BlueprintCallable, Category="Encounter")
	void SetNukeWavesAtEncounterEnd(bool bNuke);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Encounter")
	void SetPawnNumberLimit(int32 InPawnNumberLimit);

	UFUNCTION(BlueprintCallable, Category="AISpawner")
	AFortAIPawn* SpawnAIPawnReservedForEnemySpawner(AActor* EnemySpawner, FVector SpawnLocation, FRotator SpawnRotation);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Encounter")
	void SpawnTestAIGroup(const UFortAISpawnGroup* SpawnGroupToSpawn, FVector SpawnLocation, FRotator SpawnRotation, AActor* SpawnSource, const TArray<UFortAbilitySet*> AbilitySetsToGrantOnSpawn, FFortAISpawnGroupUpgradeData UpgradeData, bool bAllowAssigningToExternalSpawners, float SecondsBetweenSpawns = 1.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AISpawner")
	void UnRegisterAISpawner(AActor* InAISpawner);

	UPROPERTY(BlueprintAssignable)
	FOnEncounterSpawnDirectionsChosen OnEncounterSpawnDirectionsChosen;

	UPROPERTY()
	float NextRiftReplacementTime;

	UPROPERTY()
	float NextSpawningTime;

	UPROPERTY()
	FFortAIEncounterSpawnGroupCapsProfile EncounterSpawnGroupCapsProfile;

	UPROPERTY()
	TArray<FFortAIEncounterSpawnGroupCapsCategory> AdditionalSpawnGroupCapsCategories;

	UPROPERTY()
	FFortAIEncounterSpawnPointsProfile EncounterSpawnPointsProfile;

	UPROPERTY()
	TArray<FFortAISpawnGroupUpgradeData> AvailableUpgrades;

	UPROPERTY()
	TArray<FCurveTableRowHandle> PawnDifficultyLevelModifiers;

	UPROPERTY()
	TArray<FFortAIBaseLootDropRow> BaseLootDropRows;

	UPROPERTY()
	TArray<FFortAILootDropModifierRow> LootDropModifierRows;

	UPROPERTY(Transient)
	bool bRequiresReinitializationFromProfile;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	FCurveTableRowHandle DesiredHostilityCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pacing")
	TObjectPtr<UFortIntensityCurveSequenceProgression> IntensitySequenceProgression;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	float AliveMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	TEnumAsByte<EFortEncounterSpawnLimitType::Type> SpawnLimitType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	int32 SpawnLimit;

	UPROPERTY()
	int32 PawnNumberLimitProgress;

	UPROPERTY()
	int32 SpawnPointsLimitProgress;

	UPROPERTY()
	bool bSpawnLimitReached;

	UPROPERTY()
	bool bHasSpawnedAllBurstSpawnAI;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	bool bOverrideAliveCounts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing", meta=(EditCondition="bOverrideAliveCounts"))
	int32 MinAliveOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing", meta=(EditCondition="bOverrideAliveCounts"))
	int32 MaxAliveOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	float HostilityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	float PeakTimeSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	float BreatherTimeSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	float MaxRampTimeSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	float MinTimeBetweenBreathesSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	float MaxFadeTimeSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	float FadeEndIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float FadeEndRemainingSpawnPointsPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float CompletionPercentageToDisableBreathers;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterAllEnemiesKilled OnEncounterAllEnemiesKilled;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterEnemySpawned OnEncounterEnemySpawned;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterEnemySpawnFailed OnEncounterEnemySpawnFailed;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterAllBurstEnemiesSpawned OnEncounterAllBurstEnemiesSpawned;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterCompleted OnEncounterCompleted;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterPawnDied OnEncounterPawnDied;

	UPROPERTY()
	FOnEncounterSpawnedFinalEnemy OnEncounterSpawnedFinalEnemy;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterRiftSpawned OnEncounterRiftSpawned;

	UPROPERTY(BlueprintAssignable)
	FOnBuildingRiftBlockedShouldDie OnBuildingRiftBlockedShouldDie;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visuals")
	bool bDisplayThreatVisuals;

	UPROPERTY(EditAnywhere, Category="Utilities", meta=(ArraySizeEnum="/Script/FortniteGame.EFortAIUtility", ClampMax="10.0", ClampMin="0.0", UIMax="10.0", UIMin="0.0"))
	float BaseDesiredUtilities[16];

	UPROPERTY(EditAnywhere, Category="Utilities", meta=(ArraySizeEnum="/Script/FortniteGame.EFortAIUtility"))
	FGameplayTagContainer UtilitiesRequiredTags[16];

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Utilities")
	FGameplayTagContainer InjectedTagForUtilityCheck;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning", meta=(ClampMax="9999.0", ClampMin="1.0", UIMax="9999.0", UIMin="1.0"))
	float MaxLargeSpawnGroupDiscountInterval;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float MaxSelectionToSpawningDelay;

	UPROPERTY()
	TArray<FUtilityTypeFloatPair> CurrentDesiredUtilities;

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortAIUtility"))
	float UtilityRecentSelectionPenalties[16];

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortAIUtility"))
	float UtilityEffectivenessMeasurements[16];

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Utilities")
	FCurveTableRowHandle UtilityEffectivenessMultiplierCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Utilities")
	float UtilityEffectivenessInfluenceCap;

	UPROPERTY()
	TArray<FUtilityTypeFloatPair> CurrentTopUtilityPercentages;

	UPROPERTY(Transient)
	TArray<TEnumAsByte<EFortAIUtility::Type>> UsedTopUtilities;

	UPROPERTY(Transient)
	TArray<TEnumAsByte<EFortAIUtility::Type>> CurrentlySelectedFreeUtilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Utilities")
	int32 NumUtilitiesConsidered;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Utilities")
	float ReactivityPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Utilities")
	bool bAdjustUtilitiesDuringRest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	bool bDespawnAIsDuringRest;

	UPROPERTY()
	float LastPlayerCombatFactorUpdateTime;

	UPROPERTY()
	float LastUtilityAdjustTime;

	UPROPERTY()
	float LastSpawnPointAdjustmentTime;

	UPROPERTY()
	float LastLargeGroupSpawnTime;

	UPROPERTY()
	TArray<FAIEncounterSpawnGroupWeights> EnemySpawnData;

	UPROPERTY()
	FFortAIEncounterPIDController EncounterPIDController;

	UPROPERTY()
	int32 CurrentSpawnPointsCap;

	UPROPERTY()
	int32 CurrentSpawnPointsUsed;

	UPROPERTY()
	int32 FailSafeMinSpawnPoints;

	UPROPERTY()
	TArray<FSpawnGroupInstanceInfo> ActiveSpawnGroups;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RelevantDistances")
	float EncounterEngagementDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RelevantDistances")
	float MinRelevantBuildingDamagedDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RelevantDistances")
	float MaxRelevantBuildingDamagedDistance;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentGroupSpawnPoint;

	UPROPERTY()
	TEnumAsByte<EFortEncounterState::Type> EncounterState;

	UPROPERTY()
	TEnumAsByte<EFortEncounterPacingState::Type> PacingState;

	UPROPERTY()
	float LastPacingStateTransitionTime;

	UPROPERTY()
	FFortAIEncounterWaveProgressEstimation WaveProgressEstimate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Pacing")
	float DesiredDifficultyLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Pacing")
	float DifficultyLevelOverride;

	UPROPERTY(Transient)
	TObjectPtr<AFortAIDirector> MyAIDirector;

	UPROPERTY()
	TArray<FFortGoalActorEncounterDataManagerPair> DataManagers;

	UPROPERTY(Transient)
	TObjectPtr<AActor> TargetObjective;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	bool bOnlyActiveAtNight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	int32 NumRiftsToUse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	int32 MinRiftsToUse;

	UPROPERTY()
	int32 NumRiftsUsed;

	UPROPERTY()
	FFortEncounterSettings EncounterSettings;

	UPROPERTY()
	float EncounterStartTime;

	UPROPERTY()
	float HostilityCurveStartTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	FEncounterEnvironmentQueryInfo DefaultEnvironmentQueryInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	FEncounterEnvironmentQueryInfo FallbackEnvironmentQueryInfo;

	UPROPERTY()
	FEncounterEnvironmentQueryInfo OverrideEnvironmentQueryInfo;

	UPROPERTY()
	FEncounterEnvironmentQueryInfo CurrentEnvironmentQueryInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	bool bNukeWavesAtDaybreak;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	bool bNukeWavesAtEncounterEnd;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	bool bNukeWavesAtEncounterDeactivation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pacing")
	int32 ActiveEnemyCap;

	UPROPERTY(BlueprintReadOnly, Category="OldSpawnSystem")
	float CurrentHostilityLevel;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterRampStarted OnEncounterRampStarted;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterPeakStarted OnEncounterPeakStarted;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterFadeStarted OnEncounterFadeStarted;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterRestStarted OnEncounterRestStarted;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterCombatParticipation OnEncounterCombatParticipation;

	UPROPERTY(BlueprintAssignable)
	FOnEncounterOptionsChanged OnEncounterOptionsChanged;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiftType")
	TSubclassOf<ABuildingRift> RiftClassTemplate;

	UPROPERTY()
	TArray<TObjectPtr<UFortAIAssignment>> EncounterAssignments;

	UPROPERTY(EditAnywhere, Category="GoalManager")
	TObjectPtr<UFortAIAssignmentSettings> DefaultEncounterAssignmentSettings;

	UPROPERTY(Transient)
	int32 MaxActiveAlive;

	UPROPERTY(Transient)
	int32 MaxSpawnPointsUsed;

protected:
	UFUNCTION()
	void OnEncounterPawnDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	TObjectPtr<UFortAISpawnGroupProgressionInfo> SpawnGroupProgressionInfo;

	UPROPERTY()
	FFortSpawnPointsPercentageCurveSequenceInstanceInfo SpawnPointsPercentageCurveSequence;

	UPROPERTY()
	FFortIntensityCurveSequenceInstanceInfo IntensityCurveSequence;

	UPROPERTY()
	float BurstSpawnPointsPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	float SpawnPointsMultiplier;

	UPROPERTY()
	bool bUseBreathers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	FCurveTableRowHandle LowPlayerPerformanceBreatherTimeSecondsCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	FCurveTableRowHandle NormalPlayerPerformanceBreatherTimeSecondsCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pacing")
	FCurveTableRowHandle HighPlayerPerformanceBreatherTimeSecondsCurve;

	UPROPERTY()
	float EncounterTimeSeconds;

	UPROPERTY()
	TArray<FUtilityTypeFloatPair> LockedUtilityValues;

	UPROPERTY()
	int32 NumFreeUtilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Utilities", meta=(EditCondition="!bAdjustUtilitiesDuringRest"))
	float UtilityAdjustmentPeriodSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float MinSpawnDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	float MaxSpawnDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	int32 NumDirections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	bool bChangeDirectionsOnRest;

	UPROPERTY()
	float SpawnPointsPercentageLimit;

	UPROPERTY()
	int32 PawnNumberLimit;

	UPROPERTY()
	FFortEncounterPawnNumberCaps PawnNumberCaps;

	UPROPERTY(EditDefaultsOnly, Category="Spawning")
	float SpawningIntervalSeconds;

	UPROPERTY(EditDefaultsOnly, Category="Spawning")
	float PreSpawnRequeryTime;

	UPROPERTY()
	FFortEncounterSettingsFixedPace EncounterSettingsFixed;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterInfo")
	bool bUseAILifespans;

	UPROPERTY()
	bool bTrackCombatParticipation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GameplayTags")
	FGameplayTagContainer ModifierTags;

	UPROPERTY(Transient)
	TArray<FFortAIEncounterTimedModifierTags> TimedModifierTags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GameplayTags")
	FGameplayTagContainer GameContextTags;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameplayMutator_AILevelVariance> AILevelMutator;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortGameplayMutator_AIEncounterModifierTags>> EncounterModifierTagsMutators;

private:
	UFUNCTION()
	void OnGameDifficultyChanged();

	UPROPERTY(Transient)
	TMap<TWeakObjectPtr<AActor>, FFortAISpawnerData> ExternalAISpawners;

	UPROPERTY()
	FFortAIEncounterQueryData EncounterQueryData;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterRiftManager> RiftManager;

	UPROPERTY(Transient)
	FString AssociatedMissionName;

	UPROPERTY()
	TEnumAsByte<EFortMissionType::Type> AssociatedMissionType;

	UPROPERTY()
	uint8 bCanBeActive : 1;

	UPROPERTY(Transient)
	TObjectPtr<UCurveFloat> OverrideSpawnPointsCurve;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterInfo")
	bool bSendFullAnalyticsReport;

};

