// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_Consumable.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_Consumable : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	FGameplayTag ConsumableItemTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	FGameplayTag BlockedTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	float RequirementsCheckDelay;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	bool bUseHealthRequirements;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	float HealthRequirements;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	bool bUseShieldRequirements;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	float ShieldRequirements;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	bool bUseCommitedCallback;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	bool bUseActivatedCallback;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	FGameplayTag CommitedAbilityTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	FGameplayTagContainer BlockedByTags;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_Consumable")
	bool bOnlyInterruptibleHealingItem;

};

