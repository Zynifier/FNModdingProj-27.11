// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "CommonButtonLegacy.h"
#include "FortSimpleFeaturedYellowButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSimpleFeaturedYellowButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ChangeSecondaryText(const FText& NewText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetText(const FText& NewText);

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void RefreshUI();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSimpleFeaturedYellowButton")
	int32 FontSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSimpleFeaturedYellowButton")
	FMargin PaddingOverrideMargin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSimpleFeaturedYellowButton")
	float DelayShine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSimpleFeaturedYellowButton")
	bool bFontSizeOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSimpleFeaturedYellowButton")
	bool bPaddingOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSimpleFeaturedYellowButton")
	bool bUseShineSwipe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortSimpleFeaturedYellowButton")
	bool bShearText;

};

