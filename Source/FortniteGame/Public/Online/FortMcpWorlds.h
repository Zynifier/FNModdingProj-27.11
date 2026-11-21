// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Online/FortMcpResource.h"
#include "UI/FrontEnd/FortTheaterInfo.h"
#include "UI/FrontEnd/FortTheaterMapViewer.h"
#include "FortMcpWorlds.generated.h"

class UWorld;

USTRUCT()
struct FFortActiveTheaterInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortTheaterMapData> Theaters;

	UPROPERTY()
	TArray<FFortAvailableTheaterMissions> Missions;

	UPROPERTY()
	TArray<FFortAvailableMissionAlerts> MissionAlerts;

};

UCLASS(MinimalAPI)
class UFortMcpWorlds : public UFortMcpResource
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FFortActiveTheaterInfo TheaterInfo;

	UPROPERTY()
	int32 TheaterQueryRetry;

	UPROPERTY()
	FDateTime LastTheaterRefresh;

	UPROPERTY()
	TSoftObjectPtr<UWorld> LastWorld;

};

