// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Projectiles/FortTrapGrenadeProjectile.h"
#include "Net/UnrealNetwork.h"

UFortContextTrapItemDefinition* AFortTrapGrenadeProjectile::GetTrapDefinition()
{
	return nullptr;
}

void AFortTrapGrenadeProjectile::InitializeProjectileDecoHelperAndTool()
{
}

void AFortTrapGrenadeProjectile::OnRep_DecoTool()
{
}

void AFortTrapGrenadeProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortTrapGrenadeProjectile, ProjectileDecoTool);
}
