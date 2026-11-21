// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaEquippedItemWidgetExtension.generated.h"

class AFortWeapon;
class UFortHUDContext;

UCLASS(MinimalAPI)
class UAthenaEquippedItemWidgetExtension : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponEquipped(AFortWeapon* NewWeapon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponModSlotsChanged(AFortWeapon* CurrentWeapon);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponRemoved();

private:
	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION()
	void HandleWeaponUnEquipped();

	UPROPERTY(Transient)
	UFortHUDContext* HUDContext;

};

