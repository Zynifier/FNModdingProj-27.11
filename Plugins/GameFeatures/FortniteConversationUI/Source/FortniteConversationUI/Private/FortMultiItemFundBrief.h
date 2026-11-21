// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSingleItemFundBrief.h"
#include "FortMultiItemFundBrief.generated.h"

class UFortItemFundBrief;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMultiItemFundBrief : public UFortSingleItemFundBrief
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSelectedVisuals(int32 SelectedIndex);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortMultiItemFundBrief", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemFundBrief> Item_EntrySecondary;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMultiItemFundBrief", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortItemFundBrief> Item_EntryTertiary;

};

