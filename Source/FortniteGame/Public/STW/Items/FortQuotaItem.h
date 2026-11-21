// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortQuotaItem.generated.h"

UCLASS(MinimalAPI)
class UFortQuotaItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quota")
	int32 GetCurrentQuotaAmount();

	UPROPERTY(BlueprintReadOnly, Category="FortQuotaItem")
	float current_value;

	UPROPERTY()
	FString last_mod_time;

	UPROPERTY()
	int32 units_per_minute_recharge;

	UPROPERTY()
	int32 max_quota;

	UPROPERTY()
	int32 recharge_delay_minutes;

};

