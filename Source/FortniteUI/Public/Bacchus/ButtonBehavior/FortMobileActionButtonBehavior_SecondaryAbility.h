// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_SecondaryAbility.generated.h"

class AFortWeapon;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortMobileActionButtonBehavior_SecondaryAbility : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

};

