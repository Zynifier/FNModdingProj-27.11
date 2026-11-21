// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortFishingInterface.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class UFortFishingInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortFishingInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FName DetermineFishLootTierNameAndSetLootForSpawner(bool bIsExplosion);

};

