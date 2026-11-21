// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortEulaTab.generated.h"

class UFortRichTextBlockLegacy;
class UImage;
class UScrollBox;
class UWidgetSwitcher;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEulaTab : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EULA Information", meta=(ExposeOnSpawn="TRUE"))
	FString EULAKeyToShow;

private:
	UFUNCTION()
	void HandleDownloadEULAComplete(bool bSuccessful, FText EULAText, const FString& Key);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRichTextBlockLegacy> Text_EULA;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_TextSpinner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_EULAText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Spinner;

};

