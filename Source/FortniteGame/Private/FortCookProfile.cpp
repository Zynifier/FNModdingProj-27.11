// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCookProfile.h"

#if WITH_EDITOR
TArray<FString> UFortCookProfile::GetValidPluginNames() const
{
	return TArray<FString>();
}
#endif

#if WITH_EDITOR
TArray<FName> UFortCookProfile::GetValidPrimaryAssetTypes() const
{
	return TArray<FName>();
}
#endif
