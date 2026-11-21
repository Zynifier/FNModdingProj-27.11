// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/HUDLayoutToolV2/HUDLayoutToolV2_WidgetPreview.h"
#include "HUDLayoutToolV2_MoveStickPreview.generated.h"

class UOverlay;

UCLASS()
class UHUDLayoutToolV2_MoveStickPreview : public UHUDLayoutToolV2_WidgetPreview
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ImprovedMoveStick;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_OriginalMoveStick;

};

