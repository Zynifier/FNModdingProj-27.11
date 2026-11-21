// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_POI.generated.h"

UCLASS()
class UFortContextualTutorialDefinition_POI : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortContextualTutorialDefinition_POI")
	FGameplayTagContainer POIsToTrack;

	UPROPERTY(EditDefaultsOnly, Category="FortContextualTutorialDefinition_POI")
	FGameplayTagContainer ContextTagsToTrack;

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_POI")
	bool bCheckPOIOnActivationBinding;

};

