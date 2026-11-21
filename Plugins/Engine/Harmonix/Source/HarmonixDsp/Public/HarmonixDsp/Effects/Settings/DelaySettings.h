// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/TimeSyncOption.h"
#include "DelaySettings.generated.h"

UENUM()
enum class EDelayFilterType : uint8
{
	LowPass = 0,
	HighPass = 1,
	BandPass = 2,
	Num = 3 UMETA(Hidden),
};

UENUM()
enum class EDelayStereoType : uint8
{
	Default = 0,
	CustomSpread = 1,
	PingPongForceLR = 2,
	PingPongSum = 3,
	PingPongIndividual = 4,
	Num = 5 UMETA(Hidden),
};

USTRUCT()
struct FDelaySettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	ETimeSyncOption TimeSyncOption;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="100", ClampMin="0", UIMax="100", UIMin="0"))
	float TimeSeconds;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="240", ClampMin="1", UIMax="240", UIMin="0"))
	float Tempo;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float DryGain;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float WetGain;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float FeedbackGain;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool EQEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	EDelayFilterType EQType;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="20000", ClampMin="20", DisplayName="EQ Freq (Hz)", UIMax="20000", UIMin="20"))
	float EQFreq;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="10", ClampMin="0", UIMax="10", UIMin="0"))
	float EQQ;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool LfoEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	ETimeSyncOption LfoTimeSyncOption;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="40", ClampMin="0.01", DisplayName="LFO Rate (Hz)", UIMax="40", UIMin="0.01"))
	float LfoRate;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1", ClampMin="0", DisplayName="LFO Depth", UIMax="1", UIMin="0"))
	float LfoDepth;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	EDelayStereoType StereoType;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="100", ClampMin="0", DisplayName="Pan Left (%)", UIMax="100", UIMin="0"))
	float PanLeft;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="100", ClampMin="0", DisplayName="Pan Right (%)", UIMax="100", UIMin="0"))
	float PanRight;

};

