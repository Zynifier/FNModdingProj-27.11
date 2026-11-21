// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaExitCraft.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaExitCraft::CheatDepart()
{
}

void AFortAthenaExitCraft::OnDepartFinished()
{
}

void AFortAthenaExitCraft::OnOverlapEnd(AActor* TestActor)
{
}

void AFortAthenaExitCraft::OnOverlapStart(AActor* TestActor)
{
}

void AFortAthenaExitCraft::OnRep_BalloonActor()
{
}

void AFortAthenaExitCraft::OnRep_CurrentState()
{
}

void AFortAthenaExitCraft::OnRep_LocationLerpData()
{
}

void AFortAthenaExitCraft::OnRep_QualifyingPlayers()
{
}

void AFortAthenaExitCraft::OnRep_RotationLerpData()
{
}

void AFortAthenaExitCraft::OnRep_VehicleSkinIndex()
{
}

void AFortAthenaExitCraft::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaExitCraft, ExitCraftInfo);
	DOREPLIFETIME(AFortAthenaExitCraft, bCorrectionMade);
	DOREPLIFETIME(AFortAthenaExitCraft, CurrentState);
	DOREPLIFETIME(AFortAthenaExitCraft, OverlappingPawns);
	DOREPLIFETIME(AFortAthenaExitCraft, BalloonActor);
	DOREPLIFETIME(AFortAthenaExitCraft, VehicleSkinIndex);
	DOREPLIFETIME(AFortAthenaExitCraft, LocationLerpData);
	DOREPLIFETIME(AFortAthenaExitCraft, RotationLerpData);
}
