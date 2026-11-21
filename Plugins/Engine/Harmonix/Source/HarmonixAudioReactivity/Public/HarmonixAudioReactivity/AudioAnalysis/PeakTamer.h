// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PeakTamer.generated.h"

class UHarmonixPeakTamer;

USTRUCT(BlueprintType)
struct FHarmonixPeakTamerSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="AudioAnalysis")
	float PeakAttackTimeSeconds;

	UPROPERTY(BlueprintReadWrite, Category="AudioAnalysis")
	float PeakReleaseTimeSeconds;

	UPROPERTY(BlueprintReadWrite, Category="AudioAnalysis")
	bool bEnableValueSmoothing;

	UPROPERTY(BlueprintReadWrite, Category="AudioAnalysis")
	float ValueAttackTimeSeconds;

	UPROPERTY(BlueprintReadWrite, Category="AudioAnalysis")
	float ValueReleaseTimeSeconds;

};

/**
 * Takes a raw peak value from an audio analyzer and outputs a smoothed, compressed value in range [0, 1]
 */
UCLASS(BlueprintType)
class HARMONIXAUDIOREACTIVITY_API UHarmonixPeakTamer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AudioAnalysis")
	void Configure(const FHarmonixPeakTamerSettings& Settings);

	UFUNCTION(BlueprintCallable, Category="AudioAnalysis")
	static UHarmonixPeakTamer* CreateHarmonixPeakTamer();

	UFUNCTION(BlueprintPure, Category="AudioAnalysis")
	float GetPeak() const;

	UFUNCTION(BlueprintPure, Category="AudioAnalysis")
	float GetValue() const;

	UFUNCTION(BlueprintCallable, Category="AudioAnalysis")
	void Update(float InputValue, float DeltaTimeSeconds);

};

