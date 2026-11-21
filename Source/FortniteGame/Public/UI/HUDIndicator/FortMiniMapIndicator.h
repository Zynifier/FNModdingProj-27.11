// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortIndicator.h"
#include "FortMiniMapIndicator.generated.h"

UENUM()
enum EFortMiniMapContext
{
	EFMC_MiniMap = 0,
	EFMC_FullScreenMap = 1,
};

UENUM()
enum EFortMiniMapHeight
{
	EFMH_Equal = 0,
	EFMH_Below = 1,
	EFMH_Above = 2,
};

UENUM()
enum EFortMiniMapIconRotation
{
	EFMMIR_None = 0,
	/** Rotation based on map orientation (useful when "direction" OF object is important, for example other players rotation) */
	EFMMIR_Absolute = 1,
	/** Rotation based on relative direction to local player (useful when "direction" TO object is important, for example damage indicators) */
	EFMMIR_Relative = 2,
};

UENUM()
enum EFortMinimapLayer
{
	EFML_PrePOIText = 0,
	EFML_PostSquadIcons = 1,
	EFML_PostSpecialActors = 2,
};

UCLASS(MinimalAPI)
class UFortMiniMapIndicator : public UFortIndicator
{
	GENERATED_BODY()

};

