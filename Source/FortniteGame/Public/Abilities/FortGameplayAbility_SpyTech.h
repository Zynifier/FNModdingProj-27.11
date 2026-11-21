// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_SpyTech.generated.h"

UCLASS()
class UFortGameplayAbility_SpyTech : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Spy Tech")
	void OnAbilityGranted(const FGameplayTagContainer& TagContainer);

};

