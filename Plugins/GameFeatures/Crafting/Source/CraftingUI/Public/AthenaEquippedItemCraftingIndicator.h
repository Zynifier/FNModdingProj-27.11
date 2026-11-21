// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaEquippedItemCraftingIndicator.generated.h"

class AFortWeapon;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaEquippedItemCraftingIndicator : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCanCraftNowChanged(const bool bCanCraftNow);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsCraftableItemChanged(const bool bIsCraftableItem);

private:
	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

};

