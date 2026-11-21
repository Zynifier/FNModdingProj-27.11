// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingProp_CaptureItemSpawner.h"

int32 ABuildingProp_CaptureItemSpawner::AddItemRef()
{
	return int32();
}

bool ABuildingProp_CaptureItemSpawner::CanTakeFlag(AFortPawn* InteractingPawn) const
{
	return false;
}

void ABuildingProp_CaptureItemSpawner::NetMulticast_NotifyFeedbackEvent_Implementation(const FGameplayFeedbackEventParams& EventParams, const FFortItemQuantityPair& ItemEntry, const FGuid& ItemVariantGuid)
{
}

void ABuildingProp_CaptureItemSpawner::RegisterSpecialActor(UFortWorldItemDefinition* ItemDefinition)
{
}

int32 ABuildingProp_CaptureItemSpawner::RemoveItemRef()
{
	return int32();
}

void ABuildingProp_CaptureItemSpawner::ResetItemRefCount()
{
}

void ABuildingProp_CaptureItemSpawner::SendCaptureItemFeedbackEvent(const FGameplayFeedbackEventParams& EventParams, const FItemAndCount& ItemEntry)
{
}

void ABuildingProp_CaptureItemSpawner::UnregisterSpecialActor()
{
}
