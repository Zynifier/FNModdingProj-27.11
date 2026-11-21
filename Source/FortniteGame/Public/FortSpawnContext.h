// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortSpawnContext.generated.h"

USTRUCT(BlueprintType)
struct FFortSpawnContext
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="Team")
	uint8 Team;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="Tags")
	FGameplayTagContainer Tags;

};

