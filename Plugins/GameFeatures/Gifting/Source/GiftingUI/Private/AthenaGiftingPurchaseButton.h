// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHoldableButton.h"
#include "AthenaGiftingPurchaseButton.generated.h"

class UAthenaGiftingPriceWidget;
class UCommonTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaGiftingPurchaseButton : public UFortHoldableButton
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGiftingPriceWidget> Widget_Price;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

};

