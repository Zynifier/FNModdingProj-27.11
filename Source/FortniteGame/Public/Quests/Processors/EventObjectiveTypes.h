// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "EventObjectiveTypes.generated.h"

USTRUCT()
struct FEventCacheID
{
	GENERATED_BODY()

};

USTRUCT()
struct FEventObjectiveFilterCache
{
	GENERATED_BODY()

};

USTRUCT()
struct FEventObjectiveFilterCache_Dynamic : public FEventObjectiveFilterCache
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="EventObjectiveFilterCache_Dynamic")
	TArray<FInstancedStruct> DynamicFilters;

};

USTRUCT()
struct FEventObjectiveFilterCache_Static : public FEventObjectiveFilterCache
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFilteredEventReceiverHandle
{
	GENERATED_BODY()

};

