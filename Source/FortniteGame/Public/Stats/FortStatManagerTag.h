// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortStatManagerTag.generated.h"

USTRUCT(BlueprintType, meta=(Categories="StatManager"))
struct FFortStatManagerTag : public FGameplayTag
{
	GENERATED_BODY()


	FORTNITEGAME_API bool operator==(const FFortStatManagerTag& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FFortStatManagerTag& Value);
};

