// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "CraftingCheatManager.generated.h"

UCLASS()
class UCraftingCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void StartSelfCrafting(FName FormulaName);

	UFUNCTION(Exec)
	void ToggleFreeCrafting();

};

