// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaCharacterPartItemDefinition.generated.h"

class UCustomCharacterPart;

UCLASS(Abstract, MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaCharacterPartItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Cosmetics")
	TArray<UCustomCharacterPart*> GetCharacterParts() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Cosmetics")
	TArray<TObjectPtr<UCustomCharacterPart>> CharacterParts;

};

