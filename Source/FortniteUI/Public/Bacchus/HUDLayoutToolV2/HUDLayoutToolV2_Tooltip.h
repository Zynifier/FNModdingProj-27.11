// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HUDLayoutToolV2_Tooltip.generated.h"

class UCommonTextBlock;

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_Tooltip : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Description;

};

