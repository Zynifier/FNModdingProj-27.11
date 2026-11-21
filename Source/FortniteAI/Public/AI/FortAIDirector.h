// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"
#include "EnvironmentQuery/EQSQueryResultSourceInterface.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "AI/FortPatrolWardInterface.h"
#include "AI/FortPendingSpawnInfo.h"
#include "FortAIUtility.h"
#include "FortCombatTypes.h"
#include "FortEncounterDirectionEnum.h"
#include "FortEncounterEnvironmentQueryInfo.h"
#include "FortInitializationInterface.h"
#include "Missions/MissionTypes.h"
#include "FortAIDirector.generated.h"

class AActor;
class ABuildingProp_AISpawner;
class ABuildingRift;
class AFortAIController;
class AFortAIPawn;
class AFortAthenaAIBotController;
class AFortPawn;
class AFortPlayerControllerZone;
class AFortPlayerPawn;
class IFortAthenaAILODSettings;
class IFortPatrolWardInterface;
class UBuildingEditModeMetadata;
class UCurveFloat;
class UEQSRenderingComponent;
class UFortAIDirectorDataTrackingSettings;
class UFortAIEncounterInfo;
class UFortAIEncounterSequence;
class UFortAISpawnGroupCapsCategorySet;
class UFortAISpawnGroupUpgrade;
class UFortAISpawnGroupUpgradeProbabilities;
class UFortDifficultyEncounterSettings;
class UObject;
class UReporterGraph;
enum class EFortDayPhase : uint8;
enum class EWardAffectType : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EDespawnAIType : uint8
{
	Relevancy = 0,
	Distance = 1,
};

USTRUCT()
struct FFortAIBaseLootDropRow : public FTableRowBase
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	FString AITags;
#endif

	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	int32 Priority;

	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	float ItemDropChance;

	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	FName WorldItemLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	FName WorldItemInstancedLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	FName AccountItemLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="LootDrop", meta=(DataTableImportOptional))
	FGameplayTagContainer AITagsContainer;

};

USTRUCT(BlueprintType)
struct FFortAIEncounterPIDController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PID")
	float ProportionalGain;

	UPROPERTY(BlueprintReadOnly, Category="PID")
	float IntegralGain;

	UPROPERTY(BlueprintReadOnly, Category="PID")
	float DerivativeGain;

};

USTRUCT(BlueprintType)
struct FFortAIEncounterPIDControllerSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PID")
	FCurveTableRowHandle ProportionalGain;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PID")
	FCurveTableRowHandle IntegralGain;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PID")
	FCurveTableRowHandle DerivativeGain;

};

USTRUCT()
struct FFortAIEncounterPawnDifficultyLevelModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterPawnDifficultyLevelModifier")
	FGameplayTagQuery EncounterTagRequirementsQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterPawnDifficultyLevelModifier")
	FCurveTableRowHandle DifficultyLevelModifierCurve;

};

USTRUCT(BlueprintType)
struct FFortAIEncounterQueryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIEncounterQueryData")
	TArray<FVector> QueryLocations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIEncounterQueryData")
	TArray<TObjectPtr<AActor>> QueryActors;

};

USTRUCT()
struct FFortAIEncounterRequirements
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterRequirements")
	TEnumAsByte<EFortMissionType::Type> AssociatedMissionType;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterRequirements")
	FGameplayTagQuery TagQuery;

};

USTRUCT()
struct FFortAIEncounterSpawnGroupCap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCap")
	FCurveTableRowHandle MinSpawnGroupNumberCap;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCap")
	FCurveTableRowHandle MaxSpawnGroupNumberCap;

};

