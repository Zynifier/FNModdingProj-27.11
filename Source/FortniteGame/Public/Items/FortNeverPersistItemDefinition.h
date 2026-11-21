// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortNeverPersistItemDefinition.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortNeverPersistItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	uint8 bAccumulateOnPlayerState : 1;

};

