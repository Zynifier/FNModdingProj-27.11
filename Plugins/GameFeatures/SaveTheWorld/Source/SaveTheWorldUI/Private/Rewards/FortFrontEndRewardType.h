// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortFrontEndRewardType.generated.h"

UENUM(BlueprintType)
enum class EFrontEndRewardType : uint8
{
	Mission = 0,
	Quest = 1,
	EpicNewQuest = 2,
	Expedition = 3,
	CollectionBook = 4,
	MissionAlert = 5,
	DifficultyIncrease = 6,
	GiftBox = 7,
	ItemCache = 8,
	PhoenixLevelUp = 9,
};

