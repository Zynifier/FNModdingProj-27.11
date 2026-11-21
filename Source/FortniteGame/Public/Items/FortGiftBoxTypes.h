// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGiftBoxTypes.generated.h"

USTRUCT(BlueprintType)
struct FCurrencyData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CurrencyData")
	FText BundleTemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CurrencyData")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CurrencyData")
	FText QuestTemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CurrencyData")
	FText CurrencyTemplateId;

};

