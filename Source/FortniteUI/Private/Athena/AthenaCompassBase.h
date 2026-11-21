// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateBrush.h"
#include "FortHUDElementWidget.h"
#include "AthenaCompassBase.generated.h"

class UCurveFloat;
class UImage;
class UMaterialInstanceDynamic;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCompassBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> CompassMaterial;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Compass;

	UPROPERTY(EditDefaultsOnly, Category="Compass")
	FSlateBrush MarkerBrush;

	UPROPERTY(EditDefaultsOnly, Category="Compass")
	FSlateBrush HeadingIndicatorBrush;

	UPROPERTY(EditDefaultsOnly, Category="Compass")
	FSlateBrush StormIndicatorBrush;

	UPROPERTY(EditDefaultsOnly, Category="Compass")
	float MarkerVerticalOffset;

	UPROPERTY(EditDefaultsOnly, Category="Compass")
	float DistanceTextVerticalOffset;

	UPROPERTY(EditDefaultsOnly, Category="Compass")
	float DistanceTextHorizontalOffset;

	UPROPERTY(EditDefaultsOnly, Category="Compass")
	FSlateFontInfo HeadingFont;

	UPROPERTY(EditDefaultsOnly, Category="Compass")
	FSlateFontInfo DistanceTextFont;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Gunshot Indicators", meta=(DisplayName="Teammate Brush"))
	FSlateBrush TeammateGunshotIndicatorBrush;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Gunshot Indicators", meta=(DisplayName="Enemy Brush"))
	FSlateBrush EnemyGunshotIndicatorBrush;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Gunshot Indicators", meta=(DisplayName="Time To Show"))
	float TimeToShowGunshotIndicators;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Gunshot Indicators", meta=(DisplayName="Scale Over Time"))
	TObjectPtr<UCurveFloat> GunshotIndicatorScaleOverTime;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Gunshot Indicators", meta=(DisplayName="Scale By Strength"))
	TObjectPtr<UCurveFloat> GunshotIndicatorScaleByStrength;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Gunshot Indicators", meta=(DisplayName="Alpha Over Time"))
	TObjectPtr<UCurveFloat> GunshotIndicatorAlphaOverTime;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Gunshot Indicators", meta=(DisplayName="Alpha By Heading"))
	TObjectPtr<UCurveFloat> GunshotIndicatorAlphaByHeading;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Pinned Quest")
	FSlateBrush DefaultPinnedQuestIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Pinned Quest", meta=(ClampMax="180.000000", ClampMin="90.000000"))
	float PinnedQuestAlphaRotCutoff;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Pinned Quest", meta=(ClampMax="180.000000", ClampMin="90.000000"))
	float PinnedQuestDistanceRotCutoff;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Pinned Quest")
	float PinnedQuestIconVerticalOffset;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Pinned Quest")
	float PinnedQuestDistanceTextVerticalOffset;

	UPROPERTY(EditDefaultsOnly, Category="Compass|Pinned Quest")
	FSlateFontInfo PinnedQuestDistanceTextFont;

};

