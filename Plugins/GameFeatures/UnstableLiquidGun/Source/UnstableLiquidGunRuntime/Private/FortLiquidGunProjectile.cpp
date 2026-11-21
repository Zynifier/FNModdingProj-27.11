// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortLiquidGunProjectile.h"
#include "Net/UnrealNetwork.h"

ELiquidRibbonDetachmentReason AFortLiquidGunProjectile::GetDetachmentReason() const
{
	return ELiquidRibbonDetachmentReason();
}

void AFortLiquidGunProjectile::SetDetachmentReason(ELiquidRibbonDetachmentReason InDetachmentReason)
{
}

void AFortLiquidGunProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortLiquidGunProjectile, RandomDetachmentAngleFirstHalf);
	DOREPLIFETIME(AFortLiquidGunProjectile, RandomDetachmentAngleSecondHalf);
	DOREPLIFETIME(AFortLiquidGunProjectile, DetachmentReason);
}
