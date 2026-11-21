// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortBotTeamInfoAthena.generated.h"

class AFortAthenaAIBotController;
class AFortPoiVolume;

USTRUCT()
struct FFortBotReservedLoot
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	uint32 LootId;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortAthenaAIBotController> Owner;

};

USTRUCT()
struct FFortBotVisitedPOI
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPoiVolume> POIVolume;

	UPROPERTY(Transient)
	int32 NumCompletedTimes;

};

USTRUCT()
struct FFortBotTeamInfoAthena
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FFortBotReservedLoot> ReservedLoots;

	UPROPERTY(Transient)
	TArray<FFortBotVisitedPOI> VisitedPOIList;

};

USTRUCT()
struct FFortBotVisitedDynamicPOI
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 BotPOIID;

	UPROPERTY(Transient)
	int32 VisitCount;

};

