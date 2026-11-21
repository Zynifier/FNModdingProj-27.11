// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/FortQuestTypes.h"
#include "FortEndZoneScoreAndAwards.generated.h"

USTRUCT()
struct FEndZoneScoreAndAwards
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bResultsPendingSave;

	UPROPERTY()
	int32 TotalScore;

	UPROPERTY()
	bool bCriticalMatchBonus;

	UPROPERTY()
	bool bDidLeech;

	UPROPERTY()
	EAthenaRebootEligiblityStatus EligibilityStatus;

	UPROPERTY()
	TArray<FFortQuestEarnedBadgeData> EarnedBadgeData;

	UPROPERTY()
	TArray<FString> EarnedItemCaches;

	UPROPERTY()
	int32 NumMissionPoints;

	UPROPERTY()
	float MissionLeechScaling;

	UPROPERTY()
	int32 TotalSecondsInMatch;

};

