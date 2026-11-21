// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingActorLocalizationCache.h"

const TArray<FString>& UBuildingActorLocalizationCache::GetCachedLanguages() const
{
	static TArray<FString> Dummy;
	return Dummy;
}

FString UBuildingActorLocalizationCache::GetDisplayNameForBuildingActor(const TSubclassOf<ABuildingActor>& Class, const FString& Language, const FString& SourceString) const
{
	return FString();
}
