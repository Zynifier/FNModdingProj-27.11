// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorialDefinition.h"
#include "FortContextualTutorialDefinition_WeaponAbility.generated.h"

UCLASS(MinimalAPI)
class UFortContextualTutorialDefinition_WeaponAbility : public UFortContextualTutorialDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_WeaponAbility")
	FGameplayTagContainer WeaponTags;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_WeaponAbility")
	FGameplayTag AbilityTag;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_WeaponAbility")
	bool bTriggerOnAmmoCount;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_WeaponAbility")
	int32 TriggerAmmoCount;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_WeaponAbility")
	bool bSuccessOnAmmoCount;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_WeaponAbility")
	int32 SuccessAmmoCount;

	UPROPERTY(EditAnywhere, Config, Category="FortContextualTutorialDefinition_WeaponAbility")
	FGameplayTagContainer BlockedByTags;

};

