// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPopupMenu_Legacy.h"
#include "FortItemManagementItemPopupMenu.generated.h"

class UFortItemManagementItemTileButton;

UCLASS()
class UFortItemManagementItemPopupMenu : public UFortPopupMenu_Legacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UFortItemManagementItemTileButton* GetHostButton() const;

	UFUNCTION(BlueprintCallable)
	void HandleCompareAction();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleItemChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UFUNCTION(BlueprintCallable)
	void MulchItem();

};

