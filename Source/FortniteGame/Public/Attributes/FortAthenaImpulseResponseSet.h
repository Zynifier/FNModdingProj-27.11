// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortAthenaImpulseResponseSet.generated.h"

UCLASS(BlueprintType)
class UFortAthenaImpulseResponseSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Impulse")
	FFortGameplayAttributeData ImpulseMultiplier;

	UPROPERTY(BlueprintReadOnly, Category="Impulse")
	FFortGameplayAttributeData ImpulseMagnitude;

	UPROPERTY(BlueprintReadOnly, Category="Impulse")
	FFortGameplayAttributeData ImpulseZAngle;

};

