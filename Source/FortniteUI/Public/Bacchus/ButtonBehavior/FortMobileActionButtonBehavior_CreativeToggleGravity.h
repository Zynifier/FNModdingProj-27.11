// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_CreativeToggleGravity.generated.h"

class AFortWeapon;
class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_CreativeToggleGravity : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleOnDropToFloorChanged(bool bDropToFloor);

	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativeToggleGravity")
	TObjectPtr<UPaperSprite> GravityOffSprite;

};

