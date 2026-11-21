// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VocoderSettings.generated.h"

UENUM()
enum class EVocoderBandConfig : uint8
{
	k4 = 0 UMETA(DisplayName="4"),
	k8 = 1 UMETA(DisplayName="8"),
	k16 = 2 UMETA(DisplayName="16"),
	k32 = 3 UMETA(DisplayName="32"),
	k64 = 4 UMETA(DisplayName="64"),
	k128 = 5 UMETA(DisplayName="128"),
	k256 = 6 UMETA(DisplayName="256"),
	Num = 7 UMETA(Hidden),
	None = 8 UMETA(Hidden),
};

USTRUCT()
struct FVocoderBand
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float Gain;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP")
	bool Solo;

};

USTRUCT()
struct FVocoderBandConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	int32 BandCount;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	float FrequencyRatio;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FName Name;

};

USTRUCT()
struct FVocoderSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP")
	bool IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMin="0", UIMin="0"))
	int32 ModulatorIndex;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="8", ClampMin="1", UIMax="8", UIMin="1"))
	int32 ChannelCount;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="200000", ClampMin="40000", UIMax="200000", UIMin="40000"))
	float SampleRate;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP")
	EVocoderBandConfig BandConfig;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP")
	bool Soloing;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMin="0", UIMin="0"))
	int32 FrameCount;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float CarrierGain;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float ModulatorGain;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float CarrierThin;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float ModulatorThin;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMin="0", UIMin="0"))
	float Attack;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMin="0", UIMin="0"))
	float Release;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP")
	float HighEmphasis;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float Wet;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float OutputGain;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP")
	TArray<FVocoderBand> Bands;

};

