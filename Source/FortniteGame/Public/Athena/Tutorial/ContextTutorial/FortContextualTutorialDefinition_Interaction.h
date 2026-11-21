// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_Interaction.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_Interaction : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Interaction")
	FGameplayTag AbilityTagToTrigger;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Interaction")
	FGameplayTag ActorGamePlayTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Interaction")
	bool bFireOnSuccess;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Interaction")
	bool bFireOnFail;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Interaction")
	FGameplayTag RessourceTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Interaction")
	int32 RessourceNeeded;

};

