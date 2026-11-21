// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "BattlePassVBuckSummary.generated.h"

class UCommonRichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassVBuckSummary : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetSummary();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_TotalEarned;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_TotalToBank;

};

