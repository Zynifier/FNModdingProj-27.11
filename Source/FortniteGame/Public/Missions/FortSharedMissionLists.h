// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UI/FrontEnd/FortTheaterInfo.h"
#include "UI/FrontEnd/FortZoneTheme.h"
#include "FortSharedMissionLists.generated.h"

class AFortPlayerController;
class UFortMissionGenerationList;
class UFortMissionInfo;
class UFortQuestItemDefinition;

USTRUCT(BlueprintType)
struct FFortGlobalMission
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortGlobalMission")
	TSoftObjectPtr<UFortMissionInfo> MissionInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Theater")
	TArray<EFortTheaterType> AllowedTheaterTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Theater")
	FGameplayTagQuery TheaterTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Region")
	FGameplayTagQuery RegionTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zone")
	TArray<EFortZoneType> AllowedZoneTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Zone")
	FGameplayTagQuery ZoneTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Mission")
	FGameplayTagQuery PrimaryMissionTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGlobalMission", meta=(ClampMin="-1", MakeStructureDefaultValue="-1"))
	float MaxDifficultyLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGlobalMission", meta=(ClampMin="-1", MakeStructureDefaultValue="-1"))
	float MinDifficultyLevel;

	UPROPERTY(EditDefaultsOnly, Category="FortGlobalMission")
	bool bIsPrototype;

	UPROPERTY(EditDefaultsOnly, Category="FortGlobalMission")
	bool bAllowInTestMaps;

	UPROPERTY(EditDefaultsOnly, Category="FortGlobalMission")
	bool bEnabled;

};

USTRUCT(BlueprintType)
struct FFortMissionDistributionCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMissionDistributionCategory", meta=(ShowOnlyInnerProperties))
	FGameplayTagQuery CategoryTagQuery;

};

USTRUCT(BlueprintType)
struct FFortNonPrimaryMission
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortNonPrimaryMission")
	TSoftObjectPtr<UFortMissionInfo> MissionInfo;

	UPROPERTY(EditDefaultsOnly, AssetRegistrySearchable, Category="Theater")
	FGameplayTagQuery ContextTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="MissionRequirements")
	FDataTableRowHandle MinDifficulty;

	UPROPERTY(EditDefaultsOnly, Category="MissionRequirements")
	FDataTableRowHandle MaxDifficulty;

	UPROPERTY(Transient)
	bool bSatisfiesCurrentRequirement;

	UPROPERTY(Transient)
	TArray<int32> RequirementIndicesSatisfied;

	UPROPERTY(Transient)
	TArray<int32> DistributionCategoryIndicesSatisfied;

};

USTRUCT(BlueprintType)
struct FFortQuestDrivenMission : public FFortGlobalMission
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortQuestDrivenMission")
	TObjectPtr<UFortQuestItemDefinition> RequiredQuest;

};

USTRUCT()
struct FQuestDrivenMissionSubList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Quest-Driven Mission List")
	FName MissionSubListName;

	UPROPERTY(EditAnywhere, Category="Quest-Driven Mission List")
	bool bEnabled;

	UPROPERTY(EditAnywhere, Category="Quest-Driven Mission List")
	TArray<FFortQuestDrivenMission> QuestDrivenMissionList;

};

UCLASS(Config=Game, BlueprintType, Blueprintable)
class UFortSharedMissionLists : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleDynamicMulticastDelegate);

protected:
	UFUNCTION(BlueprintCallable, Category="PIE")
	void UpdatePIEPlayers();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Dynamic Mission Lists", meta=(DisplayName="Global Dynamic Mission List"))
	TArray<FFortGlobalMission> SharedMissionList;

	UPROPERTY(EditAnywhere, Category="Dynamic Mission Lists")
	TArray<FQuestDrivenMissionSubList> QuestDrivenMissionLists;

private:
	UPROPERTY(Transient)
	TArray<FFortNonPrimaryMission> CombinedNonPrimaryMissionList;

	UPROPERTY(EditAnywhere, Category="MissionGenerationRules")
	TArray<FFortNonPrimaryMission> NonPrimaryMissionList;

	UPROPERTY(EditAnywhere, Category="MissionGenerationRules")
	TArray<FFortMissionDistributionCategory> NonPrimaryMissionDistributionCategories;

	UPROPERTY(EditAnywhere, Category="MissionGenerationRules")
	TArray<TSoftObjectPtr<UFortMissionGenerationList>> WorldSetupMissionGenerationLists;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Mission Lists")
	FGameplayTagQuery PrimaryMissionTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Mission Lists")
	FGameplayTagQuery TheaterTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Mission Lists")
	FGameplayTagQuery RegionTagQuery;

	UPROPERTY(Transient)
	TArray<FFortQuestDrivenMission> AvailableQuestDrivenMissionList;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerController>> PendingPIEPlayers;

	UPROPERTY(Config)
	TArray<int32> DisableSharedMissionListIndices;

};

