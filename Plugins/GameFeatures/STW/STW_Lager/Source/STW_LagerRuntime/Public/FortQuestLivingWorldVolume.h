// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortAthenaLivingWorldVolume.h"
#include "FortQuestLivingWorldVolume.generated.h"

class UFortQuestItemDefinition;

UCLASS(HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortQuestLivingWorldVolume : public AFortAthenaLivingWorldVolume
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandlePIEQuestsUpdated();

	UPROPERTY(EditAnywhere, Category="FortQuestLivingWorldVolume")
	FGameplayTagContainer NoPlayerNeedsQuestFilterTags;

	UPROPERTY(EditAnywhere, Category="FortQuestLivingWorldVolume")
	FGameplayTagContainer PlayerNeedsQuestFilterTags;

	UPROPERTY(EditAnywhere, Category="FortQuestLivingWorldVolume")
	TObjectPtr<UFortQuestItemDefinition> RequiredQuest;

};

