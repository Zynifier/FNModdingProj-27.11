// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemPicker/FortItemPicker.h"
#include "FortTrapDefenderItemPicker.generated.h"

class ABuildingTrapDefender;
class UFortItem;
class UFortItemDetailsHostPanel;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortTrapDefenderItemPicker : public UFortItemPickerBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Defender Trap", meta=(DisplayName="Handle Selection Committed"))
	void HandleSelectionCommittedBP(UFortItem* CommittedItem);

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Defender Trap", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemDetailsHostPanel> DetailsPanel;

	UPROPERTY(BlueprintReadWrite, Category="Item Management|Defender Trap")
	TWeakObjectPtr<ABuildingTrapDefender> DefenderTrap;

};

