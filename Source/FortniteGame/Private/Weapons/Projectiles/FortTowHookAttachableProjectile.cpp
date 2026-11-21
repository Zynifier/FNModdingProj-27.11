// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Projectiles/FortTowHookAttachableProjectile.h"
#include "Net/UnrealNetwork.h"

void AFortTowHookAttachableProjectile::DestroyProjectile()
{
}

FVector AFortTowHookAttachableProjectile::GetRopeAttachLocation() const
{
	return FVector();
}

void AFortTowHookAttachableProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortTowHookAttachableProjectile, OwningTowHook);
}
