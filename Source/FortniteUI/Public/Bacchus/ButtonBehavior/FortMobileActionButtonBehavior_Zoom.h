// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponentTypes.h"
#include "FortMobileActionButtonBehavior_Zoom.generated.h"

class AFortWeapon;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortMobileActionButtonBehavior_Zoom : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TArray<FIconPicker> PawnSpriteOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	FGameplayTagContainer WeaponGameplayTagsToDisplay;

};

