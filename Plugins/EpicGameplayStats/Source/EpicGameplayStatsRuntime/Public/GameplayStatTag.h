// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayStatTag.generated.h"

USTRUCT(BlueprintType, meta=(Categories="GameplayStat"))
struct EPICGAMEPLAYSTATSRUNTIME_API FGameplayStatTag : public FGameplayTag
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FGameplayTag Tag;

};