USTRUCT()
struct FFortAIEncounterSpawnGroupCapsCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCapsCategory")
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCapsCategory")
	bool bApplyGroupPopulationCurveToCategoryMax;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCapsCategory")
	FCurveTableRowHandle InitialSpawnGroupAvailabilityDelaySeconds;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCapsCategory")
	FCurveTableRowHandle SpawnGroupAvailabilityDelaySeconds;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCapsCategory")
	FGameplayTagQuery UnlockingTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCapsCategory")
	TArray<FFortAIEncounterSpawnGroupCap> SpawnGroupCapsPerPlayerCount;

	UPROPERTY()
	float InitialSpawnGroupAvailabilityTime;

	UPROPERTY()
	float NumActiveCategorySpawnGroups;

	UPROPERTY()
	TArray<float> SpawnGroupAvailabilityTimes;

	UPROPERTY()
	int32 NumSpawnGroupAvailable;

	UPROPERTY()
	TObjectPtr<UObject> CategorySource;

};

USTRUCT()
struct FFortAIEncounterSpawnGroupCapsProfile
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCapsProfile")
	FGameplayTagContainer EncounterTypeTags;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnGroupCapsProfile")
	TArray<FFortAIEncounterSpawnGroupCapsCategory> PopulationCategories;

};

USTRUCT()
struct FFortAIEncounterSpawnPointsProfile
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnPointsProfile")
	FGameplayTagContainer EncounterTypeTags;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnPointsProfile")
	TArray<FCurveTableRowHandle> MaxSpawnPointsPerPlayerCount;

	UPROPERTY(EditDefaultsOnly, Category="FortAIEncounterSpawnPointsProfile")
	TArray<FCurveTableRowHandle> MinSpawnPointsPerPlayerCount;

};

USTRUCT()
struct FFortAILootDropModifierRow : public FTableRowBase
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	FString AITags;
#endif

	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	int32 Priority;

	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	float ItemDropChanceMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="LootDrop")
	FName WorldItemLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="LootDrop", meta=(DataTableImportOptional))
	FGameplayTagContainer AITagsContainer;

};

USTRUCT()
struct FFortAILootDropModifiers
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAILootDropModifiers")
	FFortAIEncounterRequirements Requirements;

	UPROPERTY(EditDefaultsOnly, Category="FortAILootDropModifiers")
	TArray<FDataTableRowHandle> LootDropModifierRows;

};

USTRUCT()
struct FFortAIPawnUpgradeProbability
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnUpgradeProbability")
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnUpgradeProbability")
	FCurveTableRowHandle UpgradeProbability;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortAISpawnGroupUpgradeData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeData")
	TSubclassOf<UFortAISpawnGroupUpgrade> SpawnGroupUpgrade;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeData")
	TSubclassOf<UFortAISpawnGroupUpgradeProbabilities> UpgradeProbabilities;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeData")
	TSubclassOf<UFortAISpawnGroupCapsCategorySet> SpawnGroupCapsCategories;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeData")
	FGameplayTagQuery EncounterTagRequirementsQuery;

};

USTRUCT()
struct FFortEncounterGroupLimitData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 DesiredPawnNumCap;

	UPROPERTY()
	int32 RemainingDesiredLimit;

	UPROPERTY()
	int32 CurrentEncounterLimit;

};

USTRUCT()
struct FFortEncounterPawnNumberCaps
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortEncounterPawnNumberCaps")
	bool bApplyPawnNumberCaps;

	UPROPERTY(EditDefaultsOnly, Category="FortEncounterPawnNumberCaps", meta=(EditCondition="bApplyPawnNumberCaps"))
	TArray<FCurveTableRowHandle> PawnCapsPerPlayerCount;

};

USTRUCT()
struct FFortPendingStoppedEncounterData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> Encounter;

	UPROPERTY()
	EFortObjectiveStatus ObjectiveStatus;

	UPROPERTY()
	bool bForceDestroyAI;

	UPROPERTY()
	bool bEncounterCompletedSuccessfully;

};

USTRUCT(BlueprintType)
struct FFortPlayerPerformanceEstimateSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPerformance")
	FCurveTableRowHandle PlayerPerformanceEstimateTransformMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPerformance")
	FCurveTableRowHandle PlayerPerformanceEstimateTransformOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPerformance")
	FCurveTableRowHandle PlayerPerformanceEstimateTransformMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPerformance")
	float EncounterPlayerPerformanceWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPerformance")
	float PreviousWavePlayerPerformanceWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPerformance")
	float CampaignPlayerPerformanceWeight;

};

