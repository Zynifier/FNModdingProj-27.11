// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaGiftingErrorsPanel.generated.h"

class UCommonButtonBase;
class URichTextBlock;
class UTileView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaGiftingErrorsPanel : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateGiftEligibility(bool bStillGiftable);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_RecipientInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Continue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTileView> TileView_Items;

};

