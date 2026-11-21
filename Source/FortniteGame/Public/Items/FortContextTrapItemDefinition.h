// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortTrapItemDefinition.h"
#include "FortContextTrapItemDefinition.generated.h"

class UFortTrapItemDefinition;

UCLASS(MinimalAPI, HideCategories=("Damage", "Effects"))
class UFortContextTrapItemDefinition : public UFortTrapItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap", meta=(IncludeAssetBundles))
	TObjectPtr<UFortTrapItemDefinition> FloorTrap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap", meta=(IncludeAssetBundles))
	TObjectPtr<UFortTrapItemDefinition> CeilingTrap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap", meta=(IncludeAssetBundles))
	TObjectPtr<UFortTrapItemDefinition> WallTrap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap", meta=(IncludeAssetBundles))
	TObjectPtr<UFortTrapItemDefinition> StairTrap;

};

