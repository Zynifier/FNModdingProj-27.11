// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Math/MathFwd.h"
#include "Components/FortGameStateComponent.h"
#include "FortGameStateComponent_SurfaceOverride.generated.h"

UCLASS(Abstract, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_SurfaceOverride : public UFortGameStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API EPhysicalSurface GetSpecialSurfaceType() const;

	UFUNCTION(BlueprintPure, Category="SurfaceOverride")
	FORTNITEGAME_API virtual bool IsLocationInSpecialSurface(const FVector& Location, const float Padding = 0.000000f) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_SurfaceOverride")
	TEnumAsByte<EPhysicalSurface> SpecialSurfaceType;

};

