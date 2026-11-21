// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/HUD/EndGame/PostGamePlacementOverlay.h"

bool UPostGamePlacementOverlay::BP_ShouldShow_Implementation() const
{
	return false;
}

void UPostGamePlacementOverlay::LocalPlacementChanged()
{
}

bool UPostGamePlacementOverlay::NativeShouldShow() const
{
	return false;
}

bool UPostGamePlacementOverlay::ShouldShow() const
{
	return false;
}
