// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/Feedback/AthenaHUDSituationalFeedback.h"
#include "AthenaGenericKeyBindsFeedback.generated.h"

class AFortWeapon;

USTRUCT()
struct FGenericAction
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaGenericKeyBindsFeedback : public UAthenaHUDSituationalFeedback
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleDBNOCarryPlayerChanged(bool bIsCarrying);

	UFUNCTION()
	void HandleEnterExitVehicle();

	UFUNCTION()
	void HandleGenericActionAdded(FName ActionName, FText DescriptionText);

	UFUNCTION()
	void HandleGenericActionRemoved(FName ActionName);

	UFUNCTION()
	void HandleInputComponentDisplayTextChanged();

	UFUNCTION()
	void HandleInputStackChanged();

	UFUNCTION()
	void HandleKeybindsChanged();

	UFUNCTION()
	void HandleSavedTabChanged(bool IsTabSaved);

	UFUNCTION()
	void HandleTetherChanged(bool bIsTethered);

	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon);

	UFUNCTION()
	void HandleWeaponHUDKeyActionUpdated(AFortWeapon* Weapon);

	UPROPERTY()
	TArray<FGenericAction> GenericActions;

	UPROPERTY(EditDefaultsOnly, Category="Feedback Lines")
	float DimmedOpacity;

};

