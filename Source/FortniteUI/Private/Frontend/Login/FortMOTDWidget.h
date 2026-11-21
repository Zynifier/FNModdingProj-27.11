// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortMOTDWidget.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UScrollBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMOTDWidget : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Body;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox;

};

