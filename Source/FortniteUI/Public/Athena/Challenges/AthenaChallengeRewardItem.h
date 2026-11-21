// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaChallengeRewardItem.generated.h"

class UCommonTextBlock;
class UFortLazyImage;
class UImage;
class UPanelWidget;

UCLASS(Abstract, meta=(Category="FortniteUI", DisableNativeTick))
class UAthenaChallengeRewardItem : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeRewardItem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_RewardIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RewardCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_RewardBacking;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_Lock;

};

