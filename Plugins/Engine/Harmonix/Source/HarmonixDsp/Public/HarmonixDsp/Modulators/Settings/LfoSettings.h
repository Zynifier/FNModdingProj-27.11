// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LfoSettings.generated.h"

UENUM(BlueprintType)
enum class ELfoTarget : uint8
{
	Pan = 0 UMETA(Json="pan"),
	Pitch = 1 UMETA(Json="pitch"),
	FilterFreq = 2 UMETA(Json="filter_freq"),
	Num = 3 UMETA(Hidden),
	None = 4 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EWaveShape : uint8
{
	Sine = 0 UMETA(Json="sine"),
	Square = 1 UMETA(Json="square"),
	SawUp = 2 UMETA(Json="saw_up"),
	SawDown = 3 UMETA(Json="saw_down"),
	Triangle = 4 UMETA(Json="triangle"),
	Random = 5 UMETA(Json="random"),
	Num = 6 UMETA(Hidden),
	None = 7 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct HARMONIXDSP_API FLfoSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	EWaveShape Shape;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	ELfoTarget Target;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool ShouldRetrigger;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool BeatSync;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="40.0", ClampMin="0.01", DisplayName="Freq (Hz)", UIMax="40.0", UIMin="0.01"))
	float Freq;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float Depth;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="0.99", ClampMin="0.0", UIMax="0.99", UIMin="0.0"))
	float InitialPhase;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="240", ClampMin="1", UIMax="240", UIMin="1"))
	float TempoBPM;

};

USTRUCT(BlueprintType)
struct FLfoSettingsArray
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FLfoSettings Array[2];

};

