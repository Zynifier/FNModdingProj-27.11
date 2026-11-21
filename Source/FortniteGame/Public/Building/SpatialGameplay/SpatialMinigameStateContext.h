// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Minigame/FortMinigameTypes.h"
#include "SpatialMinigameStateContext.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FMinigameStateChangeContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MinigameStateChangeContext")
	EFortMinigameState MinigameState;

	UPROPERTY(BlueprintReadWrite, Category="MinigameStateChangeContext")
	TObjectPtr<AActor> EventOwner;

};

