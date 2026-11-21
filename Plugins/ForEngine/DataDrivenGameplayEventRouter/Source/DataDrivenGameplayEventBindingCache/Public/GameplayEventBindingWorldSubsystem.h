// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameplayEventBindingCache.h"
#include "GameplayEventBindingWorldSubsystem.generated.h"

class UObject;

UCLASS()
class DATADRIVENGAMEPLAYEVENTBINDINGCACHE_API UGameplayEventBindingWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TMap<TSoftObjectPtr<UObject>, FGameplayEventCachedPropertyBindings> CachedObjectEventSubscriptions;

	UPROPERTY()
	TMap<TSoftObjectPtr<UObject>, FGameplayEventCachedPropertyBindings> CachedObjectEventHandlers;

};

