// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_CosmeticBase.generated.h"

UCLASS(Abstract)
class UFortAthenaAISpawnerDataComponent_CosmeticBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetFallbackTag(FGameplayTag& OutFallbackTag);

};

