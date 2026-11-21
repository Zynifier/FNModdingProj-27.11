// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortActivitySelector.generated.h"

class UFortActivityBrowserColorSchemeAsset;
class UFortActivityCreatorPageView;
class UFortGameActivity;
class UUserWidget;

UCLASS()
class UFortActivitySelector : public UObject
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnableColorScheme(const bool bIsColorSchemeActive);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSwapColorScheme(const bool bInIsUsingAlternateColorScheme);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivity> SelectedGameActivity;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> SelectedContextWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActivityCreatorPageView> CachedCreatorPageView;

	UPROPERTY(EditDefaultsOnly, Category="FortActivitySelector")
	TMap<FName, TObjectPtr<UFortActivityBrowserColorSchemeAsset>> ColorSchemes;

	UPROPERTY(Transient)
	TObjectPtr<UFortActivityBrowserColorSchemeAsset> CurrentColorScheme;

};

