// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "Athena/Modifiers/FortAthenaMutator_WeaponSettings.h"
#include "FortPropertyOverrideData.h"
#include "FortAthenaMutator_CreativeWeaponSettings.generated.h"

class AFortVolume;
class APlayerState;

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativeWeaponSettings : public AFortAthenaMutator_WeaponSettings
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleMutatorSettingsChanged(const FPropertyOverrideData& OverrideData);

	UFUNCTION()
	void OnPlayerEnterVolume(APlayerState* Client, AFortVolume* Volume);

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_CreativeWeaponSettings")
	FPrimaryAssetId EmptyHandsWeaponAssetId;

};

