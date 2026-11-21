// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaMapChallengeRewardPreview.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortCosmeticItemCard;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UAthenaMapChallengeRewardPreview : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ReplayIntroAnim();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RewardName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCosmeticItemCard> ItemCard_RewardIcon;

	UPROPERTY(EditAnywhere, Config, Category="AthenaMapChallengeRewardPreview")
	float CycleDelay;

};

