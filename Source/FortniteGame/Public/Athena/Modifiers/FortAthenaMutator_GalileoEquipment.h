// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_OverrideInventoryOnce.h"
#include "FortAthenaMutator_GalileoEquipment.generated.h"

class AFortPlayerState;
class UGameplayEffect;

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GalileoEquipment : public AFortAthenaMutator_OverrideInventoryOnce
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ApplyPlayerLoadout(AFortPlayerState* PlayerState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void MarkPlayerLoadoutChoice(AFortPlayerState* PlayerState, int32 ChosenLoadoutIndex);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	TSubclassOf<UGameplayEffect> StopDropsByApplyEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	bool bShouldStopDropsAfterApplying;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	int32 SlotToSwapToAfterGrant_DEPRECATE;

};

