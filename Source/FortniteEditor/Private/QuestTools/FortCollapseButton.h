// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Styling/SlateBrush.h"
#include "FortCollapseButton.generated.h"

class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCollapseButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetToCollapse(UWidget* InWidgetToCollapse);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnVisibilityStateBrushChanged(const FSlateBrush& Brush) const;

	UPROPERTY(EditAnywhere, Category="FortCollapseButton")
	FSlateBrush WidgetVisibleBrushOverride;

	UPROPERTY(EditAnywhere, Category="FortCollapseButton")
	FSlateBrush WidgetCollapsedBrushOverride;

private:
	UPROPERTY(Export)
	TWeakObjectPtr<UWidget> WidgetToCollapse;

};

