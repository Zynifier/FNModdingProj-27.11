// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortButtonBehaviorComponentOverride.h"
#include "FortButtonBehaviorComponentOverrideVisibility_Compound.generated.h"

UCLASS()
class UFortButtonBehaviorComponentOverrideVisibility_Compound : public UFortButtonBehaviorComponentOverride
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortButtonBehaviorComponentOverrideVisibility_Compound")
	FGameplayTagQuery HUDWeaponTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortButtonBehaviorComponentOverrideVisibility_Compound")
	FGameplayTagQuery HUDAbilityTagQuery;

};

