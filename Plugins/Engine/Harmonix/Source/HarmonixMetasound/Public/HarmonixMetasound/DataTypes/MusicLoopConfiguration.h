// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/BarMap.h"
#include "MusicLoopConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FMusicLoopConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MusicLoopConfiguration")
	bool Enabled;

	UPROPERTY(BlueprintReadWrite, Category="MusicLoopConfiguration")
	FMusicTimestamp RegionStart;

	UPROPERTY(BlueprintReadWrite, Category="MusicLoopConfiguration")
	FMusicTimestamp RegionEnd;

};

