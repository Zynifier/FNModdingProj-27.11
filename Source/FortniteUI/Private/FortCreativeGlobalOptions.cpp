// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativeGlobalOptions.h"

UFortCreativeOptionsCategory* UFortCreativeGlobalOptions::GetOptionListFromMemoryPointer() const
{
	return nullptr;
}

void UFortCreativeGlobalOptions::SetListDataSource(UFortMatchmakingKnobsDataSource::Type ListType)
{
}

void UFortCreativeGlobalOptions::UpdateCachedIndices()
{
}

UFortCreativeOptionsCategory::UFortCreativeOptionsCategory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UCommonListView* UFortCreativeOptionsCategory::GetOptionsList() const
{
	return nullptr;
}
