// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AdsrSettings.generated.h"

UENUM(BlueprintType)
enum class EAdsrTarget : uint8
{
	None = 0 UMETA(Json="none"),
	Volume = 1 UMETA(Json="volume"),
	FilterFreq = 2 UMETA(Json="filter_freq"),
	Num = 3 UMETA(Hidden),
	Invalid = 4 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct HARMONIXDSP_API FAdsrSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	EAdsrTarget Target;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="10", ClampMin="0", DisplayName="Attack (Seconds)", UIMax="10", UIMin="0"))
	float AttackTime;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="10", ClampMin="0", DisplayName="Decay (Seconds)", UIMax="10", UIMin="0"))
	float DecayTime;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float SustainLevel;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="10", ClampMin="0", DisplayName="Release (Seconds)", UIMax="10", UIMin="0"))
	float ReleaseTime;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float Depth;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="-1", DisplayName="Attack Curve (Seconds)", UIMax="1", UIMin="-1"))
	float AttackCurve;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="-1", DisplayName="Decay Curve (Seconds)", UIMax="1", UIMin="-1"))
	float DecayCurve;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="-1", DisplayName="Release Curve (Seconds)", UIMax="1", UIMin="-1"))
	float ReleaseCurve;

};

USTRUCT(BlueprintType)
struct FAdsrSettingsArray
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FAdsrSettings Array[2];

};

