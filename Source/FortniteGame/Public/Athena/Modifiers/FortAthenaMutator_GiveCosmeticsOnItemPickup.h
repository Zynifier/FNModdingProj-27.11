// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GiveCosmeticsOnItemPickup.generated.h"

class UAthenaPickaxeItemDefinition;
class UFortGadgetItemDefinition;
class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FCosmeticsToApplyOnItemPickupData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CosmeticsToApplyOnItemPickupData")
	FScalableFloat bEnabled;

	UPROPERTY(EditDefaultsOnly, Category="CosmeticsToApplyOnItemPickupData")
	TObjectPtr<UFortGadgetItemDefinition> GadgetItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="CosmeticsToApplyOnItemPickupData")
	TObjectPtr<UAthenaPickaxeItemDefinition> PickaxeItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="CosmeticsToApplyOnItemPickupData")
	FGameplayTag GameplayCueTag;

};

UCLASS(BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GiveCosmeticsOnItemPickup : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_GiveCosmeticsOnItemPickup")
	TMap<TObjectPtr<UFortItemDefinition>, FCosmeticsToApplyOnItemPickupData> PickupToSkinDataMap;

};

