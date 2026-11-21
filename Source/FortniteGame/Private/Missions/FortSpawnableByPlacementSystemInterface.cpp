// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortSpawnableByPlacementSystemInterface.h"

AFortMission* IFortSpawnableByPlacementSystemInterface::GetMission() const
{
	return nullptr;
}

FGuid IFortSpawnableByPlacementSystemInterface::GetMissionGuid() const
{
	return FGuid();
}
