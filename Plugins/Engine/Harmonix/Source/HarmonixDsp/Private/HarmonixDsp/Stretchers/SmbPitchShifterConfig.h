// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/StretcherAndPitchShifterConfig.h"
#include "SmbPitchShifterConfig.generated.h"

UCLASS(meta=(DisplayName="SMB Pitch Shifter Settings"))
class USmbPitchShifterConfig : public UStretcherAndPitchShifterConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Pool Config")
	uint32 NumAllocatedStretchers;

};

