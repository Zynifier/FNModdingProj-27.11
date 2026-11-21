// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Common/FortTextButton.h"
#include "FortActivityBrowserSoloButton.generated.h"

class UCommonTextBlock;
class UCommonTextStyle;
class UMaterialInterface;

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UFortActivityBrowserSoloButton : public UFortTextButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetSecondaryText(const FText& InSecondaryText);

private:
	UPROPERTY(EditAnywhere, Category="Button Options")
	FText SecondaryText;

	UPROPERTY(EditAnywhere, Category="Button Options")
	TSubclassOf<UCommonTextStyle> SecondaryTextStyle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserSoloButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Secondary;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Mobile Override Options", meta=(AllowPrivateAccess))
	bool bEnableMobileOverrides;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Mobile Override Options", meta=(AllowPrivateAccess, EditCondition="bEnableMobileOverrides"))
	int32 MinWidthOverride;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Mobile Override Options", meta=(AllowPrivateAccess, EditCondition="bEnableMobileOverrides"))
	int32 MinHeightOverride;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Mobile Override Options", meta=(AllowPrivateAccess, EditCondition="bEnableMobileOverrides"))
	FMargin TextPaddingOverride;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Mobile Override Options", meta=(AllowPrivateAccess, EditCondition="bEnableMobileOverrides"))
	int32 FontSizeOverride;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Mobile Override Options", meta=(AllowPrivateAccess, EditCondition="bEnableMobileOverrides"))
	TObjectPtr<UMaterialInterface> MaterialOverride;

};

