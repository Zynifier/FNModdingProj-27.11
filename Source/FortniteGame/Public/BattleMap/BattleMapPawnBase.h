// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BattleMapPawnBase.generated.h"

UENUM()
enum class BattleMapHoveredReason : int32
{
	None = 0,
	Mouse = 1,
	Code = 2,
};

USTRUCT()
struct FBattleMapSharedData
{
	GENERATED_BODY()

};

