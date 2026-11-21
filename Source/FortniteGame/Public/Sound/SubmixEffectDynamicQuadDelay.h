// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundEffectSubmix.h"
#include "Sound/SoundModulationDestination.h"
#include "SubmixEffectDynamicQuadDelay.generated.h"

USTRUCT(BlueprintType)
struct FDynamicTapDelayInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Realtime", meta=(AudioParam="DelayLength", UIMax="2000", UIMin="0.0"))
	FSoundModulationDestinationSettings DelayLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Realtime", meta=(AudioParam="Volume"))
	FSoundModulationDestinationSettings Gain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Realtime", meta=(AudioParam="LPFCutoffFrequency"))
	FSoundModulationDestinationSettings LowPass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Realtime", meta=(ClampMax="180.0", ClampMin="-180.0"))
	float BasePan;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FSubmixEffectDynamicQuadDelaySettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Initialization", meta=(ClampMin="10.0", UIMax="2000.0", UIMin="10.0"))
	float MaximumDelayLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Realtime", meta=(ClampMin="0.0", UIMax="2000.0", UIMin="0.0"))
	float InterpolationTime;

	UPROPERTY(EditAnywhere, Category="Modulation", meta=(AudioParam="Azimuth", UIMax="180.0", UIMin="-180.0"))
	FSoundModulationDestinationSettings Pan;

	UPROPERTY(EditAnywhere, Category="Modulation", meta=(AudioParam="Volume"))
	FSoundModulationDestinationSettings Wet;

	UPROPERTY(EditAnywhere, Category="Modulation", meta=(AudioParam="Volume"))
	FSoundModulationDestinationSettings Dry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Realtime")
	TArray<FDynamicTapDelayInfo> Taps;

};

UCLASS(HideCategories=("Object"))
class FORTNITEGAME_API USubmixEffectDynamicQuadDelayPreset : public USoundEffectSubmixPreset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Audio|Effects")
	void SetModulationSettings(const FSubmixEffectDynamicQuadDelaySettings& InSettings);

	UFUNCTION(BlueprintCallable, Category="Audio|Effects")
	void SetSettings(const FSubmixEffectDynamicQuadDelaySettings& InSettings);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SubmixEffectPreset")
	FSubmixEffectDynamicQuadDelaySettings Settings;

};

