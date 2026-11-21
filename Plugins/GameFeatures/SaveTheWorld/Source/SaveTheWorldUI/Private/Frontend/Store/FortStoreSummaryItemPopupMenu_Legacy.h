// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPopupMenu_Legacy.h"
#include "FortStoreSummaryItemPopupMenu_Legacy.generated.h"

class UFortStoreSummaryItemButton_Legacy;

UCLASS()
class UFortStoreSummaryItemPopupMenu_Legacy : public UFortPopupMenu_Legacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UFortStoreSummaryItemButton_Legacy* GetHostButton() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleItemChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UFUNCTION(BlueprintCallable)
	void MulchItem();

};

