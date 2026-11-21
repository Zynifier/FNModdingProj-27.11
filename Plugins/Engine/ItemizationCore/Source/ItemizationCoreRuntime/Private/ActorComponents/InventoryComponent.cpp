// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActorComponents/InventoryComponent.h"
#include "Net/UnrealNetwork.h"

void UInventoryComponent::AddItem(UItemDefinitionBase* ItemDefinition, int32 Amount)
{
}

void UInventoryComponent::AddOrResetInventory(UInventoryDefinition* NewInventoryDefinition)
{
}

AInventoryCollection* UInventoryComponent::GetInventoryCollection() const
{
	return nullptr;
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UInventoryComponent, InventoryCollection);
}
