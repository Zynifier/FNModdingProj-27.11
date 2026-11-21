// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortVehicleSoundComponent.h"
#include "Sound/FortAudioTypes.h"
#include "FortVehicleSoundComponent_Speed.generated.h"

UCLASS(HideDropdown, BlueprintType, Blueprintable, HideCategories=("Tags", "ComponentReplication", "Activation", "Variable", "Cooking", "AssetUserData", "Replication", "Collision"), meta=(ChildCanTick))
class VEHICLEAUDIORUNTIME_API UFortVehicleSoundComponent_Speed : public UFortVehicleSoundComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnReversedChanged(bool bReversing);

	UPROPERTY(EditDefaultsOnly, Category="VehicleSound|Native")
	FFortAudioFloatParameter Speed;

};

