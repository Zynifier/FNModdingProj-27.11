// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/Containers/TypedParameter.h"
#include "HarmonixDsp/PitchShifterName.h"
#include "StretcherAndPitchShifter.generated.h"

USTRUCT()
struct HARMONIXDSP_API FTimeStretchConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool bMaintainTime;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FPitchShifterName PitchShifter;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	TMap<FName, FTypedParameter> PitchShifterOptions;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool bSyncTempo;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="240", ClampMin="1", UIMax="240", UIMin="1"))
	float OriginalTempo;

};

