// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Perks/FortAIControllerPerksComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_PerksBase.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_PerksBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortAthenaAISpawnerDataComponent_PerksBase")
	TArray<FPerkAvailabilityContainer> PerksContainers;

};

