// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInteractInterface.h"
#include "Items/FortPickupInteractOverrideComponent.h"
#include "FortPickupInteractOverrideComponent_Crafting.generated.h"

class UFortItemDefinition;

UCLASS(HideCategories=("ComponentReplication", "Activation", "Cooking", "AssetUserData", "Collision", "ComponentReplication", "Activation", "Cooking", "AssetUserData", "Collision", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPickupInteractOverrideComponent_Crafting : public UFortPickupInteractOverrideComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPickupInteractOverrideComponent_Crafting")
	TObjectPtr<UFortItemDefinition> LastPickupItemDef;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPickupInteractOverrideComponent_Crafting")
	TObjectPtr<UFortItemDefinition> LastFocusedItemDef;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPickupInteractOverrideComponent_Crafting")
	FName LastTargetFormulaName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPickupInteractOverrideComponent_Crafting")
	float ContextualCraftingInteractDuration;

	UPROPERTY(BlueprintReadOnly, Category="FortPickupInteractOverrideComponent_Crafting")
	TEnumAsByte<TInteractionType> CachedInteractionType;

	UPROPERTY(BlueprintReadOnly, Category="FortPickupInteractOverrideComponent_Crafting")
	TEnumAsByte<EInteractionBeingAttempted> CachedInteractionBeingAttempted;

};

