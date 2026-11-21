// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IslandInspectorState.generated.h"

UENUM()
enum class EIslandInspectorState : uint8
{
	Initializing = 0,
	Ready = 1,
	AwaitingProcessCommand = 2,
	ProcessingCommand = 3,
};

