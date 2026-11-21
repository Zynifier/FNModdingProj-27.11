// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortBattleLabDeviceAccountItemDefinition.generated.h"

class UFortBattleLabDeviceItemDefinition;

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Frontend", "Tooltips", "Functionality", "OwnedTags", "FrontendPreview", "Series"))
class UFortBattleLabDeviceAccountItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Battle Lab")
	TObjectPtr<UFortBattleLabDeviceItemDefinition> BattleLabDeviceItemDefinition;

};

