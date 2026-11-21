// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SoundModulationParameter.h"
#include "SoundModulationParameterFortnite.generated.h"

// Modulation Parameter whose values are mixed via addition.

UCLASS(MinimalAPI, BlueprintType)
class USoundModulationParameterAdditive : public USoundModulationParameter
{
	GENERATED_BODY()

public:
	/** Unit minimum of modulator. Minimum is only enforced at modulation destination. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", meta=(ClampMin="0.0"))
	float UnitMin;

	/** Unit maximum of modulator. Maximum is only enforced at modulation destination. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General", meta=(ClampMin="0.0"))
	float UnitMax;

};

