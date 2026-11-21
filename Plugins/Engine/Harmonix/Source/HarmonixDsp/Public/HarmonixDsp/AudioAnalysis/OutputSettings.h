// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OutputSettings.generated.h"

USTRUCT(BlueprintType)
struct FHarmonixAudioAnalyzerOutputSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(ClampMax="1000", ClampMin="0", UIMax="1000", UIMin="0"))
	float RiseMs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(ClampMax="4000", ClampMin="0", UIMax="4000", UIMin="0"))
	float FallMs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(ClampMax="0", ClampMin="-96", UIMax="0", UIMin="-96"))
	float MaxDecibels;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(ClampMax="96", ClampMin="3", UIMax="96", UIMin="3"))
	float RangeDecibels;

};

