// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortBattlePassTutorialTooltip.generated.h"

class UCommonRichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBattlePassTutorialTooltip : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetText(FText Text);

	UFUNCTION(BlueprintCallable)
	void SetTooltipEnabled(const bool bEnable);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HideTooltip();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowTooltip();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassTutorialTooltip", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Tooltip;

};

