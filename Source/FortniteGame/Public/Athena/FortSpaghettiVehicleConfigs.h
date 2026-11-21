// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortOctopusVehicleConfigs.h"
#include "FortSpaghettiVehicleConfigs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortSpaghettiVehicleConfigs : public UFortOctopusVehicleConfigs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="DestructionCollision")
	float UnusedProp;

};

