// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemPicker/FortItemPicker.h"
#include "FortHeroLoadoutGadgetPicker.generated.h"

class UFortCampaignHeroLoadoutItem;
class UFortItem;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortHeroLoadoutGadgetPicker : public UFortItemPickerBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetTargetLoadoutSlot(const UFortCampaignHeroLoadoutItem* LoadoutItem, const int32 SlotIndex);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleDifferentTargetLoadoutSlotSetBP();

	UPROPERTY(BlueprintReadOnly, Category="FortHeroLoadoutGadgetPicker")
	TWeakObjectPtr<UFortCampaignHeroLoadoutItem> TargetLoadoutItem;

	UPROPERTY(BlueprintReadOnly, Category="FortHeroLoadoutGadgetPicker")
	int32 TargetSlotIndex;

	UPROPERTY()
	TArray<TObjectPtr<UFortItem>> TemporaryGadgetItemInstances;

};

