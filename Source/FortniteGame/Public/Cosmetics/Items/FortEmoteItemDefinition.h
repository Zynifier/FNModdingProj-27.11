// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/FortMontageItemDefinitionBase.h"
#include "FortEmoteItemDefinition.generated.h"

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class FORTNITEGAME_API UFortEmoteItemDefinition : public UFortMontageItemDefinitionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="EmoteItemDefinition")
	FText GetCommandName() const;

private:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Emote")
	FText CommandName;

};

