// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCMSInfoCarousel.generated.h"

class UCommonWidgetCarousel;
class UCommonWidgetCarouselNavBar;
class UEpicCMSSimpleMessage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCMSInfoCarousel : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="FortCMSInfoCarousel")
	void NavigatePageLeft();

	UFUNCTION(BlueprintCallable, Category="FortCMSInfoCarousel")
	void NavigatePageRight();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCMSInfoCarousel")
	TMap<FString, TSubclassOf<UEpicCMSSimpleMessage>> MessageWidgetLayoutMap;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCMSInfoCarousel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetCarousel> Carousel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCMSInfoCarousel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetCarouselNavBar> CarouselNavBar;

	UPROPERTY(EditAnywhere, Category="FortCMSInfoCarousel")
	FString CMSInfoId;

	UPROPERTY(EditAnywhere, Category="FortCMSInfoCarousel")
	float AutoScrollInterval;

};

