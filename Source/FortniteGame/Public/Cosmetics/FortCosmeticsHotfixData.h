// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "FortCosmeticsHotfixData.generated.h"

USTRUCT()
struct FAdditionalPartCount
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ItemPersistentCosmeticName;

	UPROPERTY()
	int32 IncrementPartsBy;

};

UCLASS(Config=Game, MinimalAPI)
class UFortCosmeticsHotfixData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TArray<FVariantUID> VariantsProhibitedByHotfix;

	UPROPERTY(Config)
	TSet<FString> CosmeticsProhibitedByHotfix;

	UPROPERTY(Config)
	TSet<FString> CosmeticsProhibitedByHotfixInCompetitive;

	UPROPERTY(Config)
	TSet<FString> CosmeticsProhibitedByHotfixInCampaign;

	UPROPERTY(Config)
	TSet<FString> CosmeticsProhibitedByHotfixInAthena;

private:
	UPROPERTY(Config)
	TSet<FString> CosmeticsProhibitedFromUsingFlowgraphByHotfix;

	UPROPERTY(Config)
	TSet<FString> CosmeticsThatProhibitFlowgraphsWhenPresentWithinOverrideStack;

	UPROPERTY(Config)
	TSet<FString> CosmeticsRestrictedToTeenByHotfix;

	UPROPERTY(Config)
	TArray<FAdditionalPartCount> CosmeticsAddAdditionalPartsToBudgetByHotfix;

};

