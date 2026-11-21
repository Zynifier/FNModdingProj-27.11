// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortAnalyticsClientEngagements.generated.h"

UENUM()
enum class EFortAnalyticsClientEngagementEventType : uint8
{
	None = 0,
	DamageReceivedFromPlayerPawn = 1,
	DamageDealtToPlayerPawn = 2,
	DamageDealtToPlayerBuild = 3,
	DamageDealtToOther = 4,
	EngagementTimeout = 5,
	PlayerWon = 6,
	PlayerDeathOnWin = 7,
	TeamWon = 8,
	TeamLost = 9,
	PlayerLost = 10,
	PlayerKilledPlayer = 11,
	PlayerFiredWeapon = 12,
	ManagerStopped = 13,
	PlayerPawnDied = 14,
	PlayerPawnSpawned = 15,
	Count = 16,
};

USTRUCT()
struct FFortAnalyticsClientEngagement
{
	GENERATED_BODY()

};

UCLASS()
class UFortAnalyticsClientEngagementsManager : public UObject
{
	GENERATED_BODY()

};

