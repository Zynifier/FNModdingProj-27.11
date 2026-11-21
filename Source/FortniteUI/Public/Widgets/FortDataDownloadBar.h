// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Timespan.h"
#include "FortHUDElementWidget.h"
#include "FortDataDownloadBar.generated.h"

class UCommonTextBlock;
class UFortEventDateTimeTextBlock;
class UImage;
class USizeBox;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortDataDownloadBar : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DisplayErrorAnimation(bool ErrorState);

	UFUNCTION(BlueprintCallable)
	void ExpandClose();

	UFUNCTION(BlueprintCallable)
	void SetProgress(const float Progress);

	UFUNCTION(BlueprintCallable)
	void SetRemainingTimeEstimate(const FTimespan& RemainingTime);

	UFUNCTION(BlueprintCallable)
	void SetStatusText(const FText& StatusText);

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDownloadCompleted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExpandClose(const bool IsExpanded);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStatusTextChanged();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Width Custom Scaling")
	bool bWidthCustomScaling;

	UPROPERTY(EditAnywhere, Export, Category="Width Custom Scaling", meta=(EditCondition="bWidthCustomScaling", EditInline="true", MakeEditWidget="TRUE"))
	TObjectPtr<UWidget> Container;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Interp, Category="Width Custom Scaling", meta=(ClampMax="100", ClampMin="0", EditCondition="bWidthCustomScaling"))
	float BarWidthPercentage;

	UPROPERTY(EditAnywhere, Category="Width Custom Scaling", meta=(EditCondition="bWidthCustomScaling"))
	float UpdateScalingRateInSeconds;

	UPROPERTY(EditAnywhere, Category="FortDataDownloadBar")
	float UpdateEstimatedTimeLeftRateInSeconds;

	UPROPERTY(BlueprintReadOnly, Category="FortDataDownloadBar")
	bool bBarExpanded;

	UPROPERTY(BlueprintReadWrite, Category="FortDataDownloadBar")
	bool bProgressDisplayPaused;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> BarSizeBox;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> BarProgressionImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> BarPercentageNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> StatusText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> BarErrorText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventDateTimeTextBlock> RemainingTimeEstimateText;

};

