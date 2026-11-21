// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_RockVehicle.generated.h"

UCLASS()
class UFortCheatManager_RockVehicle : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, Category="RockVehicle")
	void RockVehicleSetBalboaVelocity(float X, float Y, float Z);

	UFUNCTION(Exec, Category="RockVehicle")
	void RockVehicleSetLocation(float X, float Y, float Z);

	UFUNCTION(Exec, Category="RockVehicle")
	void RockVehicleSetRotation(float Pitch, float Yaw, float Roll);

	UFUNCTION(Exec, Category="RockVehicle")
	void RockVehicleSetVelocity(float X, float Y, float Z);

};

