// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_Vehicle.generated.h"

UCLASS(MinimalAPI)
class UFortContextualTutorialDefinition_Vehicle : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Vehicle")
	FGameplayTag VehicleTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Vehicle")
	FGameplayTag VehicleActionTag;

};

