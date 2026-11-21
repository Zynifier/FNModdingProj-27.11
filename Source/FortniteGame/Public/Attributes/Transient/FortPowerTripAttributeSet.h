// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/Interface/FortAttributeFuelInterface.h"
#include "FortPowerTripAttributeSet.generated.h"

UCLASS(BlueprintType)
class UFortPowerTripAttributeSet : public UFortAttributeSet, public IFortAttributeFuelInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortPowerTripAttributeSet")
	FFortGameplayAttributeData Power;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortPowerTripAttributeSet")
	FFortGameplayAttributeData MaxPower;

};

