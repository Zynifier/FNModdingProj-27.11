// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_QuickHeal.generated.h"

class AFortWeapon;
class APawn;
class UInputComponent;
class UQuickHealItemPicker;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_QuickHeal : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UQuickHealItemPicker> QuickHealItemPicker;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> QuickHealInputComponent;

private:
	UFUNCTION()
	void HandleWeaponChanged(AFortWeapon* NewWeapon, AFortWeapon* OldWeapon);

	UFUNCTION()
	void OnPlayerPawnPossessed(APawn* OldPawn, APawn* NewPawn);

	UFUNCTION()
	void OnWeaponUnholstered();

};

