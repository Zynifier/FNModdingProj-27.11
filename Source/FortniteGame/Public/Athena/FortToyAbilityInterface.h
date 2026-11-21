// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortToyAbilityInterface.generated.h"

class AActor;

UINTERFACE(BlueprintType, Blueprintable)
class UFortToyAbilityInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortToyAbilityInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Toys")
	void NotifyAbilityToReleaseToy();

	UFUNCTION(BlueprintImplementableEvent, Category="Toys")
	AActor* NotifyAbilityToSpawnToy(const FTransform& DesiredLocation);

};

