// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_NearObjects.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_NearObjects : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	FGameplayTagContainer ContainerTags;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	float RayCastFarDistance;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	float RayCastNearDistance;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	bool bInventoryRequirement;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	bool bInventoryCanInteract;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	bool bAddMarker;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	FText MarkerText;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	float MarkerTextOffset;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	FGameplayTagContainer BlockedByTags;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	FGameplayTag GamePlayEventTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearObjects")
	bool bMustBeInteractable;

};

