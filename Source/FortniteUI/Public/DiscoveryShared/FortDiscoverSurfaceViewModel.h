// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortDiscoverSurfaceViewModel.generated.h"

class UFortActivityViewModel;
class UFortDiscoverProviderViewModel;

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Discover Provider View Model"))
class UFortDiscoverProviderViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Discover Surface")
	int32 GetIslandCount() const;

	UFUNCTION(BlueprintCallable)
	void ResetImpressions();

	UFUNCTION(BlueprintCallable)
	void StartVisibleImpressions();

	UFUNCTION(BlueprintCallable)
	void StopVisibleImpression();

private:
	UPROPERTY(BlueprintReadOnly, Category="Discover Surface", meta=(AllowPrivateAccess))
	FString PanelName;

	UPROPERTY(BlueprintReadOnly, Category="Discover Surface", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortActivityViewModel>> Activities;

	UPROPERTY(BlueprintReadOnly, Category="Discover Surface", meta=(AllowPrivateAccess))
	FString PanelDisplayName;

};

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Discover Surface View Model"))
class UFortDiscoverSurfaceViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void FetchNextPageFromIndex(int32 SelectionIndex, int32 ProviderIndex);

	UFUNCTION(BlueprintCallable)
	void FetchNextPageFromPanelName(int32 SelectionIndex, FName PanelName);

	UFUNCTION(BlueprintCallable)
	virtual void FireExitedImpressionsFromSurface();

	UFUNCTION(BlueprintPure)
	const int32 GetProviderIndexFromPanelName(FName PanelName) const;

	UFUNCTION(BlueprintCallable)
	void StartAnalyticsImpressions();

	UFUNCTION(BlueprintCallable)
	void StartVisibleImpressions();

	UFUNCTION(BlueprintCallable)
	void StopVisibleImpressions();

	UFUNCTION(BlueprintCallable)
	void UpdateCachedSurfaceData(const bool bShouldForceUpdate);

protected:
	UPROPERTY(BlueprintReadWrite, Category="Discover Surface", meta=(AllowPrivateAccess))
	FName SurfaceName;

private:
	UPROPERTY(BlueprintReadOnly, Category="Discover Surface", meta=(AllowPrivateAccess))
	bool bQueryingPageInProgress;

	UPROPERTY(BlueprintReadOnly, Category="Discover Surface", meta=(AllowPrivateAccess))
	TArray<TObjectPtr<UFortDiscoverProviderViewModel>> Providers;

};

