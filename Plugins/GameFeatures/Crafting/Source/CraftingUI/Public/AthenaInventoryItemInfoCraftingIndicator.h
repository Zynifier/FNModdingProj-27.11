// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaInventoryItemInfoCraftingIndicator.generated.h"

class UFortItem;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaInventoryItemInfoCraftingIndicator : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCanCraftNowChanged(const bool bCanCraftNow);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsCraftableItemChanged(const bool bIsCraftableItem);

private:
	UFUNCTION()
	void HandleInventoryItemSelected(UFortItem* SelectedItem);

};

