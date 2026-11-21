// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Stats/FortCosmeticStatObject.h"
#include "FortCosmeticStatObject_RoyalRoyales.generated.h"

class UFortControllerComponent_VictoryCrowns;
class UFortVictoryCrownAccountItemDefinition;

UCLASS(BlueprintType, Blueprintable)
class UFortCosmeticStatObject_TotalRoyalRoyales : public UFortCosmeticStatObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticStatObject_TotalRoyalRoyales")
	TObjectPtr<UFortVictoryCrownAccountItemDefinition> VictoryCrownAccountItemDefinition;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UFortControllerComponent_VictoryCrowns>> CachedCrownComponents;

};

