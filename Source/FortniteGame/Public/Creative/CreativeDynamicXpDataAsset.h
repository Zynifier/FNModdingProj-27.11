// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Components/FortCreativeAFKComponent.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "DynamicXp/FortDynamicXpCalculatorData.h"
#include "FortReleaseVersion.h"
#include "CreativeDynamicXpDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FSeasonalDynamicXp
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ReleaseVersion")
	FFortReleaseVersion FortReleaseVersion;

	UPROPERTY(EditAnywhere, Category="Budgeting")
	float XpBudgetPerMinute;

};

UCLASS()
class UCreativeDynamicXpDataAsset : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="DynamicXp")
	const FCreativeAFKDetectionParameters& GetAFKDetectionParameters() const;

	UFUNCTION(BlueprintPure, Category="DynamicXp")
	float GetAfkMinRewardMult() const;

	UFUNCTION(BlueprintPure, Category="DynamicXp")
	float GetCappedSessionLength() const;

	UFUNCTION(BlueprintPure, Category="DynamicXp")
	float GetXpBudgetPerMinute() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Budgeting", meta=(Patchable))
	TArray<FSeasonalDynamicXp> SeasonalDynamicXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Budgeting", meta=(Patchable))
	TArray<FSeasonalDynamicXp> SeasonalPlaytimeXp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Budgeting", meta=(Patchable))
	float CreativeBudgetModifier;

	UPROPERTY(EditAnywhere, Category="Tuning", meta=(Patchable))
	float AggregatedStatsUpdateIntervalMins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tuning", meta=(Patchable))
	FGameplayTag CreatorTuningRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tuning", meta=(Patchable))
	TMap<FGameplayTag, FDynamicXpCreatorAccoladeTuning> CreatorTuning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tuning", meta=(Patchable))
	FDynamicXpCreatorAccoladeTuning DefaultTuning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tuning", meta=(Patchable))
	float CappedSessionLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Calibration", meta=(Patchable))
	FDynamicXpCircuitBreaker CircuitBreaker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AFK", meta=(Patchable))
	FCreativeAFKDetectionParameters AFKDetectionParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AFK", meta=(Patchable))
	float AfkMinRewardMult;

};

