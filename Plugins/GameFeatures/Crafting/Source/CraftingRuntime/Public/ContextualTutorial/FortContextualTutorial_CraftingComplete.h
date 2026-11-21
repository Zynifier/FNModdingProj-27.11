// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "Components/CraftingObjectComponent.h"
#include "FortContextualTutorial_CraftingComplete.generated.h"

UCLASS()
class UFortContextualTutorial_CraftingComplete : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnCraftingSuccess(const FCraftingObjectSuccessEvent& Event);

};

