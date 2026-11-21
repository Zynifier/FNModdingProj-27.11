// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "FortControllerComponent_TriggerHaptics.generated.h"

class AFortPawn;
class AFortWeapon;

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_TriggerHaptics : public UControllerComponent
{
	GENERATED_BODY()

public:
	UFortControllerComponent_TriggerHaptics(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION()
	void UpdateTriggerHaptics();

private:
	UFUNCTION()
	void OnPawnChanged(AFortPawn* InPawn);

	UFUNCTION()
	void OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

	UFUNCTION()
	void ResetTriggerHaptics();

	UPROPERTY(Config)
	uint8 bTriggerHapticsAvailable : 1;

};

