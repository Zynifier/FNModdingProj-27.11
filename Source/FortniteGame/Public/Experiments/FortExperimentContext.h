// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "FortExperimentContext.generated.h"

UENUM()
enum class EExperimentBucket : uint8
{
	Baseline = 0,
	Variation1 = 1,
	NotInExperiment = 2,
};

UCLASS(MinimalAPI)
class UFortExperimentContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldCapMips() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldDecreaseFontSizeInDiscoveryTileTitles();

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldProposeRequiredVBucksSKUs() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldShowDynamicReloadVBucks() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldShowInGameStoreToast() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldShowNewVBuckCoinAssetsJuly2019() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldShowNewVBuckColorsJuly2019() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldUseCatabaCarousel() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldUseCatabaCarouselInGame() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldUseCatabaScreen() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldUseCatabaScreenInGame() const;

	UFUNCTION(BlueprintPure, Category="A/B Testing")
	bool ShouldUseLargeItemShopLayout() const;

};

