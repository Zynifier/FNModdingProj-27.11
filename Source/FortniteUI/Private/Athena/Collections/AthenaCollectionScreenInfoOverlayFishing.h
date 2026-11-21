// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionScreenInfoOverlay.h"
#include "AthenaCollectionScreenInfoOverlayFishing.generated.h"

class UCommonRichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaCollectionScreenInfoOverlayFishing : public UAthenaCollectionScreenInfoOverlay
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Normalized Length Set"))
	void BP_OnNormalizedLengthSet(float NormalizedLength, float NormalizedMinLength, float NormalizedMaxLength);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Star Rating Set"))
	void BP_OnStarRatingSet(int32 NumStars);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="1.000000", ClampMin="0.000000", DisplayName="Normalized Length"))
	float DesignTime_NormalizedLength;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="1.000000", ClampMin="0.000000", DisplayName="Normalized Min Length"))
	float DesignTime_NormalizedMinLength;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="1.000000", ClampMin="0.000000", DisplayName="Normalized Max Length"))
	float DesignTime_NormalizedMaxLength;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(ClampMax="3", ClampMin="1", DisplayName="Star Rating"))
	int32 DesignTime_StarRating;
#endif

	UPROPERTY(BlueprintReadOnly, Category="AthenaCollectionScreenInfoOverlayFishing")
	bool bNeedsProFishingRod;

private:
	UPROPERTY(EditAnywhere, Category="Text")
	FText NoneText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_PersonalBest;

	UPROPERTY(EditAnywhere, Category="Text")
	FText ScaleRangeTextFormat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_ScaleRange;

};

