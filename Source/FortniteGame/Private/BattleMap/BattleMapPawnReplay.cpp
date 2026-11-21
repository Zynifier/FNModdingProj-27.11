// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleMap/BattleMapPawnReplay.h"

bool ABattleMapPawnReplay::BP_IsOnTimelineMode() const
{
	return false;
}

bool ABattleMapPawnReplay::BP_SetTimelineMode(bool bEnabled)
{
	return false;
}

void ABattleMapPawnReplay::HandleBattleMapAutomaticCameraPlacementChanged(bool bEnabled)
{
}

void ABattleMapPawnReplay::HandleBattleMapShowAllSquadMembersChanged(bool bEnabled)
{
}

void ABattleMapPawnReplay::HandleBattleMapShowNearbyChestsChanged(bool bEnabled)
{
}

void ABattleMapPawnReplay::HandleBattleMapShowTimeIndicatorChanged(bool bEnabled)
{
}

void ABattleMapPawnReplay::HandleCameraOutsideSafeZoneChanged(bool bCameraOutsideSafeZone)
{
}

void ABattleMapPawnReplay::HandleCompletedAllRequested()
{
}

void ABattleMapPawnReplay::HandleGotoTimeComplete(bool bWasSuccessful)
{
}

void ABattleMapPawnReplay::HandleLeftMouseDown()
{
}

void ABattleMapPawnReplay::HandleLeftMouseUp()
{
}

void ABattleMapPawnReplay::HandlePlaybackTimeChanged(float NowTime)
{
}

void ABattleMapPawnReplay::HandleRefreshingReplayEvents()
{
}

void ABattleMapPawnReplay::HandleReplayEventRemoving(int32 Index)
{
}

void ABattleMapPawnReplay::HandleRightMouseDown()
{
}

void ABattleMapPawnReplay::HandleRightMouseUp()
{
}

void ABattleMapPawnReplay::HandleTimeIndicatorUpdatedSegment(const ABattleMapNode* StartNode, const ABattleMapEdge* Edge, const ABattleMapNode* EndNode)
{
}
