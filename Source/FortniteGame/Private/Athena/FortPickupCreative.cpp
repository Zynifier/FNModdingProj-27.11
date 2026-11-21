// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPickupCreative.h"
#include "Net/UnrealNetwork.h"

bool AFortPickupCreative::BlueprintClassAllowed_Implementation(const AFortPawn* Pawn) const
{
	return false;
}

bool AFortPickupCreative::BlueprintTeamAllowed_Implementation(const AFortPawn* Pawn) const
{
	return false;
}

float AFortPickupCreative::GetAccentColorParam() const
{
	return float();
}

void AFortPickupCreative::GivePickupToPawn(AFortPawn* Pawn, bool DestoryAfterPickup)
{
}

void AFortPickupCreative::OnPickupInstigatorDataChanged(int32 TrackedIndex)
{
}

void AFortPickupCreative::OnPickupInstigatorDataRemoved(int32 TrackedIndex)
{
}

void AFortPickupCreative::OnRep_PickupInstigatorIndex()
{
}

void AFortPickupCreative::SetItemResourceCost(const EFortResourceType::Type ResourceType, const int32 Cost)
{
}

void AFortPickupCreative::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPickupCreative, CostComponent);
	DOREPLIFETIME(AFortPickupCreative, CachedPickupInstigatorHandle);
}
