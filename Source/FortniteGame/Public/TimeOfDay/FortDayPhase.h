// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDayPhase.generated.h"

UENUM(BlueprintType)
enum class EFortDayPhase : uint8
{
	Morning = 0,
	Day = 1,
	Evening = 2,
	Night = 3,
	NumPhases = 4 UMETA(DisplayName="Invalid", Hidden),
};

UENUM(BlueprintType)
namespace EFortDayPhasePrio
{
	enum Type
	{
		Default = 0,
		//This should probably go after regular gameplay events

		DailySummary = 1,
	};
}

UENUM()
enum class EFortReportDayPhase : uint8
{
	Dawn = 0,
	Dusk = 1,
	ZoneFinished = 2,
	PlayerLogout = 3,
};

USTRUCT()
struct FFortDayPhaseCallbackHandle
{
	GENERATED_BODY()

};

