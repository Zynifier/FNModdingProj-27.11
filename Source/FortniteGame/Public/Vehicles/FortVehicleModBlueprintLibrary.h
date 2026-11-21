// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortVehicleModBlueprintLibrary.generated.h"

class UPrimitiveComponent;

UCLASS(MinimalAPI)
class UFortVehicleModBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	static void WeldVehicleMod(UPrimitiveComponent* VehicleComponent, UPrimitiveComponent* ModComponent, FName InSocketName = NAME_None);

};

