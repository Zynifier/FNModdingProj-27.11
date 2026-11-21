// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortSeasonPostCopyInterface.h"

#if WITH_EDITOR
bool IFortSeasonPostCopyInterface::SeasonPostCopyFixup(const int32 SeasonNum, const FFortReleaseVersion& ReleaseVersion, const FString& NewSeasonPluginRoot)
{
	return false;
}
#endif
