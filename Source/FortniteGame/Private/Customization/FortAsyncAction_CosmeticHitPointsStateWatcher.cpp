// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/FortAsyncAction_CosmeticHitPointsStateWatcher.h"

void UFortAsyncAction_CosmeticHitPointsStateWatcher::OnPlayerStateEndPlay(AActor* Actor, EEndPlayReason::Type Reason)
{
}

UFortAsyncAction_CosmeticHitPointsStateWatcher* UFortAsyncAction_CosmeticHitPointsStateWatcher::WatchPawnHealth(AFortPlayerPawn* PlayerPawn)
{
	return nullptr;
}

UFortAsyncAction_CosmeticHitPointsStateWatcher* UFortAsyncAction_CosmeticHitPointsStateWatcher::WatchPlayerHealth(AFortPlayerStateAthena* PlayerState)
{
	return nullptr;
}
