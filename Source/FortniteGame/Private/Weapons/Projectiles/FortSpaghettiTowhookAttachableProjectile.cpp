// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Projectiles/FortSpaghettiTowhookAttachableProjectile.h"
#include "Net/UnrealNetwork.h"

void AFortSpaghettiTowhookAttachableProjectile::DestroyProjectile()
{
}

FVector AFortSpaghettiTowhookAttachableProjectile::GetRopeAttachLocation() const
{
	return FVector();
}

void AFortSpaghettiTowhookAttachableProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortSpaghettiTowhookAttachableProjectile, OwningVehicle);
}
