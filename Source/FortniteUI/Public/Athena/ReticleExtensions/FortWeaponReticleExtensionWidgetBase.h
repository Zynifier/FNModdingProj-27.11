// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortWeaponReticleExtensionWidgetBase.generated.h"

class AFortWeapon;
enum class EFortWeaponReloadType : uint8;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortWeaponReticleExtensionWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	FORTNITEUI_API AFortWeapon* GetEquippedWeapon() const;

	UFUNCTION(BlueprintPure)
	FORTNITEUI_API bool GetIsADS() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void HandleCooldownTimer(const bool bActivateTimer, const float TimerInterval);

	UFUNCTION()
	FORTNITEUI_API void HandleTargetingChanged(bool bNewIsADS);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnFullyExitVehicle();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnTargetingChanged(bool bIsADS);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnWeaponReloadCancelled();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnWeaponReloadStarted(float ReloadTime, EFortWeaponReloadType ReloadType);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnWeaponSingleFire();

	UFUNCTION()
	FORTNITEUI_API void SeatChangeEndedWidgetStateHandler();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FORTNITEUI_API void UpdateCooldownQueryTimer();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FORTNITEUI_API void UpdateRemainingCooldown();

private:
	UFUNCTION()
	FORTNITEUI_API void HandleEnterVehicleDriver();

	UFUNCTION()
	FORTNITEUI_API void HandleEnterVehiclePassenger();

	UFUNCTION()
	FORTNITEUI_API void HandleFullyExitVehicle();

	UFUNCTION()
	FORTNITEUI_API void HandleVehicleSeatChanged(int32 SeatIndex);

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> CachedAssociatedWeapon;

};

