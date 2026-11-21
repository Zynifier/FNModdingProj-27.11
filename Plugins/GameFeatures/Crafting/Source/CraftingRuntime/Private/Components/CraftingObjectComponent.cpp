// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/CraftingObjectComponent.h"
#include "Net/UnrealNetwork.h"

UCraftingObjectComponent::UCraftingObjectComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UCraftingObjectComponent::HandlePickupCraftingItemPickedUp(AFortPickup* Pickup, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* WorldItemDefinition, FVector PickupLocation)
{
}

void UCraftingObjectComponent::OnRep_CraftingObjectRepStateData(const TArray<FCraftingObjectRepStateData>& OldValue)
{
}

void UCraftingObjectComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCraftingObjectComponent, CraftingObjectRepStateData);
	DOREPLIFETIME(UCraftingObjectComponent, LastCraftedItemFormulaRow);
	DOREPLIFETIME(UCraftingObjectComponent, FreeCraftingEnabled);
}
