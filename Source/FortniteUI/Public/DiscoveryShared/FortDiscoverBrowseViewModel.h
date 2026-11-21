// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DiscoveryShared/FortDiscoverSurfaceViewModel.h"
#include "FortDiscoverBrowseViewModel.generated.h"

class UFortActivityViewModel;
class UFortDiscoverProviderViewModel;

UCLASS(MinimalAPI, meta=(DisplayName="Discover Browse View Model"))
class UFortDiscoverBrowseViewModel : public UFortDiscoverSurfaceViewModel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const UFortDiscoverProviderViewModel* GetAllCategoriesProviderViewModel() const;

	UFUNCTION(BlueprintPure)
	const UFortDiscoverProviderViewModel* GetFeaturedCategoriesProviderViewModel() const;

	UFUNCTION(BlueprintCallable)
	void SetDataFromProviders();

private:
	UPROPERTY(BlueprintReadOnly, Category="Discover Browse", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortActivityViewModel>> FeaturedCategories;

	UPROPERTY(BlueprintReadOnly, Category="Discover Browse", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortActivityViewModel>> AllCategories;

	UPROPERTY(BlueprintReadOnly, Category="Discover Browse", meta=(AllowPrivateAccess))
	FText FeaturedCategoriesPanelDisplayName;

	UPROPERTY(BlueprintReadOnly, Category="Discover Browse", meta=(AllowPrivateAccess))
	FText AllCategoriesPanelDisplayName;

};

