// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HardcoreModifierPreviewPane.generated.h"

class UCommonTextBlock;
class UFortLazyImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UHardcoreModifierPreviewPane : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Modifier Changed"))
	void BP_HandleModifierChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleMaxLevelCompleted(int32 Level);

	UFUNCTION(BlueprintImplementableEvent)
	void SetAccoladeCount(int32 AccoladeRank, int32 NumTimesEarned);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_ChallengePreview;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_CurrentChallenge;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Top50Count;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Top25Count;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Top10Count;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Top5Count;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VRCount;

};

