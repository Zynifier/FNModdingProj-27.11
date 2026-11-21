// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModulatorSettings.generated.h"

UENUM(BlueprintType)
enum class EModulatorTarget : uint8
{
	StartPoint = 0 UMETA(Json="Start Point"),
	Pitch = 1 UMETA(Json="Pitch"),
	Num = 2 UMETA(Hidden),
	None = 3 UMETA(Hidden, Json="None"),
};

USTRUCT(BlueprintType)
struct HARMONIXDSP_API FModulatorSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP")
	EModulatorTarget Target;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1000000.0", ClampMin="0.0", UIMax="1000000.0", UIMin="0.0"))
	float Range;

	UPROPERTY(EditDefaultsOnly, Category="Harmonix|DSP", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float Depth;

};

USTRUCT(BlueprintType)
struct FModulatorSettingsArray
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FModulatorSettings Array[2];

};

