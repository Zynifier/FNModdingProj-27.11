// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AutoAimWeaponKismetLibrary.generated.h"

class AFortPawn;
class AFortPlayerPawn;
class UAutoAimWeaponPawnComponent;

UCLASS(MinimalAPI)
class UAutoAimWeaponKismetLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Auto Aim Weapon")
	static bool DoesAutoAimWeaponHaveLineOfSight(AFortPawn* SourcePawn, AFortPawn* TargetPawn);

	UFUNCTION(BlueprintCallable, Category="Auto Aim Weapon")
	static bool DoesAutoAimWeaponReticleIntersectTarget(float& OutReticleDistance, AFortPawn* SourcePawn, AFortPawn* TargetPawn, const float ReticleSize);

	UFUNCTION(BlueprintCallable, Category="Auto Aim Weapon")
	static void FindBestAutoAimTarget(AFortPawn*& OutTargetPawn, float& OutReticleDistance, AFortPlayerPawn* SourcePawn, const float ReticleSize, const float Range);

	UFUNCTION(BlueprintCallable, Category="Auto Aim Weapon")
	static UAutoAimWeaponPawnComponent* GetAutoAimWeaponPawnComponent(AFortPawn* SourcePawn);

};

