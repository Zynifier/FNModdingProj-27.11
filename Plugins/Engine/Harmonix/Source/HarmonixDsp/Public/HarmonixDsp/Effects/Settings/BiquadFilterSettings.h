// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BiquadFilterSettings.generated.h"

UENUM()
enum class EBiquadFilterType : int32
{
	LowPass = 0 UMETA(Json="low-pass"),
	HighPass = 1 UMETA(Json="high-pass"),
	BandPass = 2 UMETA(Json="band-pass"),
	Peaking = 3 UMETA(Json="peaking"),
	LowShelf = 4 UMETA(Json="low-shelf"),
	HighShelf = 5 UMETA(Json="high-shelf"),
	Num = 6 UMETA(Hidden),
	None = 7 UMETA(Hidden),
};

USTRUCT()
struct FBiquadFilterSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool IsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	EBiquadFilterType Type;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="20000", ClampMin="20", DisplayName="Freq (Hz)", UIMax="20000", UIMin="20"))
	float Freq;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="10", ClampMin="0", UIMax="10", UIMin="0"))
	float Q;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="12", ClampMin="-96", UIMax="12", UIMin="-96"))
	float DesignedDBGain;

};

