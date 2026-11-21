// Copyright Epic Games, Inc. All Rights Reserved.

#include "ResourceFeed/FortResourceFeed.h"

void UFortResourceFeed::HandleDamagedResourceActor(AActor* InActor, UFortItem* InItem, bool bDestroyed, bool bJustHitWeakspot)
{
}

void UFortResourceFeed::HandleDamagedResourceBuilding(ABuildingSMActor* InBuildingSMActor, UFortItem* InItem, bool bDestroyed, bool bJustHitWeakspot)
{
}

void UFortResourceFeed::HandleFadeOutFinished()
{
}

void UFortResourceFeed::HandleGamePhaseChanged()
{
}

void UFortResourceFeed::HandleItemPickedUp(UFortWorldItem* WorldItem, int32 Count)
{
}

void UFortResourceFeed::HandlePlayerVolumeChanged(AFortVolume* Volume)
{
}

void UFortResourceFeed::HandleResourceGainedFinished()
{
}

bool UFortResourceFeed::HandleTimedOut(float InDeltaTime)
{
	return false;
}

void UFortResourceFeed::HandleWeakpointHitFinished()
{
}
