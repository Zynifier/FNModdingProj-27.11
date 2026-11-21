// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_NearNPCs.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_NearNPCs : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearNPCs")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearNPCs")
	float RayCastFarDistance;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearNPCs")
	float RayCastNearDistance;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearNPCs")
	bool bInventoryRequirement;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearNPCs")
	FGameplayTagContainer BlockedByTags;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_NearNPCs")
	FGameplayTag GamePlayEventTag;

};

