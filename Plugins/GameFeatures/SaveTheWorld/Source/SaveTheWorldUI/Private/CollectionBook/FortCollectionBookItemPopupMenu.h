// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPopupMenu_Legacy.h"
#include "FortCollectionBookItemPopupMenu.generated.h"

class UFortCollectionBookSlotButton;

UENUM(BlueprintType)
enum class EFortCollectionBookPopupButtonType : uint8
{
	Invalid = 0,
	SelectItem = 1,
	Preview = 2,
	Purchase = 3,
	Unslot = 4,
	Back = 5,
};

UCLASS()
class UFortCollectionBookItemPopupMenu : public UFortPopupMenu_Legacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	bool CanItemBePurchased();

	UFUNCTION(BlueprintCallable)
	bool CanItemBeUnslotted();

	UFUNCTION(BlueprintPure)
	UFortCollectionBookSlotButton* GetHostButton() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleItemChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleItemUpdated();

};

