// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataDrivenServiceTypes.generated.h"

USTRUCT(BlueprintType)
struct FDataDrivenServiceBriefConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Display Text")
	FText TitleText;

	UPROPERTY(EditDefaultsOnly, Category="Display Text")
	FText DescriptionText;

	UPROPERTY(EditDefaultsOnly, Category="Display Text")
	FText TransactionText;

	UPROPERTY(EditDefaultsOnly, Category="Display Text")
	FText StockText;

	UPROPERTY(EditDefaultsOnly, Category="Display Text")
	TMap<FName, FText> CannotUseReasonParameterToDisplayText;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Choice Parameter Keys")
	FString CannotUseReasonParameterKey;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Choice Parameter Keys")
	FString CostParameterKey;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Choice Parameter Keys")
	FString StockCountParameterKey;

};

USTRUCT(BlueprintType)
struct FItemFundingUpdatedFundingData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="ItemFundingUpdatedFundingData")
	int32 StationIndex;

	UPROPERTY(BlueprintReadWrite, Category="ItemFundingUpdatedFundingData")
	int64 NewCurrentFunds;

};

UCLASS(MinimalAPI, BlueprintType)
class UServiceBriefConfigCollection : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ServiceBriefConfigCollection")
	TMap<FName, FDataDrivenServiceBriefConfig> ServiceConfigs;

};

