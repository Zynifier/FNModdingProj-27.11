// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/Components/FortWorldMultiItemXPComponent.h"
#include "Net/UnrealNetwork.h"

void UFortWorldMultiItemXPComponent::FlushPendingPowerUp()
{
}

float UFortWorldMultiItemXPComponent::GetMultiItemXP() const
{
	return float();
}

bool UFortWorldMultiItemXPComponent::GetMultiItemXPPercentage(float& OutItemXPPercentage) const
{
	return false;
}

UFortWorldMultiItem* UFortWorldMultiItemXPComponent::GetOwningMultiItem() const
{
	return nullptr;
}

AFortPawn* UFortWorldMultiItemXPComponent::GetOwningPawn() const
{
	return nullptr;
}

int32 UFortWorldMultiItemXPComponent::GetSelectedItemIndex() const
{
	return int32();
}

AFortWeapon* UFortWorldMultiItemXPComponent::GetWeaponActor() const
{
	return nullptr;
}

void UFortWorldMultiItemXPComponent::HandleItemSwitched(const int32 CurrentItemIndex)
{
}

void UFortWorldMultiItemXPComponent::HandleItemXPChanged(const float XPChangeAmount, const float CurrentXP)
{
}

void UFortWorldMultiItemXPComponent::HandlePowerUpPending(const int32 CurrentItemIndex, const int32 PendingItemIndex)
{
}

bool UFortWorldMultiItemXPComponent::IsPowerUpPending() const
{
	return false;
}

void UFortWorldMultiItemXPComponent::OnRep_OwningItemReplicationProxy(const FMultiItemReplicationProxy& OldItemReplicationProxy)
{
}

void UFortWorldMultiItemXPComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortWorldMultiItemXPComponent, OwningItemReplicationProxy);
}
