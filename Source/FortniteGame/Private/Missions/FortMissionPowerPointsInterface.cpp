// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMissionPowerPointsInterface.h"

float IFortMissionPowerPointsInterface::GetAvailabilityWeight(float DifficultyLevel) const
{
	return float();
}

float IFortMissionPowerPointsInterface::GetInitialRangeLerpValue(float PointsAvailable) const
{
	return float();
}

float IFortMissionPowerPointsInterface::GetMaxRangeLerpValue(float PointsAvailable, float PreviousLerpValue) const
{
	return float();
}

float IFortMissionPowerPointsInterface::GetPowerPointsCost(float LerpValue) const
{
	return float();
}
