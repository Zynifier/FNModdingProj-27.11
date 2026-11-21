// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityPlayerBrowserView.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortActivityCategoryPageView.generated.h"

class UCommonButtonBase;
class UCommonRichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityCategoryPageView : public UFortActivityPlayerBrowserView, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_CategoryTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityCategoryPageView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackToTop;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MobileAccept;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MobileShowGameDetails;

};

