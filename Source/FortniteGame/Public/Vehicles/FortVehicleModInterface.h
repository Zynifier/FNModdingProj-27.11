// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortVehicleModInterface.generated.h"

class UFortVehicleModConfig;

UINTERFACE(MinimalAPI, BlueprintType)
class UFortVehicleModInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortVehicleModInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void CacheModConfig(const UFortVehicleModConfig* InModConfig);

	UFUNCTION()
	virtual const UFortVehicleModConfig* GetModConfig();

};

