// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMPlayspaceScopedSystemManager.h"

void UFMPlayspaceScopedSystemManager::GetOrCreateSystemForActorBP(TSubclassOf<AActor> SystemClass, AActor* Requester, AActor*& OutActor, ESystemGetResult& OutWasValid)
{
}

void UFMPlayspaceScopedSystemManager::MulticastNewSystemCreated_Implementation(AActor* PlayspaceActor, TSubclassOf<AActor> SystemClass, AActor* CreatedActor)
{
}
