// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Stats/FortCosmeticStatObject.h"
#include "FortCosmeticStatObject_VictoryCrowns.generated.h"

class UFortVictoryCrownAccountItemDefinition;

UCLASS(BlueprintType, Blueprintable)
class UFortCosmeticStatObject_TotalVictoryCrowns : public UFortCosmeticStatObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticStatObject_TotalVictoryCrowns")
	TObjectPtr<UFortVictoryCrownAccountItemDefinition> VictoryCrownAccountItemDefinition;

};

