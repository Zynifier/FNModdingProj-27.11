// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ControllerComponents/FortControllerComponent_EndMatchPersistence.h"

void UFortControllerComponent_EndMatchPersistence::AddEndOfMatchLoot(const TArray<FFortItemEntry>& LootList, const bool bAddToExisting)
{
}

const TArray<FFortItemEntry>& UFortControllerComponent_EndMatchPersistence::GetEndOfMatchLoot() const
{
	static TArray<FFortItemEntry> Dummy;
	return Dummy;
}

UFortControllerComponent_EndMatchPersistence* UFortControllerComponent_EndMatchPersistence::GetFromPlayerController(AFortPlayerControllerAthena* PC, bool bCreateIfNotFound)
{
	return nullptr;
}
