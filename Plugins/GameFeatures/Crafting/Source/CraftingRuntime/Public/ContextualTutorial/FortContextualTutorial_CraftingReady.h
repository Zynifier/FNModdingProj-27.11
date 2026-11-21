// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_CraftingReady.generated.h"

UCLASS()
class UFortContextualTutorial_CraftingReady : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleFormulaCraftableChanged(const FName& FormulaRowName, bool bIsCraftable);

};

