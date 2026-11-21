// Copyright Epic Games, Inc. All Rights Reserved.

#include "Camera/WeaponCameraFunctionLibrary.h"

void UWeaponCameraFunctionLibrary::FindOrAddCameraModifierForPawnNative(TSubclassOf<UCameraModifier> ModifierClass, const AActor* InPawnActor, UCameraModifier*& OutModifier)
{
}

void UWeaponCameraFunctionLibrary::FindOrAddCameraModifierNative(TSubclassOf<UCameraModifier> ModifierClass, const AFortWeaponRanged* InWeapon, UCameraModifier*& OutModifier)
{
}

void UWeaponCameraFunctionLibrary::FireCameraShake(AFortWeaponRanged* Weapon, TSubclassOf<UPrimaryDataAsset> ShakeDataClass, UFortWeaponCameraAnimation*& ActiveCameraModifier, const bool bShouldSetBPShakeData)
{
}

void UWeaponCameraFunctionLibrary::FiringCameraShakeNative(AFortWeaponRanged* Weapon)
{
}

bool UWeaponCameraFunctionLibrary::UseWeaponCameraFunctionLibraryNativeImplementation()
{
	return false;
}
