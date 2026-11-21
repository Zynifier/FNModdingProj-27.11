// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortDeployableBasePickup.h"
#include "Net/UnrealNetwork.h"

void AFortDeployableBasePickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortDeployableBasePickup, AssociatedPlotOccupant);
}
