// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaGiftingPriceWidget.generated.h"

class UCommonTextBlock;
class UWidget;
enum class EGiftingPricePresentationMode : uint8;

UENUM(BlueprintType)
enum class EGiftingPricePresentationMode : uint8
{
	MtxCurrency = 0,
	RealMoney = 1,
	Hidden = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaGiftingPriceWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetPresentationMode(EGiftingPricePresentationMode Mode);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RealMoneyPrice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FinalPrice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RegularPrice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_SalePrice;

};

