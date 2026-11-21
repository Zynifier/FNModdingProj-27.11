// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BitCrusherSettings.generated.h"

USTRUCT()
struct FBitCrusherSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP")
	bool IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float InputGain;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float OutputGain;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float WetGain;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="15", ClampMin="0", DisplayName="Crush (Bit Depth)", UIMax="15", UIMin="0"))
	uint16 Crush;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="16", ClampMin="0", UIMax="16", UIMin="0"))
	uint16 SampleHoldFactor;

};

