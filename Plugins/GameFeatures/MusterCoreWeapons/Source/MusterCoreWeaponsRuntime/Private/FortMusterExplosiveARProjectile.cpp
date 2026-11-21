// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMusterExplosiveARProjectile.h"
#include "Net/UnrealNetwork.h"

void AFortMusterExplosiveARProjectile::OnRep_HitLocation()
{
}

void AFortMusterExplosiveARProjectile::SetHitLocation(const FVector& NewHitLocation)
{
}

void AFortMusterExplosiveARProjectile::SetHitPlayer(bool bWasHit)
{
}

void AFortMusterExplosiveARProjectile::SetHitRotation(const FRotator& NewHitRotation)
{
}

void AFortMusterExplosiveARProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMusterExplosiveARProjectile, HitLocation);
	DOREPLIFETIME(AFortMusterExplosiveARProjectile, HitRotation);
	DOREPLIFETIME(AFortMusterExplosiveARProjectile, bHitPlayer);
}
