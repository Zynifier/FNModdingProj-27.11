// Copyright Epic Games, Inc. All Rights Reserved.

#include "LevelOverlay/FortLevelOverlayConfig.h"

void UFortLevelOverlayConfig::GetOverlayList(TArray<FFortSourceWorldAndOverlayWorld>& OutOverlayList) const
{
}

#if WITH_EDITOR
bool UFortLevelOverlayConfig::RemoveOverlaysForUncookedMaps(TArray<FString>& OutRemovedOverlays, FString& OutFailureReason)
{
	return false;
}
#endif
