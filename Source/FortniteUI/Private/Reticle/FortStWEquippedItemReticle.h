// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortStWEquippedItemReticle.generated.h"

class AFortWeapon;
enum class EFortWeaponOverheatState : uint8;
enum class EFortWeaponReloadType : uint8;

UCLASS(Abstract, meta=(DisplayName="Fort StW Equipped Item Reticle"))
class UFortStWEquippedItemReticle : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleAmmoChanged(int32 MagazineAmmoCount, int32 TotalRemaining);

	UFUNCTION()
	void HandleWeaponChanged(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION()
	void HandleWeaponOverheatValueChanged(float CurrentValue, float MaxValue, EFortWeaponOverheatState State, bool bIsInCooldown);

	UFUNCTION()
	void HandleWeaponReloadCancelled();

	UFUNCTION()
	void HandleWeaponReloadStarted(float ReloadTime, EFortWeaponReloadType ReloadType);

	UFUNCTION()
	void HandleWeaponTargetingChanged(bool bIsTargeting);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAmmoChanged(int32 MagazineAmmoCount, int32 TotalRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponChanged(AFortWeapon* NewWeapon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponOverheatValueChanged(float CurrentValue, float MaxValue, EFortWeaponOverheatState State, bool bIsInCooldown);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponReloadCancelled(AFortWeapon* Weapon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponReloadStarted(float ReloadTime, EFortWeaponReloadType ReloadType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponTargetingChanged(bool bIsTargeting);

	UPROPERTY(BlueprintReadOnly, Category="Equipped Item Reticle")
	TWeakObjectPtr<AFortWeapon> BoundWeapon;

};

