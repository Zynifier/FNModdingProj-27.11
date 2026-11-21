// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortBattlePassTileBase.h"

bool UFortBattlePassTileBase::AreAnyGrantedItemsEquipped() const
{
	return false;
}

const BattlePassTileAvailabilityStates UFortBattlePassTileBase::GetState() const
{
	return BattlePassTileAvailabilityStates();
}

bool UFortBattlePassTileBase::IsAvailable() const
{
	return false;
}

bool UFortBattlePassTileBase::IsLocked() const
{
	return false;
}

bool UFortBattlePassTileBase::IsOwned() const
{
	return false;
}

void UFortBattlePassTileBase::SetSize(const EPageItemTileSize TileSize, const FVector2D& CellSpacing)
{
}

void UFortBattlePassTileBase::SetState(const BattlePassTileAvailabilityStates NewState)
{
}
