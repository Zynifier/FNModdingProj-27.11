// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/HUDLayoutToolV2/HUDLayoutToolV2_WidgetPreview.h"
#include "HUDLayoutToolV2_KeyButtonPreview.generated.h"

class UFortKeybindWidget;

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_KeyButtonPreview : public UHUDLayoutToolV2_WidgetPreview
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindWidget;

};