USTRUCT(BlueprintType)
struct FIntensityContribution
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityContribution")
	TEnumAsByte<EFortCombatFactors::Type> CombatFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityContribution")
	EFortAIDirectorFactor ContributingAIDirectorFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityContribution")
	float MaxContribution;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityContribution")
	bool bModifyContributionByCompletionPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityContribution", meta=(EditCondition="bModifyContributionByCompletionPercentage"))
	FCurveTableRowHandle CompletionPercentageInitialMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityContribution", meta=(EditCondition="bModifyContributionByCompletionPercentage"))
	FCurveTableRowHandle CompletionPercentageToStartReducingMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityContribution", meta=(EditCondition="bModifyContributionByCompletionPercentage"))
	FCurveTableRowHandle CompletionPercentageToStopReducingMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityContribution")
	bool bModifyByNumberOfCriticalEncounterGoals;

};

USTRUCT(BlueprintType)
struct FIntensityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityData")
	TArray<FIntensityContribution> ContributingFactors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FIntensityData")
	float ContributionsTotal;

	UPROPERTY(EditAnywhere, Category="FIntensityData")
	TArray<TObjectPtr<UBuildingEditModeMetadata>> ExceptionEditModes;

	UPROPERTY(EditAnywhere, Category="FIntensityData", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float ExceptionEditModeWeight;

};

USTRUCT()
struct FLODAIUpdateInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FUtilityContribution
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FUtilityContribution", meta=(ClampMax="10.0", ClampMin="-10.0", UIMax="10.0", UIMin="-10.0"))
	float MaxContribution;

	UPROPERTY(EditAnywhere, Category="FUtilityContribution")
	TEnumAsByte<EFortCombatFactors::Type> ContributingFactor;

	UPROPERTY(EditAnywhere, Category="FUtilityContribution")
	EFortAIDirectorFactor ContributingAIDirectorFactor;

	UPROPERTY(EditAnywhere, Category="FUtilityContribution")
	TEnumAsByte<EFortFactorContributionType::Type> ContributionType;

};

USTRUCT()
struct FUtilityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FUtilityData")
	TArray<FUtilityContribution> ContributingFactors;

	UPROPERTY(VisibleAnywhere, Category="FUtilityData")
	float ContributionsTotal;

	UPROPERTY(EditAnywhere, Category="FUtilityData")
	bool bApplyRecentSelectionPenalty;

	UPROPERTY(EditAnywhere, Category="FUtilityData", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float RecentlySelectedPenaltyPercentage;

	UPROPERTY(EditAnywhere, Category="FUtilityData", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float PenaltyFallOffRate;

	UPROPERTY(EditAnywhere, Category="FUtilityData")
	FString DebugGraphName;

	UPROPERTY(EditAnywhere, Category="FUtilityData")
	FLinearColor DebugGraphColor;

};

USTRUCT()
struct FUtilityTypeFloatPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<EFortAIUtility::Type> Utility;

	UPROPERTY()
	float Value;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "Actor", "Advanced", "Replication"))
