// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialActorTrackerContext.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FActorTrackerBaseContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="ActorTrackerBaseContext")
	TObjectPtr<AActor> EventOwner;

};

USTRUCT(BlueprintType)
struct FActorTrackerActorEnteredContext : public FActorTrackerBaseContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="ActorTrackerActorEnteredContext")
	TObjectPtr<AActor> EnteredActor;

};

USTRUCT(BlueprintType)
struct FActorTrackerActorExitContext : public FActorTrackerBaseContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="ActorTrackerActorExitContext")
	TObjectPtr<AActor> ExitingActor;

};

