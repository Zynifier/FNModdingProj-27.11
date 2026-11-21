// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StreamingRadioPlayerComponent.h"
#include "StreamingRadioPlayerComponent_Rock.generated.h"

class AController;
class AFortAthenaVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UStreamingRadioPlayerComponent_Rock : public UStreamingRadioPlayerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void VehicleExploded(const AController* LastDamageInstigator, AFortAthenaVehicle* Vehicle);

};

