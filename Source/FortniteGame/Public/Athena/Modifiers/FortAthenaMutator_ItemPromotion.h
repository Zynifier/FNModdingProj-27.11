// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortRarityEnum.h"
#include "FortAthenaMutator_ItemPromotion.generated.h"

class UDataTable;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ItemPromotion : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	TObjectPtr<UDataTable> UpgradeTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	EFortRarity HighestUpgradeTier;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FGameplayTagContainer ValidWeaponTags;

	UPROPERTY(EditDefaultsOnly, Category="Modification Behavior")
	FScalableFloat bPromoteAllItemsOnRespawn;

};

