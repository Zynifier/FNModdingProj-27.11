// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPlayerStateComponent_VictoryCrowns.h"
#include "Net/UnrealNetwork.h"

bool UFortPlayerStateComponent_VictoryCrowns::GetWonRoyalRoyale() const
{
	return false;
}

void UFortPlayerStateComponent_VictoryCrowns::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayerStateComponent_VictoryCrowns, bHasWonRoyalRoyale);
}
