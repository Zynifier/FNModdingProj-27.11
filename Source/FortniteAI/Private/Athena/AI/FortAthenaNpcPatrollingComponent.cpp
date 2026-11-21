// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaNpcPatrollingComponent.h"

bool UFortAthenaNpcPatrollingComponent::FindAndSetDynamicPatrolPath(const FFortAthenaAIObjectTrackerQuery& FindQuery, const bool bOrientationAlreadyRandomized, const bool bExcludeCurrentlyUsedPatrolPath)
{
	return false;
}

AFortAthenaPatrolPoint* UFortAthenaNpcPatrollingComponent::GetCurrentPatrolPoint() const
{
	return nullptr;
}

const AFortAthenaPatrolPath* UFortAthenaNpcPatrollingComponent::GetPatrolPath() const
{
	return nullptr;
}

int32 UFortAthenaNpcPatrollingComponent::GetPatrolPointsCount() const
{
	return int32();
}

bool UFortAthenaNpcPatrollingComponent::IsCurrentPatrolPointAnEndPoint() const
{
	return false;
}

bool UFortAthenaNpcPatrollingComponent::IsPatrollingEnable() const
{
	return false;
}

void UFortAthenaNpcPatrollingComponent::OnPatrolPathStatusChanged(const bool bEnableState)
{
}

void UFortAthenaNpcPatrollingComponent::RemovePatrolPath()
{
}

void UFortAthenaNpcPatrollingComponent::SelectNextPatrolPoint()
{
}

void UFortAthenaNpcPatrollingComponent::SetPatrolPath(AFortAthenaPatrolPath* NewPatrolPath, const bool bOrientationAlreadyRandomized)
{
}

void UFortAthenaNpcPatrollingComponent::UpdateCurrentDestinationToNearestNextPoint()
{
}
