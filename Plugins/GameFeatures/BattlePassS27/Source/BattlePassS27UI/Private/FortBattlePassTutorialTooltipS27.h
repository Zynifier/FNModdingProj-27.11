// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortBattlePassTutorialTooltipS27.generated.h"

class UCommonRichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBattlePassTutorialTooltipS27 : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetText(FText Text);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HideTooltip();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowTooltip();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassTutorialTooltipS27", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Tooltip;

};

