// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_ScoutDrone.generated.h"

class AActor;
class AFortPlayerController;

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ScoutDrone : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnViewTargetChanged(AFortPlayerController* PlayerController, AActor* OldViewTarget, AActor* NewViewTarget);

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	FGameplayTagContainer DroneAllowedInteractionTags;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	FGameplayTagContainer DroneBlockedInteractionTags;

	UPROPERTY(Transient)
	bool bIsControllingDrone;

};

