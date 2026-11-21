// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/Components/FortBuildingWallDoorComponent.h"
#include "Net/UnrealNetwork.h"

void UFortBuildingWallDoorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortBuildingWallDoorComponent, LastDoorOpenerState);
	DOREPLIFETIME(UFortBuildingWallDoorComponent, DoorDesiredRotation);
	DOREPLIFETIME(UFortBuildingWallDoorComponent, DoorDesiredLocation);
	DOREPLIFETIME(UFortBuildingWallDoorComponent, DoorDesiredRotOffset);
}
