// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingItemCollectorActor.h"
#include "Net/UnrealNetwork.h"

void ABuildingItemCollectorActor::ClearLootSpawnWorldTransformOverride()
{
}

UFortWorldItemDefinition* ABuildingItemCollectorActor::GetCurrentActiveItem() const
{
	return nullptr;
}

int32 ABuildingItemCollectorActor::GetDepositAmount(AFortPlayerController* InFortPC, UFortWorldItemDefinition* InInputItem)
{
	return int32();
}

int32 ABuildingItemCollectorActor::GetDepositGoal(AFortPlayerController* InFortPC, UFortWorldItemDefinition* InInputItem)
{
	return int32();
}

int32 ABuildingItemCollectorActor::GetNumberOfCaptures(AFortPlayerController* InFortPC, UFortWorldItemDefinition* InInputItem)
{
	return int32();
}

bool ABuildingItemCollectorActor::GetOverrideRarity_Implementation(EFortRarity& Rarity) const
{
	return false;
}

int32 ABuildingItemCollectorActor::GetTeamReachedGoalCount(uint8 InTeam)
{
	return int32();
}

bool ABuildingItemCollectorActor::HasEnoughDepositItems(AFortPlayerController* FortPC, UFortWorldItemDefinition* InputItem, bool bAllOrNothing, const EInteractionBeingAttempted InInteractionBeingAttempted)
{
	return false;
}

void ABuildingItemCollectorActor::OnRep_ActiveInputItem()
{
}

void ABuildingItemCollectorActor::OnRep_ControllingPlayer()
{
}

void ABuildingItemCollectorActor::OnRep_ItemCollectorState()
{
}

void ABuildingItemCollectorActor::OnRep_TrackedInteractionData()
{
}

void ABuildingItemCollectorActor::RefreshCollectorsActiveItem()
{
}

void ABuildingItemCollectorActor::ServerSpawnItem_Implementation(const FFortItemEntry OutputItem)
{
}
bool ABuildingItemCollectorActor::ServerSpawnItem_Validate(const FFortItemEntry OutputItem)
{
	return true;
}

void ABuildingItemCollectorActor::SetItemCollectorState(EFortItemCollectorState InItemCollectorState)
{
}

void ABuildingItemCollectorActor::SetLootSpawnWorldTransformOverride(const FTransform& Transform)
{
}

void ABuildingItemCollectorActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingItemCollectorActor, ItemCollectorState);
	DOREPLIFETIME(ABuildingItemCollectorActor, TrackingType);
	DOREPLIFETIME(ABuildingItemCollectorActor, ControllingPlayer);
	DOREPLIFETIME(ABuildingItemCollectorActor, bUseInstanceLootValueOverrides);
	DOREPLIFETIME(ABuildingItemCollectorActor, OverrideOutputItems);
	DOREPLIFETIME(ABuildingItemCollectorActor, ItemCollections);
	DOREPLIFETIME(ABuildingItemCollectorActor, ActiveInputItem);
	DOREPLIFETIME(ABuildingItemCollectorActor, StartingGoalLevel);
	DOREPLIFETIME(ABuildingItemCollectorActor, TrackedInteractionData);
}
