// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortItemQuantityPair.h"
#include "FortCollectionBookDirectPurchaseData.generated.h"

USTRUCT()
struct FFortCollectionBookDirectPurchaseData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	TArray<FFortItemQuantityPair> PurchaseCosts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	FGameplayTagContainer PurchaseCatalysts;

};

