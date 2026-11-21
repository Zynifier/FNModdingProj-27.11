// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HUDLayoutToolV2_TooltipLayer.generated.h"

class UHUDLayoutToolV2_Tooltip;

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_TooltipLayer : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Tooltip> Tooltip_Message;

};

