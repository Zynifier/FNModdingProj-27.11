// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Inventory/AthenaQuickBarSlotExtensionWidgetBase.h"
#include "AthenaQuickBarSlotCraftingIndicator.generated.h"

class AFortWeapon;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaQuickBarSlotCraftingIndicator : public UAthenaQuickBarSlotExtensionWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCanCraftNowChanged(const bool bCanCraftNow);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIngredientChanged(const bool bCanCraftNow);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsCraftableItemChanged(const bool bIsCraftableItem);

private:
	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UPROPERTY(EditDefaultsOnly, Category="AthenaQuickBarSlotCraftingIndicator")
	bool bCheckForIngredientChangesWhenCraftable;

};

