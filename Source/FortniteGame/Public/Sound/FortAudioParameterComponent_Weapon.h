// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioParameterComponent.h"
#include "FortAudioParameterComponent_Weapon.generated.h"

class AFortWeapon;

UCLASS(BlueprintType, HideCategories=("Object", "ActorComponent", "Physics", "Rendering", "Mobility", "LOD"))
class UFortAudioParameterComponent_Weapon : public UAudioParameterComponent
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category="Weapon Parameters")
	void OnRateOfFireChanged(float NewRateOfFire);

	UFUNCTION()
	void OnTargetingChanged(bool bIsTargeting);

	UFUNCTION(BlueprintCallable, Category="Weapon Parameters")
	void OnWeaponFireAudio(AFortWeapon* Weapon);

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> CachedWeaponOwner;

};

