// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortGameFeatureEnum.h"
#include "FortQualityLevelSelectScreen.generated.h"

class UCommonButtonLegacy;
class UFortHUDQualityLevelSelectTimer;
class UFortQualityModeTile;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQualityLevelSelectScreen : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortQualityLevelSelectScreen")
	TSet<EFortGameFeature> GameFeaturesToVerify;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQualityModeTile> Button_SelectMediumQuality;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQualityModeTile> Button_SelectHighQuality;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortHUDQualityLevelSelectTimer> QualityLevelSelectTimer;

};

