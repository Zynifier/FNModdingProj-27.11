// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "UFortGameFeatureAction_LootTierGroups.generated.h"

UCLASS(meta=(DisplayName="Loot Tier Groups"))
class UUFortGameFeatureAction_LootTierGroups : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Loot")
	TArray<FName> SupportedAthenaLootTierGroups;

};

