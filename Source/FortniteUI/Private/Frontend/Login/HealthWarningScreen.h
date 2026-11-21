// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "HealthWarningScreen.generated.h"

class UCommonTextBlock;
class URestrictedCountryRatingIcons;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UHealthWarningScreen : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="HealthWarningScreen")
	float ShowTimeLength;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_HealthWarning;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URestrictedCountryRatingIcons> RatingIcons_RatingIcons;

};

