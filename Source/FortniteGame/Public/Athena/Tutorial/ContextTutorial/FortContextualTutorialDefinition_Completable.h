// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_Completable.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_Completable : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortContextualTutorialDefinition_Completable")
	FGameplayTagContainer CompletionEventsToTrack;

};

