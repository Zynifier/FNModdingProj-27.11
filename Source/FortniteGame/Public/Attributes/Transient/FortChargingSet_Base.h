// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TickableAttributeSetInterface.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/Interface/FortAttributeFuelInterface.h"
#include "FortChargingSet_Base.generated.h"

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortChargingSet_Base : public UFortAttributeSet, public IFortAttributeFuelInterface, public ITickableAttributeSetInterface
{
	GENERATED_BODY()

public:
	FORTNITEGAME_API virtual void Tick(float DeltaTime) override;

	FORTNITEGAME_API virtual bool ShouldTick() const override;

};

