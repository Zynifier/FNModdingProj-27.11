// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_MarkerUtilities.h"
#include "Net/UnrealNetwork.h"

const FFortAthenaCompassIcon& AFortAthenaMutator_MarkerUtilities::GetIndicatedActorCompassIcon(AActor* Actor) const
{
	static FFortAthenaCompassIcon Dummy;
	return Dummy;
}

void AFortAthenaMutator_MarkerUtilities::OverrideIndicatedActorCompassIcon(AActor* Actor, const FFortAthenaCompassIcon CompassIcon)
{
}

void AFortAthenaMutator_MarkerUtilities::RestoreIndicatedActorCompassIcon(AActor* Actor)
{
}

void AFortAthenaMutator_MarkerUtilities::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_MarkerUtilities, ReplicatedTeamPlacements);
}
