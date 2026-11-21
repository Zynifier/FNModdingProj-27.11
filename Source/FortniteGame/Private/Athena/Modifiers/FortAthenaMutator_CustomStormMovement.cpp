// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_CustomStormMovement.h"
#include "Net/UnrealNetwork.h"

const FSafeZoneRoute& AFortAthenaMutator_CustomStormMovement::GetSafeZoneRoute(const FString& ContextString) const
{
	static FSafeZoneRoute Dummy;
	return Dummy;
}

void AFortAthenaMutator_CustomStormMovement::OnRep_SafeZoneRouteIndex()
{
}

void AFortAthenaMutator_CustomStormMovement::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_CustomStormMovement, SafeZoneRoutes);
	DOREPLIFETIME(AFortAthenaMutator_CustomStormMovement, SafeZoneRouteIndex);
}

void UFortCheatManager_CustomStormMovement::CustomStormMovementDebug(float TextScale)
{
}
