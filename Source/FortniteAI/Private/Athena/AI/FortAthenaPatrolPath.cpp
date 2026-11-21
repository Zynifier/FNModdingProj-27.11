// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaPatrolPath.h"

bool AFortAthenaPatrolPath::CanBeUsed() const
{
	return false;
}

AFortAthenaPatrolPoint* AFortAthenaPatrolPath::GetPatrolPoint(const int32 Index) const
{
	return nullptr;
}

void AFortAthenaPatrolPath::GetPatrolPoints(TArray<AFortAthenaPatrolPoint*>& OutPatrolPoints) const
{
}

void AFortAthenaPatrolPath::OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

void AFortAthenaPatrolPath::PatrolPathStarted(AAIController* AIInstigator) const
{
}

void AFortAthenaPatrolPath::PatrolPathStopped(AAIController* AIInstigator) const
{
}

void AFortAthenaPatrolPath::PatrolPointFailedToReach(AFortAthenaPatrolPoint* PathPoint, AAIController* AIInstigator) const
{
}

void AFortAthenaPatrolPath::PatrolPointReached(AFortAthenaPatrolPoint* PathPoint, AAIController* AIInstigator) const
{
}

void AFortAthenaPatrolPath::SetPatrolPathEnabled(const bool bIsEnabled)
{
}

void AFortAthenaPatrolPath::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
}
