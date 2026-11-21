// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaItemShopReloadMtxInfo.generated.h"

class UAthenaDynamicReloadMtxScreenLegacy;
class UAthenaReloadMtxScreenLegacy;

USTRUCT(BlueprintType)
struct FAthenaItemShopReloadMtxInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaItemShopReloadMtxInfo")
	TArray<FName> StaticStorefrontNames;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopReloadMtxInfo")
	TArray<FName> DynamicStorefrontNames;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopReloadMtxInfo")
	FName IncrementalStorefrontName;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopReloadMtxInfo")
	FString DynamicOtherOptionOfferId;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopReloadMtxInfo")
	int32 MaxMtxQuantityToShowDynamicReloadMtx;

private:
	UPROPERTY(EditAnywhere, Category="AthenaItemShopReloadMtxInfo")
	TSoftClassPtr<UAthenaReloadMtxScreenLegacy> StaticReloadMtxScreenClass;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopReloadMtxInfo")
	TSoftClassPtr<UAthenaDynamicReloadMtxScreenLegacy> DynamicReloadMtxScreenClass;

};

