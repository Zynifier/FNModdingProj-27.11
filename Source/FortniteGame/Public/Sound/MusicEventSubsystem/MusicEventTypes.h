// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "MusicEventTypes.generated.h"

UENUM(BlueprintType)
enum class EMusicEventResolutionRule : uint8
{
	NewestWins = 0,
	OldestWins = 1,
	ClosestWins = 2,
};

USTRUCT(BlueprintType)
struct FMusicEventData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MusicEventData", meta=(Categories="MusicEventSubsystem.Event"))
	FGameplayTag EventTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MusicEventData")
	EMusicEventResolutionRule ResolutionRule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MusicEventData")
	float FadeInTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MusicEventData")
	float FadeOutTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MusicEventData")
	int32 MaxConcurrentEvents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MusicEventData")
	float AttenuationEvalThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MusicEventData")
	FString Description;

};

