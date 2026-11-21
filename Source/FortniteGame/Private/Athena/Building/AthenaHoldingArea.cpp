// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Building/AthenaHoldingArea.h"
#include "Net/UnrealNetwork.h"

void AAthenaHoldingArea::OnRep_bHoldingAreaActive()
{
}

void AAthenaHoldingArea::OnRep_IgnoredPlayerPawns()
{
}

void AAthenaHoldingArea::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAthenaHoldingArea, bHoldingAreaActive);
	DOREPLIFETIME(AAthenaHoldingArea, IgnoredPlayerPawns);
}
