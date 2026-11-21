// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortRequirementsInfo.h"
#include "FortRegionInfo.generated.h"

class UFortMissionGenerator;
class USlateBrushAsset;

USTRUCT(BlueprintType)
struct FFortMissionAlertRequirementsInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMissionAlertRequirementsInfo")
	FName CategoryName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMissionAlertRequirementsInfo")
	FFortRequirementsInfo Requirements;

};

USTRUCT()
struct FFortTheaterDifficultyWeight
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortTheaterDifficultyWeight")
	FDataTableRowHandle DifficultyInfo;

	UPROPERTY(Transient)
	FString LootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterDifficultyWeight")
	float Weight;

};

USTRUCT()
struct FFortTheaterMissionWeight
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMissionWeight")
	TSoftClassPtr<UFortMissionGenerator> MissionGenerator;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMissionWeight")
	float Weight;

};

USTRUCT()
struct FFortTheaterMapMissionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMapMissionData")
	TArray<FFortTheaterMissionWeight> MissionWeights;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMapMissionData")
	TArray<FFortTheaterDifficultyWeight> DifficultyWeights;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMapMissionData")
	int32 NumMissionsAvailable;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMapMissionData")
	int32 NumMissionsToChange;

	UPROPERTY(EditDefaultsOnly, Category="FortTheaterMapMissionData")
	float MissionChangeFrequency;

};

UCLASS(BlueprintType, Blueprintable)
class UFortRegionInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortRegionInfo")
	FText RegionName;

	UPROPERTY(BlueprintReadOnly, Category="FortRegionInfo")
	FName UniqueId;

	UPROPERTY(EditDefaultsOnly, Category="FortRegionInfo")
	FGameplayTagContainer RegionTags;

	UPROPERTY(EditDefaultsOnly, Category="FortRegionInfo")
	FFortRequirementsInfo Requirements;

	UPROPERTY(EditDefaultsOnly, Category="FortRegionInfo")
	TArray<FFortMissionAlertRequirementsInfo> MissionAlertRequirements;

	UPROPERTY(EditDefaultsOnly, Category="FortRegionInfo")
	FFortTheaterMapMissionData MissionData;

	UPROPERTY(EditDefaultsOnly, Category="FortRegionInfo")
	TSoftObjectPtr<USlateBrushAsset> RegionThemeIcon;

};

