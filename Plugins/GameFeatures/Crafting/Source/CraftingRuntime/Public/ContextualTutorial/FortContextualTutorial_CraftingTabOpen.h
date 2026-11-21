// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_CraftingTabOpen.generated.h"

UCLASS()
class UFortContextualTutorial_CraftingTabOpen : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleFormulaCraftableChanged(const FName& FormulaRowName, bool bIsCraftable);

	UFUNCTION()
	void HandleInventoryTabChanged(const FName InventoryTabNameId);

};

