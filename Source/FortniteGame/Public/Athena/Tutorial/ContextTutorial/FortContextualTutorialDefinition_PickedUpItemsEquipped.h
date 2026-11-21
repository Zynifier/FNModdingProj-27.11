// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_PickedUpItemsEquipped.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_PickedUpItemsEquipped : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_PickedUpItemsEquipped")
	FGameplayTagContainer ItemsTags;

};

