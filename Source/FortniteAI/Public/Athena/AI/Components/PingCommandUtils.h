// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PingCommandUtils.generated.h"

UENUM(BlueprintType)
enum class PingCommandType : uint8
{
	GoTo = 0,
	BackToMe = 1,
	BackToDefault = 2,
	HoldPosition = 3,
	Revive = 4,
	Dismiss = 5,
	Item = 6,
	Attack = 7,
	Invalid = 8,
	MAX = 9 UMETA(Hidden),
};

