// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Styling/SlateBrush.h"
#include "FortEmporiumItemInfo.generated.h"

class UFortItem;

UCLASS(meta=(DisableNativeTick))
class UFortEmporiumItemInfo : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetSelectItemTagsIcon(FSlateBrush SelectItemTagsIcon);

	UFUNCTION(BlueprintImplementableEvent)
	void SetSelectItemTagsPrompt(const FText& Prompt);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTagFocus();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowSelectItemTagsPrompt(bool bShowPrompt);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateWithFortItem(const UFortItem* Item, const bool bAllowInteractiveTags);

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemInfo")
	TArray<FName> HiddenTags;

};

