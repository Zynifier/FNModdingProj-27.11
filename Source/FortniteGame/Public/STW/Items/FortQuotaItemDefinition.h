// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortQuotaItemDefinition.generated.h"

UCLASS(BlueprintType)
class UFortQuotaItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Quota")
	float StartingValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Quota")
	int32 MaximumValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Quota")
	float UnitsPerMinuteRechargeRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Quota")
	int32 RechargeDelayMinutes;

};

