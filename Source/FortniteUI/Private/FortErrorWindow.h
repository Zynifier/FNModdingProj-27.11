// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortErrorWindow.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UImage;
class UScrollBox;
class UTextBlock;
class UWidgetSwitcher;

UCLASS(meta=(DisableNativeTick))
class UFortErrorWindow : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnOverrideCloseButtonText(const FText& OverrideText);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_MainError;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_MainError;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TextBlock_MainErrorCode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TextBlock_OverflowErrorCodes;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher_SeverityImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Mild;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Severe;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortErrorWindow", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> CommonButton_Close;

	UPROPERTY(EditInstanceOnly, Category="FortErrorWindow", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackActionRowHandle;

private:
	UPROPERTY(EditAnywhere, Category="Title")
	TArray<FText> MildTitles;

	UPROPERTY(EditAnywhere, Category="Title")
	TArray<FText> SevereTitles;

	UPROPERTY(EditAnywhere, Category="FortErrorWindow")
	uint32 MaxOverflowErrorCodes;

};

