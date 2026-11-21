// Copyright Epic Games, Inc. All Rights Reserved.

#include "Async/FortAsyncAction_TeleportAndWaitForLevelStreamingToComplete.h"

UFortAsyncAction_TeleportAndWaitForLevelStreaming* UFortAsyncAction_TeleportAndWaitForLevelStreaming::CreateTeleportAndWaitForLevelStreaming(AFortPlayerPawn* InPlayerPawn, const FVector& InTeleportLocation, const FRotator& InTeleportRotation, const bool bIgnoreCollision, const bool bIgnoreSupplementalKillVolumeSweep)
{
	return nullptr;
}

void UFortAsyncAction_TeleportAndWaitForLevelStreaming::OnLevelStreamingComplete()
{
}

void UFortAsyncAction_TeleportAndWaitForLevelStreaming::OnPawnEndPlay(AActor* Actor, EEndPlayReason::Type Reason)
{
}
