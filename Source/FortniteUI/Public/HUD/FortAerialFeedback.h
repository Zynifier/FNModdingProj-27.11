// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortAerialFeedback.generated.h"

class UCommonTextBlock;
class UFortKeybindWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortAerialFeedback : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Feedback;

};

