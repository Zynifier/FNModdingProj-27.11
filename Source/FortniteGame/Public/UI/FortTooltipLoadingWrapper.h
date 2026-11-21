// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortTooltipLoadingWrapper.generated.h"

class UFortTooltip;
class UObject;

UCLASS(MinimalAPI, BlueprintType, meta=(ShortTooltip="Wraps a tooltip supported object and handles async loading of assets."))
class UFortTooltipLoadingWrapper : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTooltipAssetsLoaded);

public:
	UFUNCTION(BlueprintPure, Category="Tooltips")
	bool AreAssetsLoaded() const;

	UPROPERTY(BlueprintAssignable, Category="Tooltips")
	FOnTooltipAssetsLoaded OnTooltipAssetsLoaded;

private:
	UFUNCTION()
	void HandleTooltipAssetLoaded();

	UPROPERTY()
	TWeakObjectPtr<UObject> SourceObject;

	UPROPERTY()
	TObjectPtr<UFortTooltip> TooltipInstance;

};

