// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TriState.generated.h"

UENUM()
enum class ETriState : uint8
{
	DefaultState = 0 UMETA(DisplayName="UseDefault", ScriptName="UseDefault"),
	TrueState = 1 UMETA(DisplayName="True", ScriptName="True"),
	FalseState = 2 UMETA(DisplayName="False", ScriptName="False"),
};

