// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Math/Color.h"
#include "FortCreativeCreditsAttributions.generated.h"

class UCommonRichTextBlock;
class UCurveLinearColor;
class UTimelineComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeCreditsAttributions : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Animation")
	TObjectPtr<UCurveLinearColor> HoverAnimationCurve;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	float GetHoverAnimationLength();

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeCreditsAttributions")
	int32 AttributionsPreviewTextWordLimit;

private:
	UFUNCTION()
	void OnAnimationUpdate(FLinearColor Color) const;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreditsAttributions", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UTimelineComponent> HoverAnimationTimeline;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreditsAttributions", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_CreditsAttributionsShortDescription;

};

