// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleMap/BattleMapPawnLive.h"

bool ABattleMapPawnLive::BP_IsOnTimelineMode() const
{
	return false;
}

bool ABattleMapPawnLive::BP_SetTimelineMode(bool bEnabled)
{
	return false;
}

bool ABattleMapPawnLive::HandleClickPressed(FKey ButtonPressed)
{
	return false;
}

bool ABattleMapPawnLive::HandleClickReleased(FKey ButtonReleased)
{
	return false;
}

void ABattleMapPawnLive::HandleTimeIndicatorUpdatedSegment(const ABattleMapNode* StartNode, const ABattleMapEdge* Edge, const ABattleMapNode* EndNode)
{
}

void ABattleMapPawnLive::ZoomIn(const float Val)
{
}
