// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "WeaponOverheatWidget.generated.h"

class AFortWeapon;
class UImage;

UCLASS()
class UWeaponOverheatWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPawnChanged();

	UFUNCTION()
	void OnWeaponEquipped(AFortWeapon* CurrentWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION()
	void OnWeaponUnEquipped();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> OverheatProgressImage;

};

