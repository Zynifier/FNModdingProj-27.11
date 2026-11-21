// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortAIControllerComponent_Tempest.generated.h"

class UFortTimeOfDayWeatherComponent;

UCLASS(HideCategories=("ComponentTick", "ComponentReplication", "Tags", "Activation", "AssetUserData", "Collision", "Trigger", "PhysicsVolume"))
class UFortAIControllerComponent_Tempest : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortTimeOfDayWeatherComponent> WeatherComponent;

};

