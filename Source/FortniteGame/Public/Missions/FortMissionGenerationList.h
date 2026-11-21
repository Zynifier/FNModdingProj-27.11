// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortMissionGenerationList.generated.h"

USTRUCT()
struct FMissionGenerationInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MissionRequirements", meta=(ClampMax="5000", ClampMin="0", UIMax="5000", UIMin="0"))
	int32 NumMissionsRequired;

	UPROPERTY(EditDefaultsOnly, Category="MissionRequirements", meta=(ClampMax="5000", ClampMin="-1", UIMax="5000", UIMin="-1"))
	int32 MaxMissionsAllowed;

	UPROPERTY(Transient)
	int32 NumMissionsGeneratedMatchingRequirements;

	UPROPERTY(EditDefaultsOnly, Category="MissionRequirements")
	FGameplayTagQuery MissionTagRequirements;

};

USTRUCT()
struct FPerDifficultyMissionGenerationInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MissionRequirements")
	FDataTableRowHandle MinDifficulty;

	UPROPERTY(EditDefaultsOnly, Category="MissionRequirements")
	FDataTableRowHandle MaxDifficulty;

	UPROPERTY(EditDefaultsOnly, Category="MissionRequirements", meta=(ShowOnlyInnerProperties))
	TArray<FMissionGenerationInfo> MissionGenerationInfos;

};

UCLASS(BlueprintType, Blueprintable)
class UFortMissionGenerationList : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="MissionGeneration", meta=(ShowOnlyInnerProperties))
	FGameplayTagQuery GameplayContextRequirements;

	UPROPERTY(EditDefaultsOnly, Category="MissionGeneration", meta=(ShowOnlyInnerProperties))
	TArray<FPerDifficultyMissionGenerationInfo> PerDifficultyMissionGenerationInfos;

};

