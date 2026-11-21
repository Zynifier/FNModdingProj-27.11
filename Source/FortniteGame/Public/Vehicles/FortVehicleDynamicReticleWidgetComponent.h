// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "FortVehicleDynamicReticleWidgetComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Activation", "Components|Activation", "Sockets", "Base", "Lighting", "LOD", "Mesh", "Mobility", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFortVehicleDynamicReticleWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortVehicleDynamicReticleWidgetComponent")
	uint32 WeaponSeatIndex;

};

