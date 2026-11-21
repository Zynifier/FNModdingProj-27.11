// Copyright Epic Games, Inc. All Rights Reserved.

#include "FrontEnd/FortTheaterCamera.h"

TArray<UFortQuestItem*> AFortTheaterCamera::FindPinnedQuestsForTiles(TArray<AFortTheaterMapTile*> Tiles) const
{
	return TArray<UFortQuestItem*>();
}

FVector AFortTheaterCamera::LimitToTheater(const FVector& DesiredPosition) const
{
	return FVector();
}
