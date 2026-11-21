// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingWall.h"
#include "Net/UnrealNetwork.h"

UFortBuildingWallDoorComponent* ABuildingWall::GetDoorComponent() const
{
	return nullptr;
}

bool ABuildingWall::HasBashableDoor() const
{
	return false;
}

bool ABuildingWall::HasSlidingDoor() const
{
	return false;
}

bool ABuildingWall::HasSwingingDoor() const
{
	return false;
}

bool ABuildingWall::IsDoorComponent(const UStaticMeshComponent* MeshComponent) const
{
	return false;
}

bool ABuildingWall::IsDoorOpen() const
{
	return false;
}

bool ABuildingWall::IsLocked() const
{
	return false;
}

void ABuildingWall::OnNearDoorTriggerTouched(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABuildingWall::OnNearDoorTriggerUnTouched(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ABuildingWall::OnRep_bDoorCollisionDisabled()
{
}

void ABuildingWall::OnRep_bDoorOpen()
{
}

void ABuildingWall::VerifyDoorCollisionMatchesServer()
{
}

void ABuildingWall::VerifyDoorOpenMatchesServer()
{
}

void ABuildingWall::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingWall, DoorMesh);
	DOREPLIFETIME(ABuildingWall, DoubleDoorMesh);
	DOREPLIFETIME(ABuildingWall, DoorOpenStyle);
	DOREPLIFETIME(ABuildingWall, bDoorOpen);
	DOREPLIFETIME(ABuildingWall, bDoorCollisionDisabled);
	DOREPLIFETIME(ABuildingWall, bFastOpenRequested);
}
