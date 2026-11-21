// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingFillFloor.h"
#include "Net/UnrealNetwork.h"

bool ABuildingFillFloor::GetFloorPositionFromStep(int32 Step, float& MoveTime, float& Height, float& PostMoveDelay) const
{
	return false;
}

void ABuildingFillFloor::InterpToStopCallback(const FHitResult& ImpactResult, float Time)
{
}

void ABuildingFillFloor::OnLavaOverlap(AFortPlayerPawn* Pawn)
{
}

void ABuildingFillFloor::OnRep_FloorZ()
{
}

void ABuildingFillFloor::OnRep_IsMoving()
{
}

void ABuildingFillFloor::OnRep_StepIndex()
{
}

void ABuildingFillFloor::StartMovement_Implementation()
{
}

void ABuildingFillFloor::StopMovement()
{
}

void ABuildingFillFloor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingFillFloor, StepIndex);
	DOREPLIFETIME(ABuildingFillFloor, FloorZ);
	DOREPLIFETIME(ABuildingFillFloor, FloorMovementSpeed);
	DOREPLIFETIME(ABuildingFillFloor, bIsMoving);
}
