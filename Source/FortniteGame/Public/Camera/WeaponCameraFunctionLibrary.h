// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WeaponCameraFunctionLibrary.generated.h"

class AActor;
class AFortWeaponRanged;
class UCameraModifier;
class UFortWeaponCameraAnimation;
class UPrimaryDataAsset;

UCLASS()
class FORTNITEGAME_API UWeaponCameraFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void FindOrAddCameraModifierForPawnNative(TSubclassOf<UCameraModifier> ModifierClass, const AActor* InPawnActor, UCameraModifier*& OutModifier);

	UFUNCTION(BlueprintCallable)
	static void FindOrAddCameraModifierNative(TSubclassOf<UCameraModifier> ModifierClass, const AFortWeaponRanged* InWeapon, UCameraModifier*& OutModifier);

	UFUNCTION(BlueprintCallable)
	static void FireCameraShake(AFortWeaponRanged* Weapon, TSubclassOf<UPrimaryDataAsset> ShakeDataClass, UFortWeaponCameraAnimation*& ActiveCameraModifier, const bool bShouldSetBPShakeData = true);

	UFUNCTION(BlueprintCallable)
	static void FiringCameraShakeNative(AFortWeaponRanged* Weapon);

	UFUNCTION(BlueprintPure)
	static bool UseWeaponCameraFunctionLibraryNativeImplementation();

};

