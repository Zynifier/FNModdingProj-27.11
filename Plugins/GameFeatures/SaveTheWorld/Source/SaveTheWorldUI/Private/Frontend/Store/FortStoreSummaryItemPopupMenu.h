// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPopupMenu.h"
#include "FortStoreSummaryItemPopupMenu.generated.h"

class UFortStoreSummaryItemButton;

UCLASS()
class UFortStoreSummaryItemPopupMenu : public UFortPopupMenu
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UFortStoreSummaryItemButton* GetHostButton() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleItemChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UFUNCTION(BlueprintCallable)
	void MulchItem();

};

