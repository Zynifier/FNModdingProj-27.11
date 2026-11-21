// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortToastWidget.h"
#include "FortPlayerPowerRatingToast.generated.h"

class UCommonTextBlock;
class UFortPlayerBanner;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPlayerPowerRatingToast : public UFortToastWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HideToast();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowToast();

	UPROPERTY(BlueprintReadOnly, Export, Category="PowerRatingToast", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PowerDifference;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerBanner> Banner_MemberBanner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PowerRating;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

};

