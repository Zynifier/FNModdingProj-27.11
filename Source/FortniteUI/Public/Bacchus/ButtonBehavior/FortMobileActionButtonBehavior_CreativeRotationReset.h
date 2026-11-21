// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_CreativeRotationReset.generated.h"

class AFortWeapon;

UCLASS()
class UFortMobileActionButtonBehavior_CreativeRotationReset : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleMoveToolRotationModified(FQuat CurrentRotationOffset);

	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

};

