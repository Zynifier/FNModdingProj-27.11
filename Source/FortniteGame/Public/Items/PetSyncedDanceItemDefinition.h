// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaDanceItemDefinition.h"
#include "PetSyncedDanceItemDefinition.generated.h"

class UAnimMontage;
class UAthenaPetItemDefinition;

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UPetSyncedDanceItemDefinition : public UAthenaDanceItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Emote")
	TSoftObjectPtr<UAnimMontage> GetPetAnimation(const UAthenaPetItemDefinition* PetItemDef) const;

protected:
	UPROPERTY(EditAnywhere, Category="Emote")
	TSoftObjectPtr<UAnimMontage> DefaultPetAnimation;

};

