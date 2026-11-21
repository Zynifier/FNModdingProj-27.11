// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCampaignNewsTile.generated.h"

class UCommonBorder;
class UCommonTextBlock;
class UEpicCMSImage;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignNewsTile : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayIntroAnim();

	UFUNCTION(BlueprintImplementableEvent)
	void SetDefaultImage();

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCampaignNewsTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEpicCMSImage> CMSImage_NewsImage;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NewsTitle;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NewsBody;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_AdSpace;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCampaignNewsTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AdSpace;

};

