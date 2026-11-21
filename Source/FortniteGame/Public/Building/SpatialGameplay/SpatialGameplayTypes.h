// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialGameplayTypes.generated.h"

UENUM(BlueprintType)
enum class EFortVolumeType : uint8
{
	None = 0,
	// Standard value for playspaces.

	Island = 1,
	// Normal Creative volume that allows saving.

	Published = 2,
	// User entered island code for a published island on a rift in a Hub.

	Featured = 3,
	// Volume for Featured islands.

	Hub = 4,
};

UENUM(BlueprintType)
enum class ESpatialLoadingState : uint8
{
	Uninitialized = 0,
	ReadOnly = 1,
	// State during mini games

	Initializing = 2,
	// State when populating the volume

	Ready = 3,
};

