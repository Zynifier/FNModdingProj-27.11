// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/SpecialActor/FortAsyncAction_WatchGlobalActorRegistry.h"

void UFortAsyncAction_WatchGlobalActorRegistry::HandleActorRegisteredWithTag(const FGameplayTag& Tag, AActor* Actor)
{
}

void UFortAsyncAction_WatchGlobalActorRegistry::HandleActorUnregisteredWithTag(const FGameplayTag& Tag, AActor* Actor)
{
}

UFortAsyncAction_WatchGlobalActorRegistry* UFortAsyncAction_WatchGlobalActorRegistry::WatchGlobalActorRegistryWithTag(UObject* WorldContextObject, const FGameplayTag& TagToWatch, bool bOnlyWatchForFirstRegistration)
{
	return nullptr;
}
