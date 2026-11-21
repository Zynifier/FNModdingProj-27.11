// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameStateComponent_VictoryCrowns.h"
#include "Net/UnrealNetwork.h"

void UFortGameStateComponent_VictoryCrowns::ClientKillFeedMessage_Implementation(const AFortPlayerStateAthena* FortPSA, bool bAdded)
{
}

void UFortGameStateComponent_VictoryCrowns::HandleCrownStatusChanged(AFortPlayerControllerAthena* FortPlayerControllerAthena, const UFortItem* CrownItem)
{
}

bool UFortGameStateComponent_VictoryCrowns::IsCrownBearer(const AFortPlayerStateAthena* FortPSA) const
{
	return false;
}

void UFortGameStateComponent_VictoryCrowns::OnRep_CrownBearerPlayerStates()
{
}

void UFortGameStateComponent_VictoryCrowns::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_VictoryCrowns, CrownBearerPlayerStates);
}
