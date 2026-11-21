// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_TagVisibility.h"
#include "FortMobileButtonBehaviorComponent_WeaponTagVisibility.generated.h"

class AFortWeapon;

UCLASS()
class UFortMobileButtonBehaviorComponent_WeaponTagVisibility : public UFortMobileButtonBehaviorComponent_TagVisibility
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

};

