// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "UFortContextualTutorialDefinition_GameplayEvent.generated.h"

UCLASS()
class UUFortContextualTutorialDefinition_GameplayEvent : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="UFortContextualTutorialDefinition_GameplayEvent")
	FGameplayTagContainer ActivationEventsToTrack;

	UPROPERTY(EditDefaultsOnly, Category="UFortContextualTutorialDefinition_GameplayEvent")
	FGameplayTagContainer IncludeTargetTags;

	UPROPERTY(EditDefaultsOnly, Category="UFortContextualTutorialDefinition_GameplayEvent")
	FGameplayTagContainer ExcludeTargetTags;

	UPROPERTY(EditDefaultsOnly, Category="UFortContextualTutorialDefinition_GameplayEvent")
	FGameplayTagContainer CompletionEventsToTrack;

	UPROPERTY(EditDefaultsOnly, Category="UFortContextualTutorialDefinition_GameplayEvent")
	FGameplayTagContainer FailureEventsToTrack;

private:
	UPROPERTY(EditAnywhere, Config, Category="UFortContextualTutorialDefinition_GameplayEvent")
	bool bCheckEventTagsOnActivationBinding;

};

