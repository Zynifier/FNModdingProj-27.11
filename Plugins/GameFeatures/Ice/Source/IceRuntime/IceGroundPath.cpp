// Copyright Epic Games, Inc. All Rights Reserved.

#include "IceGroundPath.h"
#include "Net/UnrealNetwork.h"

void AIceGroundPath::AddSplinePoint(FVector InWorldLoc)
{
}

bool AIceGroundPath::GetLastSplinePointLocation(FVector& LastPointLocation) const
{
	return false;
}

FVector AIceGroundPath::GetLocationOnLandscape(FVector Location)
{
	return FVector();
}

void AIceGroundPath::OnRep_SplinePoints()
{
}

void AIceGroundPath::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AIceGroundPath, SplinePoints);
}
