// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_ItemTags.generated.h"

UCLASS(MinimalAPI)
class UFortContextualTutorialDefinition_ItemTags : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTags")
	FGameplayTagContainer ItemTags;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_ItemTags")
	FGameplayTagContainer BlockedTags;

};

