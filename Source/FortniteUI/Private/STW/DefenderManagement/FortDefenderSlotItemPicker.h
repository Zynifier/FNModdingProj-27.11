// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInventoryFilterEnum.h"
#include "ItemPicker/FortItemPicker.h"
#include "FortDefenderSlotItemPicker.generated.h"

class UFortDefenderItem;
enum class EInventoryContentSortType : uint8;

UENUM(BlueprintType)
enum class EFortDefenderSlotType : uint8
{
	Invalid = 0,
	Defender = 1,
	Weapon = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortDefenderSlotItemPicker : public UFortItemPickerBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Defenders")
	void PopulateDefenderSlotItems(const UFortDefenderItem* DefenderItem);

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Defenders", meta=(DesignerRebuild="TRUE"))
	EFortDefenderSlotType DefenderSlotType;

protected:
	UFUNCTION(BlueprintCallable, Category="Defenders")
	void NextSortType();

	UFUNCTION(BlueprintImplementableEvent, Category="Defenders")
	void OnCurrentSortTypeChanged(EInventoryContentSortType SortType);

	UFUNCTION(BlueprintCallable, Category="Defenders")
	void SetSortType(EInventoryContentSortType SortType);

	UPROPERTY(BlueprintReadOnly, Category="Defenders")
	TArray<EInventoryContentSortType> SortTypesList;

	UPROPERTY(BlueprintReadOnly, Category="Defenders")
	EInventoryContentSortType CurrentSortType;

};

