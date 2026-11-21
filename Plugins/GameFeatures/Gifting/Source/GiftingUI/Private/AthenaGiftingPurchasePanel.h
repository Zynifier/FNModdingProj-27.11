// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaGiftingPurchasePanel.generated.h"

class UAthenaGiftingPurchaseButton;
class UCommonTextBlock;
class UFortSocialAvatarIcon;
class UTileView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaGiftingPurchasePanel : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayIntroAnimation();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGiftingPurchaseButton> Button_PurchaseGift;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Avatar_MemberIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SocialNameInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemsCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_OfferName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGiftingPurchasePanel", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UTileView> TileView_Items;

};

