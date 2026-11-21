// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortGameFeatureData.h"
#include "FortAnnualRefundTokenData.generated.h"

class UFortPurchaseHistoryScreen;

UCLASS()
class UFortAnnualRefundTokenData : public UFortGameFeatureData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnnualRefundTokenData")
	TSoftClassPtr<UFortPurchaseHistoryScreen> PurchaseHistoryScreenClass;

};

