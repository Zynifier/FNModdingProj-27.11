// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_ReloadTracker.generated.h"

class AFortWeapon;

UCLASS()
class UFortGameplayAbility_ReloadTracker : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Weapon")
	int32 GetScourceWeaponTimesReloaded() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Weapon")
	void OnSourceWeaponTimesReloadedUpdated(AFortWeapon* SourceWeapon);

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TimesReloaded, Category="FortGameplayAbility_ReloadTracker")
	float TimesReloaded;

private:
	UFUNCTION()
	void OnRep_TimesReloaded();

};

