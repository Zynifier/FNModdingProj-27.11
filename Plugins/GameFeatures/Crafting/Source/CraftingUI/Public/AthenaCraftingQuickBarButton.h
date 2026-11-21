// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Inventory/AthenaQuickBarSlotButtonBase.h"
#include "AthenaCraftingQuickBarButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaCraftingQuickBarButton : public UAthenaQuickBarSlotButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCanCraftNowChanged(const bool bCanCraftNow);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsCraftableItemChanged(const bool bIsCraftableItem);

};

