// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_TagIconPicker.h"
#include "FortMobileButtonBehaviorComponent_WeaponIconPicker.generated.h"

class AFortWeapon;

UCLASS()
class UFortMobileButtonBehaviorComponent_WeaponIconPicker : public UFortMobileButtonBehaviorComponent_TagIconPicker
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

};

