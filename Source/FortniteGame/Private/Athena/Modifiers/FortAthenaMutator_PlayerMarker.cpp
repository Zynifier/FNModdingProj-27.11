// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_PlayerMarker.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_PlayerMarker::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_PlayerMarker, PlayerMarkerEffectDataArray);
}
