// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortGameplayAbility_SpyTech_GrantItem.h"
#include "FortGameplayAbility_SpyTech_MysteryGun.generated.h"

class UFortWorldItemDefinition;

UCLASS()
class UFortGameplayAbility_SpyTech_MysteryGun : public UFortGameplayAbility_SpyTech_GrantItem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortWorldItemDefinition> LastGrantedItem;

	UPROPERTY(EditAnywhere, Category="FortGameplayAbility_SpyTech_MysteryGun")
	FGameplayTag StarterPistolTag;

	UPROPERTY(EditAnywhere, Category="FortGameplayAbility_SpyTech_MysteryGun")
	FGameplayTag WeaponTag;

};

