// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_POI.generated.h"

class AFortPlayerControllerZone;

UCLASS(MinimalAPI)
class UFortContextualTutorial_POI : public UFortContextualTutorial
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void ActivationEventCallback(const FGameplayTag& NewTag);

	UFUNCTION()
	void HandleBindActivationTrigger(AFortPlayerControllerZone* FortPCZone);

};

