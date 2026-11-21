// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortProgressiveStageWidget.generated.h"

class UCommonTextBlock;
class UFortProgressiveItemWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortProgressiveStageWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UFortProgressiveItemWidget* AddStageItemWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void ClearStageItemWidgets();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPeekStateChanged(bool bIsInPeekState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetTooltipText(const FText& InTooltipText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetTooltipVisible(const bool bVisible);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Month;

};

