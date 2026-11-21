// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaSpectatorTrapsLoadoutBase.generated.h"

class UAthenaSpectatorInventorySlotBase;
class UFortWorldItem;

UCLASS(Abstract)
class UAthenaSpectatorTrapsLoadoutBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SelectSlot(int32 SlotIdx);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Export, Category="AthenaSpectatorTrapsLoadoutBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaSpectatorInventorySlotBase>> ItemSlots;

private:
	UFUNCTION()
	void ClearSlots();

	UFUNCTION()
	void OnWorldItemListChanged(const TArray<UFortWorldItem*>& ItemsAdded, const TArray<UFortWorldItem*>& ItemsRemoved);

};

