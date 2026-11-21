// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortVehicleTeleportPortal.generated.h"

class AActor;

UINTERFACE(MinimalAPI, BlueprintType)
class UVehicleTeleportPortal : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IVehicleTeleportPortal
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void NotifyTeleportedVehicle(AActor* VehicleActor);

};

