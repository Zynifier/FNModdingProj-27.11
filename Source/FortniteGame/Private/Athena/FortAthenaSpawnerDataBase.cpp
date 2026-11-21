// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaSpawnerDataBase.h"

FGameplayTagContainer UFortAthenaSpawnerDataBase::GetDescriptorTag() const
{
	return FGameplayTagContainer();
}

#if WITH_EDITOR
UFortAthenaSpawnerDataBase* UFortAthenaSpawnerDataBase::GetSpawnerDataDefaultObject(UObject* SourceObject)
{
	return nullptr;
}
#endif
