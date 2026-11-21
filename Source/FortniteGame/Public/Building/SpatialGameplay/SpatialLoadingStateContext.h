// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/SpatialGameplay/SpatialGameplayTypes.h"
#include "SpatialLoadingStateContext.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FSpatialGamePlayActorLoadingStateUpdatedContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SpatialGamePlayActorLoadingStateUpdatedContext")
	TObjectPtr<AActor> SpatialGameplayInterfaceActor;

	UPROPERTY(BlueprintReadOnly, Category="SpatialGamePlayActorLoadingStateUpdatedContext")
	ESpatialLoadingState State;

};

USTRUCT(BlueprintType)
struct FSpatialGameplayActorLoadingStateUpdatedPlayerContext : public FSpatialGamePlayActorLoadingStateUpdatedContext
{
	GENERATED_BODY()

};

