// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Common/FortMultiSizeImage.h"
#include "FortSimpleItemConditionIconIndicator.generated.h"

class UFortItem;

UCLASS(Abstract, BlueprintType)
class UFortSimpleItemConditionIconIndicator : public UFortMultiSizeImage
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Simple Item Condition Icon Indicator")
	UFortItem* GetItemToRepresent() const;

	UFUNCTION(BlueprintCallable, Category="Simple Item Condition Icon Indicator")
	void SetItemToRepresent(UFortItem* ItemToRepresent);

	UFUNCTION(BlueprintCallable, Category="Simple Item Condition Icon Indicator")
	void ShouldCollapseWhenConditionIsFalse(bool Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Simple Item Condition Icon Indicator", meta=(ScriptName="ShouldCollapseWhenConditionIsFalseValue"))
	bool bShouldCollapseWhenConditionIsFalse;

};

