// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/FortPhysicsObjectNavigationComponent.h"
#include "FortVehicleNavModifierComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Variable", "Tags", "Cooking", "Collision", "Variable", "Tags", "Cooking", "Collision", "Variable", "Tags", "Cooking", "Collision", "Activation"), meta=(BlueprintSpawnableComponent))
class UFortVehicleNavModifierComponent : public UFortPhysicsObjectNavigationComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnVehicleSleepStateChanged(const bool bIsAwake);

};

