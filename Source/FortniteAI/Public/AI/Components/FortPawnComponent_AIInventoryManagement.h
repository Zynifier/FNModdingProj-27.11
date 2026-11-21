// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_AIInventoryManagement.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPawnComponent_AIInventoryManagement : public UFortPawnComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AI Inventory Management")
	FGameplayTagContainer CanEquipItemTags;

};

