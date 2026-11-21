// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingTrapFloor_TargetDummy.h"
#include "Net/UnrealNetwork.h"

void ABuildingTrapFloor_TargetDummy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingTrapFloor_TargetDummy, PathPointLocations);
}
