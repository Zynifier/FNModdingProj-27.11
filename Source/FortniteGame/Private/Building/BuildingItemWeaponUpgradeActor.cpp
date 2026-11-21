// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingItemWeaponUpgradeActor.h"
#include "Net/UnrealNetwork.h"

void ABuildingItemWeaponUpgradeActor::FloorDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void ABuildingItemWeaponUpgradeActor::OnRep_AllowSecondInteraction()
{
}

void ABuildingItemWeaponUpgradeActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingItemWeaponUpgradeActor, bAllowSecondInteraction);
}
