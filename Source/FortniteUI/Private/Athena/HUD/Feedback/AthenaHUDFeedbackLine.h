// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaHUDFeedbackLine.generated.h"

class UCommonRichTextBlock;
class UFortKeybindWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaHUDFeedbackLine : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowEnabledUpdated(const bool bShowEnabled);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind_Feedback;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Feedback;

};

