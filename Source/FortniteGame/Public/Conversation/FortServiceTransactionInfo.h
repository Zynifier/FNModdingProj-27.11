// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortServiceTransactionInfo.generated.h"

class UFortWorldItemDefinition;

USTRUCT(BlueprintType)
struct FFortServiceTransactionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortServiceTransactionInfo")
	int32 Cost;

	UPROPERTY(BlueprintReadOnly, Category="FortServiceTransactionInfo")
	bool bPriceWasDiscounted;

	UPROPERTY(BlueprintReadOnly, Category="FortServiceTransactionInfo")
	TSoftObjectPtr<UFortWorldItemDefinition> CurrencyItem;

	UPROPERTY(BlueprintReadOnly, Category="FortServiceTransactionInfo")
	int32 OwnedCurrency;

	UPROPERTY(BlueprintReadOnly, Category="FortServiceTransactionInfo")
	bool bIsLocked;

	UPROPERTY(BlueprintReadOnly, Category="FortServiceTransactionInfo")
	int32 UnlockLevel;

};

