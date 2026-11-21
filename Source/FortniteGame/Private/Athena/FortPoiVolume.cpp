// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPoiVolume.h"

void AFortPoiVolume::CalendarEventsShouldBeReady(const TArray<FString>& NewEvents)
{
}

bool AFortPoiVolume::ContainsLocationTag(const FGameplayTag& Tag) const
{
	return false;
}

bool AFortPoiVolume::DoesShapeComponentOverlap(UShapeComponent* Shape)
{
	return false;
}

#if WITH_EDITOR
void AFortPoiVolume::FixBoxScaling()
{
}
#endif

UDataLayerAsset* AFortPoiVolume::GetPoiDataLayer() const
{
	return nullptr;
}
