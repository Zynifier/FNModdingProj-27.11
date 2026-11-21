// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeItemGranter.generated.h"

class UFortWorldItemDefinition;

USTRUCT(BlueprintType)
struct FCreativeItemGranterItemEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, SaveGame, Category="Creative Item Granter")
	TSoftObjectPtr<UFortWorldItemDefinition> ItemDefinition;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, SaveGame, Category="Creative Item Granter")
	int32 Count;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, SaveGame, Category="Creative Item Granter")
	int32 Level;

};

