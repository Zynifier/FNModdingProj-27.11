// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortCatalogTypes.generated.h"

USTRUCT()
struct FFortCurrencyData : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCurrencyData")
	FString TemplateName;

	UPROPERTY(EditDefaultsOnly, Category="FortCurrencyData")
	int32 MaxStackSize;

	UPROPERTY(EditDefaultsOnly, Category="FortCurrencyData")
	int32 MaxNumStacks;

	UPROPERTY(EditDefaultsOnly, Category="FortCurrencyData")
	FString ProfileType;

	UPROPERTY(EditDefaultsOnly, Category="FortCurrencyData")
	FString Platform;

	UPROPERTY(EditDefaultsOnly, Category="FortCurrencyData")
	bool bPrivate;

};

USTRUCT()
struct FFortProceduralCatalogCostPriceFactor : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortProceduralCatalogCostPriceFactor")
	float PriceFactor;

};

