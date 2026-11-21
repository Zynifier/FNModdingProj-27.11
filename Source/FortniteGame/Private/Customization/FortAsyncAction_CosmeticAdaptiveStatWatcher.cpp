// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/FortAsyncAction_CosmeticAdaptiveStatWatcher.h"

void UFortAsyncAction_CosmeticAdaptiveStatWatcher::BroadcastUpdate(const int32 ValueToBroadcast)
{
}

void UFortAsyncAction_CosmeticAdaptiveStatWatcher::OnPawnEndPlay(AActor* Actor, EEndPlayReason::Type Reason)
{
}

UFortAsyncAction_CosmeticAdaptiveStatWatcher* UFortAsyncAction_CosmeticAdaptiveStatWatcher::WatchCosmeticStat(UObject* Owner, AFortPlayerPawn* Pawn, FFortStatManagerTag StatTag, int32 DefaultValue, bool bBroadcastInitialValue, float InitialValueBroadcastDelay, float ChangeValueBroadcastDelay, bool bConsumeWaitingNotifications)
{
	return nullptr;
}
