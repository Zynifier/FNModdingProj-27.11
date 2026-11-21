// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Mobile/BacchusButton.h"
#include "BacchusAvailablePickupButton.generated.h"

class UCommonRichTextBlock;
class UFortLazyImage;
class UFortMultiSizeItemCard;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBacchusAvailablePickupButton : public UBacchusButton
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> ItemCard_BackgroundGradient;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_AmmoIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Quantity_Text;

};