class AFortAIDirector : public AActor, public IFortInitializationInterface, public IEQSQueryResultSourceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	virtual void Activate();

	UFUNCTION(BlueprintPure, Category="EncounterDirection")
	static TArray<TEnumAsByte<EFortEncounterDirection::Type>> ConvertInvalidDirectionsToValidDirections(TArray<TEnumAsByte<EFortEncounterDirection::Type>> InvalidDirections);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	virtual void Deactivate();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AI")
	void GetAmbientThreatEncounterSpawnLocations(TArray<FVector>& AmbientThreatEncounterSpawnLocations) const;

	UFUNCTION(BlueprintPure, Category="EncounterDirection")
	static EFortEncounterDirection::Type GetEncounterDirectionFromVector(FVector DirectionVector);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	int32 GetNumActiveEncounters();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AI")
	virtual int32 GetNumPlayers() const;

	UFUNCTION(BlueprintPure, Category="AI")
	int32 GetPlayerPawnsInRange(const FVector& Origin, const float Radius, TArray<AFortPlayerPawn*>& OutPawns) const;

	UFUNCTION(BlueprintPure, Category="AI")
	TArray<ABuildingRift*> GetRiftsFromClosestActiveEncounterTo(AActor* Target) const;

	UFUNCTION(BlueprintPure, Category="EncounterDirection")
	static FVector GetVectorFromEncounterDirection(EFortEncounterDirection::Type Direction);

	UFUNCTION(BlueprintPure, Category="AI")
	bool IsAnyActiveEncounterRelevantToDefender(AFortAIPawn* Defender) const;

	UFUNCTION(BlueprintPure, Category="AI")
	bool IsAnyActiveEncounterRelevantToPlayer(const AFortPlayerPawn* Player) const;

	UFUNCTION(BlueprintPure, Category="AI")
	bool IsAnyAIRelevantToPlayer(AFortPlayerPawn* Player) const;

	UFUNCTION(BlueprintPure, Category="AI")
	bool IsAnyEncounterGoalWithinDistanceOfPoint(const FVector& Point, float Distance, bool bOnlyActiveEncounters) const;

	UFUNCTION(BlueprintPure, Category="AI")
	bool IsLineTooCloseToPatrolWards(const FVector& LineStart, const FVector& LineEnd) const;

	UFUNCTION(BlueprintPure, Category="AI")
	bool IsPointTooCloseToPatrolWards(const FVector& Point, const EWardAffectType WardEffectTypeFilter = EWardAffectType::AffectsBothStartAndEndPoints) const;

	UFUNCTION()
	virtual void OnDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnDirectorDeactivated();

	UFUNCTION(BlueprintImplementableEvent, Category="Encounter")
	void OnFadeStarted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnPawnDied(AFortAIPawn* KilledPawn);

	UFUNCTION(BlueprintImplementableEvent, Category="Encounter")
	void OnPeakStarted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnPlayerDied(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnPlayerSpawn(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintImplementableEvent, Category="Encounter")
	void OnRampStarted();

	UFUNCTION(BlueprintImplementableEvent, Category="Encounter")
	void OnRestStarted();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void PostDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void ReceivePawnSpawned(AFortPawn* SpawnedPawn);

	UFUNCTION(BlueprintCallable, Category="AI")
	void RegisterPatrolWard(TScriptInterface<IFortPatrolWardInterface> PatrolWard);

	UFUNCTION(BlueprintCallable, Category="AIEncounter")
	UFortAIEncounterInfo* StartEncounter(UPARAM(ref) FString& EncounterInstigator, UFortDifficultyEncounterSettings* DifficultyEncounterSettings, FFortAIEncounterQueryData OptionalQueryData);

	UFUNCTION(BlueprintCallable, Category="AI")
	void UnregisterPatrolWard(TScriptInterface<IFortPatrolWardInterface> PatrolWard);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Legacy")
	FCurveTableRowHandle MaxAliveCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Legacy")
	FCurveTableRowHandle MinAliveCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Intensity")
	FIntensityData IntensityInfo;

	UPROPERTY(BlueprintReadOnly, Category="Intensity")
	FFortAIEncounterPIDController AIDirectorPIDController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Intensity")
	FFortAIEncounterPIDControllerSettings PIDControllerSettings;

	UPROPERTY(EditAnywhere, Category="Utilities", meta=(ArraySizeEnum="/Script/FortniteGame.EFortAIUtility"))
	FUtilityData UtilityContributionData[16];

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Utilities")
	float UnreachableLocationPathCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Intensity")
	FFortPlayerPerformanceEstimateSettings PlayerPerformanceEstimateSettings;

	UPROPERTY()
	uint8 bUsePrototypeEnemies : 1;

	UPROPERTY()
	bool bForceByPassNavMeshForAISpawning;

	UPROPERTY(Transient)
	TArray<TEnumAsByte<EFortEncounterDirection::Type>> DebugEncounterDirections;

	UPROPERTY()
	TObjectPtr<UReporterGraph> IntensityGraph;

	UPROPERTY()
	TObjectPtr<UReporterGraph> UtilitiesGraph;

	UPROPERTY()
	TObjectPtr<UReporterGraph> PIDValuesGraph;

	UPROPERTY()
	TObjectPtr<UReporterGraph> PIDContributionsGraph;

	UPROPERTY(Transient)
	uint8 bNightActive : 1;

	UPROPERTY()
	uint8 bAIDisabled : 1;

	UPROPERTY()
	uint8 bRegisteredForDayPhaseChange : 1;

	UPROPERTY(Transient)
	uint8 bUseSpawnCap : 1;

	UPROPERTY(BlueprintReadWrite, Category="WorldState")
	int32 NightCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Encounters")
	float NightEncounterFailureBreatherTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Encounters", meta=(DisplayName="EncounterUpdateInterval"))
	float EncounterPawnSpawnInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Encounters")
	TSubclassOf<UFortAIEncounterInfo> DefaultNightEncounter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Encounters")
	TSubclassOf<UFortAIEncounterInfo> DummyDebugEncounter;

	UPROPERTY(EditAnywhere, Category="Encounters")
	TSubclassOf<UFortAIEncounterInfo> BaseEncounterClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Encounters")
	int32 MaxActiveAlive;

	UPROPERTY()
	int32 NumActiveAlive;

	UPROPERTY()
	int32 NumPendingCapRelevantAI;

	UPROPERTY()
	TArray<FPendingSpawnInfo> PendingSpawns;

	UPROPERTY(EditDefaultsOnly, Category="AmbientThreat")
	int32 NumWorldSubdivides;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dormant")
	float MinAISpawnDistanceFromPlayers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Debug")
	int32 DebugGraphUpdateFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LOD")
	float MaxNormalLODDistanceToPlayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI")
	float AIRelevantDistanceToPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float EncounterRelevantDistanceToPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float EncounterRelevantDistanceToDefender;

	UPROPERTY(Transient)
	int32 MaxTotalActiveAliveAI;

	UPROPERTY(Transient)
	int32 MaxEncounterActiveAliveAI;

	UPROPERTY(Transient)
	int32 MaxSPUsed;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIDirector")
	EDespawnAIType DespawnAIType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIDirector")
	float DespawnDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIDirector")
	float DespawnInterval;

	UPROPERTY(Transient)
	FGameplayTagContainer DebugSpawnAIGroupTags;

	UPROPERTY(Transient)
	FGameplayTagContainer DebugEncounterTags;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	float BurstSpawnThreatVisualsEndDelay;

	UPROPERTY(EditDefaultsOnly, Category="EncounterBudgets")
	TArray<FFortAIEncounterSpawnGroupCapsProfile> EncounterSpawnGroupCapSettings;

	UPROPERTY(EditDefaultsOnly, Category="EncounterBudgets")
	TArray<FFortAIEncounterSpawnPointsProfile> EncounterSpawnPointsSettings;

	UPROPERTY(EditDefaultsOnly, Category="GroupEnemyModifiers")
	TArray<FFortAIEncounterPawnDifficultyLevelModifier> EncounterPawnDifficultyLevelModifiers;

	UPROPERTY(EditDefaultsOnly, Category="SpawnGroupUpgrades")
	TArray<FFortAISpawnGroupUpgradeData> SpawnGroupUpgrades;

	UPROPERTY(EditDefaultsOnly, Category="SpawnGroupUpgrades")
	float GuaranteedUpgradeGroupUtilityBonus;

	UPROPERTY(EditDefaultsOnly, Category="Utilities", meta=(ArraySizeEnum="/Script/FortniteAI.EFortEncounterUtilityDesire"))
	float DiscreteEncounterUtilityDesireMappings[4];

	UPROPERTY(EditDefaultsOnly, Category="Utilities")
	TEnumAsByte<EFortAIUtility::Type> InitialDynamicUtilities[4];

	UPROPERTY(EditDefaultsOnly, Category="RiftPlacement", meta=(ArraySizeEnum="/Script/FortniteGame.EFortEncounterSpawnLocationPlacementMode"))
	FEncounterEnvironmentQueryInfo SpawnLocationPlacementQueries[4];

	UPROPERTY(EditDefaultsOnly, Category="RiftPlacement", meta=(ArraySizeEnum="/Script/FortniteGame.EFortEncounterSpawnLocationPlacementMode"))
	FEncounterEnvironmentQueryInfo SpawnLocationActorSearchQueries[4];

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DataTracking")
	TObjectPtr<UFortAIDirectorDataTrackingSettings> DataTrackingSettings;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	TArray<FDataTableRowHandle> BaseLootDropData;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	TArray<FFortAILootDropModifiers> LootDropModifiers;

	UPROPERTY(EditDefaultsOnly, Category="LootDrops")
	FGameplayTagQuery LootDropDenialQuery;

	UPROPERTY()
	uint8 bDebugEncounterQueries : 1;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerControllerZone>> PlayerControllersForBVTree;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawn>> PlayerPawnsForBVTree;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAIController>> AIControllersForBVTree;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAIPawn>> AIPawnsForBVTree;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAthenaAIBotController>> AIPlayerBotControllersForBVTree;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawn>> AIPlayerBotPawnsForBVTree;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortAthenaAIBotController>> AINonPlayerBotControllersForBVTree;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawn>> AINonPlayerBotPawnsForBVTree;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerPawn>> NonPlayerBotPawns;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerPawn>> PlayerBotPawns;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerPawn>> PlayerPawns;

	UPROPERTY()
	TArray<TObjectPtr<AFortAIPawn>> FortAIPawns;

	UPROPERTY(Config)
	bool bUseLODSettings;

	UPROPERTY(Transient)
	TScriptInterface<IFortAthenaAILODSettings> CachedLODSettingsManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="AI")
	bool bAsyncProcessUpdateAliveAIs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="AI")
	bool bAllowProcessPlayerTargeting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="AI")
	int32 MaxNumLODAIProcessPerFrame;

	UPROPERTY(EditDefaultsOnly, Category="FortAIDirector")
	FFortEncounterPawnNumberCaps DefaultEncounterPawnCaps;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AmbientThreat")
	FGameplayTagContainer AmbientThreatPreferredPlacementActorTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AmbientThreat")
	FGameplayTagContainer AmbientThreatRequiredPlacementActorTags;

	UPROPERTY()
	TArray<TObjectPtr<UFortAIEncounterInfo>> ActiveEncounters;

	UPROPERTY()
	TArray<TObjectPtr<UFortAIEncounterInfo>> InactiveEncounters;

	UPROPERTY()
	TArray<FFortPendingStoppedEncounterData> PendingStoppedEncounters;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> ActiveDefaultEncounter;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> ActiveDummyDebugEncounter;

	UPROPERTY()
	TArray<TObjectPtr<UFortAIEncounterSequence>> EncounterSequences;

	UPROPERTY(Transient)
	TArray<FUtilityTypeFloatPair> DebugEncounterTopUtilityPercentages;

	UPROPERTY(EditAnywhere, Category="Debug")
	TArray<TObjectPtr<UCurveFloat>> DebugEncounterSpawnPointsCurves;

	UPROPERTY()
	uint8 bDebugAllowEncounterModifierTags : 1;

	UPROPERTY(Transient)
	int32 SimulatedNumberOfPlayersForAIEncounters;

	UPROPERTY(Config)
	int32 MaxNumberOfEncounterGroups;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingProp_AISpawner>> RegisteredAISpawners;

private:
	UPROPERTY(EditDefaultsOnly, Config, Category="Spawning")
	int32 MaxAISpawnedPerFrame;

	UPROPERTY(EditDefaultsOnly, Config, Category="Spawning")
	int32 MaxAIDespawnedPerFrame;

	UPROPERTY(EditDefaultsOnly, Config, Category="Spawning")
	int32 DespawnAllAIMaxAIDespawnedPerFrame;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortAIPawn>> PendingDespawns;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UEQSRenderingComponent> EQSRenderingComp;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IFortPatrolWardInterface>> PatrolWards;

};

