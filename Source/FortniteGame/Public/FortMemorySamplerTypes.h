// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "ActorMetadata/FortActorMetadata.h"
#include "OnlineLinkId.h"
#include "FortMemorySamplerTypes.generated.h"

UENUM(BlueprintType)
enum class EMemorySamplerState : uint8
{
	// Sampler has not been started yet

	Idle = 0,
	// Sampler is in progress

	InProgress = 1,
	//Sampler is in progress but we arent the owner of the process

	InProgressNotOwner = 2,
	//Sampler failed to launch

	LaunchError = 3,
	//Running the sampling location generation algorithm

	GeneratingSamplingLocations = 4,
	//Initializing the memory sampler

	Initializing = 5,
	//When the memory sampler is ready to be used

	Ready = 6,
};

USTRUCT(BlueprintType)
struct FMemorySamplerResultStatsContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerResultStatsContext")
	TArray<FFortActorTemplateStats> ActorStats;

	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerResultStatsContext")
	FDateTime StartTime;

	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerResultStatsContext")
	FTimespan ElapsedTime;

	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerResultStatsContext")
	FVector HighestMemoryLocation;

	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerResultStatsContext")
	int32 HighestMemoryValue;

	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerResultStatsContext")
	int32 ThresholdMemoryValue;

	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerResultStatsContext")
	int32 NumLocationsSampled;

	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerResultStatsContext")
	bool bSuccess;

	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerResultStatsContext")
	FOnlineLinkId LinkCode;

};

USTRUCT(BlueprintType)
struct FMemorySamplerStateChangedContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MemorySamplerStateChangedContext")
	EMemorySamplerState State;

};

