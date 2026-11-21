// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_WeaponAbility.generated.h"

UCLASS()
class UFortContextualTutorial_WeaponAbility : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleAbilityTrigger(const FGameplayTag Tags, int32 Count);

	UFUNCTION()
	void HandleStartSkydivingForActivation();

};

