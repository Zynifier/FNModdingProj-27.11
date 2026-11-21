// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeCostComponent.h"
#include "Net/UnrealNetwork.h"

void UFortCreativeCostComponent::ClearCosts()
{
}

const TArray<int32>& UFortCreativeCostComponent::GetItemCosts() const
{
	static TArray<int32> Dummy;
	return Dummy;
}

bool UFortCreativeCostComponent::PassesCostCheck(const AFortPawn* Pawn) const
{
	return false;
}

void UFortCreativeCostComponent::SetItemResourceCost(const EFortResourceType::Type ResourceType, const int32 Cost)
{
}

bool UFortCreativeCostComponent::TakeWorldResourcesFromPlayer(AFortPawn* Pawn) const
{
	return false;
}

void UFortCreativeCostComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCreativeCostComponent, ItemCosts);
}
