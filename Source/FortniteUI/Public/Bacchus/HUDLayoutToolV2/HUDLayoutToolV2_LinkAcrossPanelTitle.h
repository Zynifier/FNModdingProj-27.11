// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HUDLayoutToolV2_LinkAcrossPanelTitle.generated.h"

class UCommonTextBlock;
class USizeBox;

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_LinkAcrossPanelTitle : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_LinkAcrossPanelTitle")
	FText AdvancedActionTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_Preview;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_WidgetName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Action;

};

