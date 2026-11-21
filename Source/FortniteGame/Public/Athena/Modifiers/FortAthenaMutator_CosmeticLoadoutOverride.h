// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortAthenaMutator_CosmeticLoadoutOverride.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FCosmeticOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Cosmetics")
	EAthenaCustomizationCategory SlotName;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetics")
	TObjectPtr<UFortItemDefinition> CosmeticItem;

};

UCLASS(Abstract, HideDropdown, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class FORTNITEGAME_API AFortAthenaMutator_CosmeticLoadoutOverride : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Skins")
	TArray<FCosmeticOverrideData> CosmeticOverrides;

};

