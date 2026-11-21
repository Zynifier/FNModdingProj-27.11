// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/PannerDetails.h"
#include "StandardStream.generated.h"

USTRUCT(BlueprintType)
struct FStreamingChannelParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	int32 StreamIndex;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	float Gain;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FPannerDetails Pan;

};

USTRUCT()
struct FStreamingTrackParams
{
	GENERATED_BODY()

};

