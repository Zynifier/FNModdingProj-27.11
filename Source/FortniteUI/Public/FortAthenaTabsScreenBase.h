// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "Feature/FortUIFeature.h"
#include "FortAthenaTabsScreenBase.generated.h"

class UCommonWidgetSwitcherLegacy;
class UFortMtxStoreRootBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortAthenaTabsScreenBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortAthenaTabsScreenBase")
	TArray<EFortUIFeature> TabsUIFeature;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> TabContentSwitcher;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMtxStoreRootBase> StoreMain_Root;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaTabsScreenBase", meta=(AllowPrivateAccess, Categories="ERG.Camera"))
	FGameplayTag SeasonTrailerAutoplayEndingCamera;

};

