// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FortFirstPersonCameraController.h"
#include "FortCreativeOptionVariableBase.h"
#include "FortCreativeEditCameraController.generated.h"

class AFortWeapon;
class UFortCreativeOption;

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortCreativeEditCameraController : public AFortFirstPersonCameraController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeEditCameraController")
	FCreativeOptionVariableBase WantsToImmersiveEdit;

private:
	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION()
	void OnCreativeEditModeChanged(bool bIsCreativeEditModeEnabled);

	UFUNCTION()
	void OnWantsToImmersiveEditChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetImmersiveEdit(const bool bWantsToImmersiveEdit, const bool bIsCreativeEditModeEnabled);

};

