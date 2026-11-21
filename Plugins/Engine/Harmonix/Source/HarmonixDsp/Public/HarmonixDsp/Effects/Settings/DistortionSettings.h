// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/Effects/Settings/BiquadFilterSettings.h"
#include "DistortionSettings.generated.h"

UENUM()
enum class EDistortionTypeV1 : int32
{
	Clean = 0,
	Warm = 1,
	Dirty = 2,
	Soft = 3,
	Asymmetric = 4,
	Num = 5 UMETA(Hidden),
};

UENUM()
enum class EDistortionTypeV2 : int32
{
	Clean = 0,
	Warm = 1,
	Clip = 2,
	Soft = 3,
	Asymmetric = 4,
	Cruncher = 5,
	CaptCrunch = 6,
	Rectifier = 7,
	Num = 8 UMETA(Hidden),
};

USTRUCT()
struct HARMONIXDSP_API FDistortionFilterSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool FilterPreClip;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FBiquadFilterSettings Filter;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="3", ClampMin="1", UIMax="3", UIMin="1"))
	int32 NumPasses;

};

USTRUCT()
struct HARMONIXDSP_API FDistortionSettingsV1
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="12", ClampMin="-96.0", UIMax="12.0", UIMin="-96.0"))
	float InputGainDb;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="12", ClampMin="-96.0", UIMax="12.0", UIMin="-96.0"))
	float OutputGainDb;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1.0", ClampMin="-1.0", UIMax="1.0", UIMin="-1.0"))
	float DCAdjust;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	EDistortionTypeV1 Type;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool Oversample;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FDistortionFilterSettings Filters[3];

};

USTRUCT()
struct HARMONIXDSP_API FDistortionSettingsV2
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="12", ClampMin="-96.0", UIMax="12.0", UIMin="-96.0"))
	float InputGainDb;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="12", ClampMin="-96.0", UIMax="12.0", UIMin="-96.0"))
	float OutputGainDb;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="0.0", UIMax="0.0", UIMin="0.0"))
	float DryGain;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float WetGain;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1.0", ClampMin="-1.0", UIMax="1.0", UIMin="-1.0"))
	float DCAdjust;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	EDistortionTypeV2 Type;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool Oversample;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FDistortionFilterSettings Filters[3];

};

