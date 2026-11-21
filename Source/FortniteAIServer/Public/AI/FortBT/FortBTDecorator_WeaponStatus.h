// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "GameplayTagContainer.h"
#include "FortBTDecorator_WeaponStatus.generated.h"

UCLASS(HideCategories=("Condition"))
class UFortBTDecorator_WeaponStatus : public UBTDecorator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortBTDecorator_WeaponStatus")
	float WeaponStatusUpdateRate;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponValid")
	uint8 bTestIfCurrentWeaponIsValid : 1;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponValid", meta=(editcondition="bTestIfCurrentWeaponIsValid"))
	uint8 bCurrentWeaponShouldBeValid : 1;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponTags")
	uint8 bTestAllowedCurrentWeaponTags : 1;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponTags", meta=(editcondition="bTestAllowedCurrentWeaponTags"))
	FGameplayTagContainer AllowedCurrentWeaponTags;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponReloading")
	uint8 bTestIfCurrentWeaponIsReloading : 1;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponReloading", meta=(editcondition="bTestIfCurrentWeaponIsReloading"))
	uint8 bCurrentWeaponShouldBeReloading : 1;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponAmmo")
	uint8 bTestIfCurrentWeaponHasAmmoInMagazine : 1;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponAmmo", meta=(editcondition="bTestIfCurrentWeaponHasAmmoInMagazine"))
	uint8 bCurrentWeaponShouldHaveAmmoInMagazine : 1;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponAmmo")
	uint8 bTestIfCurrentWeaponHasExtraAmmo : 1;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponAmmo", meta=(editcondition="bTestIfCurrentWeaponHasExtraAmmo"))
	uint8 bCurrentWeaponShouldHaveExtraAmmo : 1;

	UPROPERTY(EditAnywhere, Category="CurrentWeaponStatus")
	uint8 bAllInterestedTestsMustPass : 1;

};

