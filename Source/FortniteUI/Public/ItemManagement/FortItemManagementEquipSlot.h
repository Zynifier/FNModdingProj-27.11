// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserWidget.h"
#include "FortItemManagementEquipSlot.generated.h"

class UFortItem;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemManagementEquipSlot : public UFortUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Management|Equip Slot")
	bool WillAcceptItem(const UFortItem* InItem);

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Item Management|Equip Slot")
	int32 SlotIndex;

protected:
	UFUNCTION(BlueprintCallable, Category="Item Management|Equip Slot")
	void UpdateInventoryChangedDelegate();

};

