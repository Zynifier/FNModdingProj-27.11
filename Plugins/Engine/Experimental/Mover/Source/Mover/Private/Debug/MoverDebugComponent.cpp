// Copyright Epic Games, Inc. All Rights Reserved.

#include "Debug/MoverDebugComponent.h"

TArray<FTrajectorySampleInfo> UMoverDebugComponent::GetFutureTrajectory(float FutureSeconds, float SamplesPerSecond) const
{
	return TArray<FTrajectorySampleInfo>();
}

TArray<FTrajectorySampleInfo> UMoverDebugComponent::GetPastTrajectory() const
{
	return TArray<FTrajectorySampleInfo>();
}

void UMoverDebugComponent::OnHistoryTrackingRollback(const FMoverTimeStep& NewTimeStep, const FMoverTimeStep& InvalidatedTimeStep)
{
}

void UMoverDebugComponent::OnMovementSimRollback(const FMoverTimeStep& NewTimeStep, const FMoverTimeStep& InvalidatedTimeStep)
{
}

void UMoverDebugComponent::OnMovementSimTick(const FMoverTimeStep& TimeStep)
{
}

void UMoverDebugComponent::SetHistoryTracking(float SecondsToTrack, float SamplesPerSecond)
{
}
