// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "McpCatalogEnums.h"
#include "McpCatalogItemPrice.generated.h"

USTRUCT()
struct GAMESUBCATALOG_API FCatalogItemSalePrice
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Sales")
	int32 SalePrice;

	UPROPERTY(EditAnywhere, Category="Sales")
	TEnumAsByte<ECatalogSaleType::Type> SaleType;

	UPROPERTY(EditAnywhere, Category="Sales")
	FDateTime StartTime;

	UPROPERTY(EditAnywhere, Category="Sales")
	FDateTime EndTime;

};

USTRUCT()
struct GAMESUBCATALOG_API FCatalogItemPrice
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Price")
	TEnumAsByte<EStoreCurrencyType::Type> CurrencyType;

	UPROPERTY(EditAnywhere, Category="Price")
	FString CurrencySubType;

	UPROPERTY(EditAnywhere, Category="Price")
	int32 RegularPrice;

	UPROPERTY()
	int32 FinalPrice;

	UPROPERTY()
	FText PriceTextOverride;

	UPROPERTY()
	TEnumAsByte<ECatalogSaleType::Type> SaleType;

	UPROPERTY()
	FDateTime SaleExpiration;

	UPROPERTY()
	EAppStore AppStoreId;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Price")
	TArray<FCatalogItemSalePrice> SalePrices;
#endif

};

