// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Items/FortPersistableItemDefinition.h"
#include "FortApparelItemDefinitionStubs.generated.h"

UCLASS(MinimalAPI, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UFortApparelItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortApparelLayoutItemDefinition : public UFortPersistableItemDefinition
{
	GENERATED_BODY()

};

