// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Stat.generated.h"

UENUM(BlueprintType)
enum class EStatMod : uint8
{
	//Add the given value to the existing value already stored in the stat. The most common modification.

	Delta = 0,
	//Set the stat to the given value, ignoring any previous value.

	Set = 1,
	//Set the stat to the max of the given value and the previous value. Like Set, except it can't lower the stat.

	Maximum = 2,
};

UENUM(BlueprintType)
enum class EStatRecordingPeriod : uint8
{
	Frame = 0,
	Minute = 1,
	AthenaSafeZonePhase = 2,
	Life = 3,
	Map = 4,
	Campaign = 5,
	Persistent = 6,
	Max = 7,
};

UENUM(BlueprintType)
enum class EStatTeamAggregateFunction : uint8
{
	/** Add the stat value for all team members (eg damage done) */
	Add = 0,
	/** Use the max stat value of all team members (eg furthest storm circle reached or bool values like objective completed) */
	Max = 1,
	/** Use the min stat value of all team member*/
	Min = 2,
};

UCLASS()
class UStat : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName StatName;

	UPROPERTY()
	EStatRecordingPeriod HighestPeriodToTrack;

	UPROPERTY()
	int32 AbsoluteMaxValue;

	UPROPERTY()
	EStatTeamAggregateFunction TeamAggregateFunction;

};

