// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/Streaming/StandardStream.h"
#include "TrackChannelInfo.generated.h"

USTRUCT(BlueprintType)
struct HARMONIXDSP_API FStreamingChannelParamsArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	TArray<FStreamingChannelParams> ChannelParams;

};

USTRUCT(BlueprintType)
struct HARMONIXDSP_API FTrackChannelInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMin="-1", UIMin="-1"))
	int32 RealTrackIndex;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FName Routing;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	TArray<FStreamingChannelParams> Channels;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	TMap<FName, FStreamingChannelParamsArray> PresetChannels;

};

