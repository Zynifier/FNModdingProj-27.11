// Copyright Epic Games, Inc. All Rights Reserved.

#include "Effects/FortSplineGroundPath.h"
#include "Net/UnrealNetwork.h"

void AFortSplineGroundPath::DebugDisplayPathPoints() const
{
}

void AFortSplineGroundPath::OnRep_MostRecentlyAddedLocation()
{
}

void AFortSplineGroundPath::StartNextSectionTimedOut()
{
}

void AFortSplineGroundPath::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortSplineGroundPath, MostRecentlyAddedLocation);
	DOREPLIFETIME(AFortSplineGroundPath, FortReppedPointList);
}
