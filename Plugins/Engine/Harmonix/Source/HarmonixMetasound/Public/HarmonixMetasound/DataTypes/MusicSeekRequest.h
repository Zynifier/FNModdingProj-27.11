// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixMidi/BarMap.h"
#include "MusicSeekRequest.generated.h"

UENUM(BlueprintType)
enum class ESeekPointType : uint8
{
	BarBeat = 0,
	Millisecond = 1,
};

USTRUCT(BlueprintType)
struct FMusicSeekRequest
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MusicTransport")
	bool EmmediateIfPastFromPoint;

	UPROPERTY(BlueprintReadWrite, Category="MusicTransport")
	FMusicTimestamp FromPoint;

	UPROPERTY(BlueprintReadWrite, Category="MusicTransport")
	FMusicTimestamp ToPoint;

};

USTRUCT(BlueprintType)
struct FMusicSeekTarget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MusicTransport")
	ESeekPointType Type;

	UPROPERTY(BlueprintReadWrite, Category="MusicTransport", meta=(EditCondition="Type == ESeekPointType::BarBeat", EditConditionHides))
	FMusicTimestamp BarBeat;

	UPROPERTY(BlueprintReadWrite, Category="MusicTransport", meta=(EditCondition="Type == ESeekPointType::Millisecond", EditConditionHides))
	float Ms;

};

