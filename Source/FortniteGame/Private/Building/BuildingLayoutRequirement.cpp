// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingLayoutRequirement.h"
#include "Net/UnrealNetwork.h"

void ABuildingLayoutRequirement::ActivateRequirement(bool bMakeVisible)
{
}

void ABuildingLayoutRequirement::DeactivateRequirement()
{
}

void ABuildingLayoutRequirement::OnRep_RequirementStatus()
{
}

void ABuildingLayoutRequirement::OnRequirementSatisfyingActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void ABuildingLayoutRequirement::SetRequiredResourceType(EFortResourceType::Type DesiredResourceType)
{
}

void ABuildingLayoutRequirement::SetRequirementVisible(bool bVisible)
{
}

bool ABuildingLayoutRequirement::SupportsEditingOfOccupant() const
{
	return false;
}

void ABuildingLayoutRequirement::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingLayoutRequirement, bRequirementSatisfied);
	DOREPLIFETIME(ABuildingLayoutRequirement, RequirementStatus);
}
