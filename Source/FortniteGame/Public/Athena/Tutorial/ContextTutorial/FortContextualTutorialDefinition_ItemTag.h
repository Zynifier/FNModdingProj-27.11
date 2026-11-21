// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_ItemTag.generated.h"

UCLASS(MinimalAPI)
class UFortContextualTutorialDefinition_ItemTag : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTag")
	FGameplayTag ItemTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTag")
	FGameplayTag BlockedTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTag")
	float RequirementsCheckDelay;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTag")
	bool bUseCommitedCallback;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTag")
	bool bUseActivatedCallback;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTag")
	bool bRequireItemEquipped;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTag")
	FGameplayTag CommitedAbilityTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTag")
	FGameplayTagContainer BlockedByTags;

};

