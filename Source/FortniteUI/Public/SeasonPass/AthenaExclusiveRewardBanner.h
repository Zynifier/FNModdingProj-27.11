// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaExclusiveRewardBanner.generated.h"

class UCommonRichTextBlock;
class UFortLazyImage;
class UTexture2D;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaExclusiveRewardBanner : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnClearBanner();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitBanner();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitBannerIcon(const UTexture2D* RewardIcon);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_RewardMessage;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaExclusiveRewardBanner", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_RewardIcon;

};

