// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingContainer.h"
#include "Net/UnrealNetwork.h"

void ABuildingContainer::BounceContainer()
{
}

void ABuildingContainer::BP_FinishSpawning(const FName InSearchLootTierGroup, const FGameplayTagContainer& InGameplayTagContainer, const FTransform& InTransform)
{
}

bool ABuildingContainer::BP_IsAlreadySearched()
{
	return false;
}

void ABuildingContainer::BP_SetAlreadySearched(bool bInAlreadySearched)
{
}

bool ABuildingContainer::BP_SpawnLoot(AFortPlayerPawn* PlayerPawn)
{
	return false;
}

int32 ABuildingContainer::GetChosenRandomUpgrade() const
{
	return int32();
}

int32 ABuildingContainer::GetLootTier()
{
	return int32();
}

AFortPlayerPawn* ABuildingContainer::GetSearchingPawn()
{
	return nullptr;
}

void ABuildingContainer::HandlePickedUpForAnalyticsEvent(AFortPickup* SelfActor, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* WorldItemDefinition, FVector PickupLocation)
{
}

void ABuildingContainer::OnRep_bAlreadySearched()
{
}

void ABuildingContainer::OnRep_ChosenRandomUpgrade()
{
}

void ABuildingContainer::OnRep_LootTier()
{
}

void ABuildingContainer::RaiseTreasure()
{
}

void ABuildingContainer::SetSearchLootTierGroup(FName InSearchLootTierGroup, bool bReRollForLootExistence, const bool bIgnorePotentialRandomUpgrades)
{
}

void ABuildingContainer::StartAudiovisualIndicator(UAudioComponent* ForComponent, EFortSoundIndicatorTypes Type, float Interval)
{
}

void ABuildingContainer::StopAudiovisualIndicator()
{
}

void ABuildingContainer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingContainer, SearchedMesh);
	DOREPLIFETIME(ABuildingContainer, ReplicatedLootTier);
	DOREPLIFETIME(ABuildingContainer, ChosenRandomUpgrade);
	DOREPLIFETIME(ABuildingContainer, bAlreadySearched);
	DOREPLIFETIME(ABuildingContainer, SearchBounceData);
}
