// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Missions/MissionSaving/MissionSavingTypes.h"
#include "FortMissionManagerRecord.generated.h"

class AFortMissionManager;

USTRUCT()
struct FFortMissionManagerRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<AFortMissionManager> MissionManagerClass;

	UPROPERTY()
	TArray<FFortMissionRecord> MissionRecords;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EMissionGenerationCategory"))
	int32 NumRequiredMissionsOfType[4];

	UPROPERTY()
	TArray<uint8> MissionManagerData;

};

