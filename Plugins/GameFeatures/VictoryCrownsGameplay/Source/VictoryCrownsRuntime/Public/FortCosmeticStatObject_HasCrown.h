// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Stats/FortCosmeticStatObject.h"
#include "FortCosmeticStatObject_HasCrown.generated.h"

class UFortVictoryCrownAccountItemDefinition;

UCLASS(BlueprintType, Blueprintable)
class UFortCosmeticStatObject_HasCrown : public UFortCosmeticStatObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticStatObject_HasCrown")
	TObjectPtr<UFortVictoryCrownAccountItemDefinition> VictoryCrownAccountItemDefinition;

};

