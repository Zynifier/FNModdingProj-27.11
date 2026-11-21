// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAttributeFuelInterface.generated.h"

UENUM()
enum class EFortFuelGadgetVisualType : uint8
{
	FuelMeter = 0,
	ChargeText = 1,
	Invalid = 2,
};

UINTERFACE(MinimalAPI)
class UFortAttributeFuelInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortAttributeFuelInterface
{
	GENERATED_BODY()

};

