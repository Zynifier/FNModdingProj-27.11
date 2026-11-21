// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_NearChest.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_NearChest : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearChest")
	FGameplayTag ContainerTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearChest")
	float ChestCheckRayCastDistance;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearChest")
	FText MarkerText;

};

