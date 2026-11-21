// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Online/FortLinkEntryEnums.h"
#include "FortDiscoverSearchViewModel.generated.h"

class UFortActivityViewModel;
class UFortDiscoverBrowseViewModel;

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Discover Search Model"))
class UFortDiscoverSearchViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ActionSearch();

	UFUNCTION(BlueprintCallable)
	void ClearSearch();

	UFUNCTION(BlueprintCallable)
	void FireAnalyticsForBrowseAndSearch(UFortDiscoverBrowseViewModel* BrowseViewModel);

	UFUNCTION(BlueprintPure, Category="Discover Search")
	int32 GetIslandResultCount() const;

	UFUNCTION(BlueprintPure, Category="Discover Search")
	bool IsAnySearchActiveOrInProgress() const;

	UFUNCTION(BlueprintCallable)
	void StartAnalyticsImpressions();

	UFUNCTION(BlueprintCallable)
	void StartAnalyticsSession();

	UFUNCTION(BlueprintCallable)
	void StartAnalyticsVisibilityImpressions();

	UFUNCTION(BlueprintCallable)
	void StopAnalyticsVisibilityImpressions();

private:
	UPROPERTY(BlueprintReadWrite, Category="Discover Search", meta=(AllowPrivateAccess))
	FString SearchTerm;

	UPROPERTY(BlueprintReadOnly, Category="Discover Search", meta=(AllowPrivateAccess))
	bool bIsSearchInProgress;

	UPROPERTY(BlueprintReadOnly, Category="Discover Search", meta=(AllowPrivateAccess))
	bool bIsLinkCodeSearch;

	UPROPERTY(BlueprintReadOnly, Category="Discover Search", meta=(AllowPrivateAccess))
	FString ResultsTerm;

	UPROPERTY(BlueprintReadOnly, Category="Discover Search", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortActivityViewModel>> SearchResults;

	UPROPERTY(BlueprintReadOnly, Category="Discover Search", meta=(AllowPrivateAccess))
	ELinkEntryQueryResult LastLinkEntryQueryResult;

};

