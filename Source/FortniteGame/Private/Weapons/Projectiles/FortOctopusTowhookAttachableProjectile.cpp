// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Projectiles/FortOctopusTowhookAttachableProjectile.h"
#include "Net/UnrealNetwork.h"

void AFortOctopusTowhookAttachableProjectile::DestroyProjectile()
{
}

FVector AFortOctopusTowhookAttachableProjectile::GetRopeAttachLocation() const
{
	return FVector();
}

void AFortOctopusTowhookAttachableProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortOctopusTowhookAttachableProjectile, OwningVehicle);
}
