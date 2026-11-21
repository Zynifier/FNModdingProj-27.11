// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "ScalableFloat.h"
#include "UObject/SoftObjectPath.h"
#include "WorldConditionQuery.h"
#include "Conditions/FortAthenaLivingWorldDespawnCondition.h"
#include "FortAthenaLivingWorldSpawnAction.h"
#include "FortAthenaLivingWorldEventData.generated.h"

class AActor;
class UEnvQuery;
class UFortAthenaSpawnerDataBase;

UENUM()
enum class ELivingWorldCalendarEventConditionBehavior : uint8
{
	/** The condition will check if the calendar event is active or not. */
	IsActive = 0,
	/** The condition will check if the calendar event is active and has reached a certain completion ratio. */
	Ratio = 1,
};

UENUM()
enum class ELivingWorldCalendarEventConditionRatioBehavior : uint8
{
	Less = 0,
	LessOrEqual = 1,
	Greater = 2,
	GreaterOrEqual = 3,
	InBetween = 4,
};

USTRUCT(BlueprintType)
struct FFortAthenaLivingWorldEventTagDensityRegistration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventTagDensityRegistration", meta=(Categories="Athena.AI.Lager.TagDensity"))
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventTagDensityRegistration")
	FScalableFloat Range;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventTagDensityRegistration")
	FScalableFloat DensityValue;

};

USTRUCT(BlueprintType)
struct FFortAthenaLivingWorldTagTimer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldTagTimer")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldTagTimer")
	FScalableFloat Duration;

};

USTRUCT(BlueprintType)
struct FFortAthenaLivingWorldActorSpawnDescription
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Spawner Data")
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY(EditAnywhere, Category="Spawner Data")
	TSoftClassPtr<UFortAthenaSpawnerDataBase> SpawnerData;

	UPROPERTY(EditAnywhere, Category="Spawner Data")
	FGameplayTagQuery SpawnerDataTagQuery;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FScalableFloat ActorDensityValue;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FScalableFloat DensityComputationRangeOverride;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	TArray<FFortAthenaLivingWorldEventTagDensityRegistration> TagDensityRegistrations;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	TArray<FFortAthenaLivingWorldTagTimer> PostDestructionTagDensityPersistenceDuration;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	bool bPreloadOnClient;

};

USTRUCT(BlueprintType)
struct FFortAthenaLivingWorldEventDataActorSpawnDescription : public FFortAthenaLivingWorldActorSpawnDescription
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Point Providers Filters")
	bool bSpawnAroundDefaultPoint;

	UPROPERTY(EditAnywhere, Category="Point Providers Filters", meta=(EditCondition="bSpawnAroundDefaultPoint"))
	bool bUpdateDefaultPosition;

	UPROPERTY(EditAnywhere, Category="Point Providers Filters", meta=(EditCondition="bSpawnAroundDefaultPoint"))
	bool bSharePreviousActorEQSResult;

	UPROPERTY(EditAnywhere, Category="LivingWorld", meta=(EditCondition="bSpawnAroundDefaultPoint"))
	TObjectPtr<UEnvQuery> SpawnAroundEnvironmentQuery;

	UPROPERTY(EditAnywhere, Category="LivingWorld", meta=(EditCondition="bSpawnAroundDefaultPoint"))
	TEnumAsByte<EEnvQueryRunMode::Type> SpawnAroundEnvironmentQueryRunMode;

	UPROPERTY(EditAnywhere, Category="LivingWorld", meta=(EditCondition="bSpawnAroundDefaultPoint", MetaClass="/Script/NavigationSystem.NavigationData"))
	FSoftClassPath SpawnAroundNavigationSourceOverride;

};

USTRUCT()
struct FLivingWorldCalendarEventCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LivingWorldCalendarEventCondition")
	FName CalendarEventName;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorldCalendarEventCondition")
	ELivingWorldCalendarEventConditionBehavior Behavior;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorldCalendarEventCondition")
	bool ShouldEventBeActive;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorldCalendarEventCondition")
	ELivingWorldCalendarEventConditionRatioBehavior RatioBehavior;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorldCalendarEventCondition")
	float RatioValue;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorldCalendarEventCondition")
	float RatioMaxValue;

};

USTRUCT()
struct FLivingWorldCalendarEventConditions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LivingWorldCalendarEventConditions")
	TArray<FLivingWorldCalendarEventCondition> Conditions;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorldCalendarEventConditions")
	bool IsActiveWithoutSeasonalManager;

};

USTRUCT(BlueprintType)
struct FPointProviderFilterEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Point Provider")
	FGameplayTagQuery ProviderFiltersTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Point Provider")
	FLivingWorldCalendarEventConditions CalendarEventConditions;

	UPROPERTY(EditDefaultsOnly, Category="Point Provider")
	FScalableFloat Weight;

};

UCLASS(BlueprintType, Blueprintable)
class LAGERRUNTIME_API UFortAthenaLivingWorldEventData : public UDataAsset
{
	GENERATED_BODY()

private:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | NPC Editor")
	void SetupSimpleActorDescription(const FGameplayTag& SpawnerDataTag);
#endif

	UPROPERTY(EditDefaultsOnly, Category="TimeOfDay Filters", meta=(BitMask, BitmaskEnum="/Script/FortniteGame.EFortDayPhase"))
	int32 TimeOfDayFilters;

	UPROPERTY(EditAnywhere, Category="Water Level")
	float WaterLevelIndexMin;

	UPROPERTY(EditAnywhere, Category="Water Level")
	float WaterLevelIndexMax;

	UPROPERTY(EditAnywhere, Category="Activation")
	FWorldConditionQueryDefinition CanSpawnCondition;

	UPROPERTY(EditDefaultsOnly, Category="Deactivation")
	TArray<FFortAthenaLivingWorldDespawnCondition> DespawnConditions;

	UPROPERTY(EditDefaultsOnly, Category="Point Providers Filters")
	FGameplayTagQuery ProviderFiltersTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Point Providers Filters")
	TArray<FPointProviderFilterEntry> ProviderFiltersEntries;

	UPROPERTY(EditAnywhere, Category="Point Providers Filters", meta=(BaseStruct="/Script/LagerRuntime.FortAthenaLivingWorldPointProviderSelector"))
	FInstancedStruct PointProviderSelector;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventData")
	TArray<FFortAthenaLivingWorldTaggedSpawnActionClass> SpawnActions;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventData")
	FScalableFloat MinActorCountToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventData")
	FScalableFloat MaxActorCountToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldEventData")
	TArray<FFortAthenaLivingWorldEventDataActorSpawnDescription> ActorDescriptions;

};

