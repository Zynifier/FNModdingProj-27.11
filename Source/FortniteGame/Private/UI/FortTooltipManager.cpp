// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/FortTooltipManager.h"

UFortTooltipContext* UFortTooltipContext::SpawnTooltipContext()
{
	return nullptr;
}

UFortTooltipContext* UFortTooltipContext::SpawnTooltipContext_Advanced(const TSubclassOf<UFortTooltipContext>& TooltipContextClass)
{
	return nullptr;
}

UFortTooltipContext* UFortTooltipContext::SpawnTooltipContextWithNetID(UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueID)
{
	return nullptr;
}

UFortTooltipContext* UFortTooltipContext::SpawnTooltipContextWithNetID_Advanced(const TSubclassOf<UFortTooltipContext>& TooltipContextClass, UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueID)
{
	return nullptr;
}

UFortTooltipContext* UFortTooltipContext::SpawnTooltipContextWithSource(APlayerController* SourcePlayerController)
{
	return nullptr;
}

UFortTooltipContext* UFortTooltipContext::SpawnTooltipContextWithSource_Advanced(const TSubclassOf<UFortTooltipContext>& TooltipContextClass, APlayerController* SourcePlayerController)
{
	return nullptr;
}
