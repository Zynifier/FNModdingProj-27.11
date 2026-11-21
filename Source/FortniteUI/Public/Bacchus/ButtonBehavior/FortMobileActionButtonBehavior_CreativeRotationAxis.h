// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_CreativeRotationAxis.generated.h"

class AFortWeapon;
class UPaperSprite;

UCLASS()
class UFortMobileActionButtonBehavior_CreativeRotationAxis : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleMoveToolRotationAxisChanged(uint8 AxisIndex);

	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativeRotationAxis")
	TObjectPtr<UPaperSprite> RotateXAxisSprite;

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativeRotationAxis")
	TObjectPtr<UPaperSprite> RotateYAxisSprite;

	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehavior_CreativeRotationAxis")
	TObjectPtr<UPaperSprite> RotateZAxisSprite;

};

