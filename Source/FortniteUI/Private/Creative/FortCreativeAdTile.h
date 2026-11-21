// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Context/CMSContext.h"
#include "FortCreativeAdTile.generated.h"

class UEpicCMSImage;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeAdTile : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCMSDataUpdated();

	UFUNCTION(BlueprintCallable)
	void PopulateAdTile(const FCreativeAdData& Entry);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeAdTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEpicCMSImage> Image_CreativeAd;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeAdTile")
	FCreativeAdData CMSAdEntry;

};

