// Copyright Epic Games, Inc. All Rights Reserved.

#include "Settings/SharedSettingsSubsystem.h"

void USharedSettingsSubsystem::AddOrUpdateCachedSharedSettingsData(UObject* ContextObject)
{
}

bool USharedSettingsSubsystem::GetCachedResolverScopesForObject(TArray<FName>& OutResolverScopes, int32& OutPriority, bool& bOutBuildSuccess, const UObject* ContextObject) const
{
	return false;
}

USharedSettingsSubsystem* USharedSettingsSubsystem::GetForObject(const UObject* Object, bool bOnlyGameWorlds)
{
	return nullptr;
}

bool USharedSettingsSubsystem::RemoveCachedSharedSettingsData(UObject* ContextObject)
{
	return false;
}
