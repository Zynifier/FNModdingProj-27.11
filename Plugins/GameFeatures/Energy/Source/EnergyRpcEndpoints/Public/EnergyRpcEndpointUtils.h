// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnergyRpcEndpointUtils.generated.h"

class UFortComponent_Energy;

UCLASS()
class UEnergyRpcEndpointUtils : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static UFortComponent_Energy* GetEnergyComponentFromPlayer();

};

