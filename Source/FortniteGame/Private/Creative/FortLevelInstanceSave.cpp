// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortLevelInstanceSave.h"

int32 AFortLevelInstanceSaveActor::GetCachedActorCost() const
{
	return int32();
}

TSoftObjectPtr<UFortCreativeActorCollection> AFortLevelInstanceSaveActor::GetContentCollection() const
{
	return TSoftObjectPtr<UFortCreativeActorCollection>();
}

FGuid AFortLevelInstanceSaveActor::GetLevelInstanceGuid() const
{
	return FGuid();
}

bool AFortLevelInstanceSaveActor::GetSize(int32& OutSizeX, int32& OutSizeY, int32& OutHeight) const
{
	return false;
}

void AFortLevelInstanceSaveActor::Resave()
{
}
