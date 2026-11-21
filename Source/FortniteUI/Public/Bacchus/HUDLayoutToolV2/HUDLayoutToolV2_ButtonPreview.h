// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/HUDLayoutToolV2/HUDLayoutToolV2_WidgetPreview.h"
#include "HUDLayoutToolV2_ButtonPreview.generated.h"

class UImage;

UCLASS(Abstract)
class UHUDLayoutToolV2_ButtonPreview : public UHUDLayoutToolV2_WidgetPreview
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

};

