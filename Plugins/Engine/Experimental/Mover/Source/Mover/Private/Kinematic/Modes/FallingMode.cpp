// Copyright Epic Games, Inc. All Rights Reserved.

#include "Kinematic/Modes/FallingMode.h"

void UFallingMode::OnGenerateMove(const FKinematicMoverTickStartData& StartState, const FMoverTimeStep& TimeStep, FProposedMove& OutProposedMove) const
{
}

void UFallingMode::OnSimulationTick(const FSimulationTickParams& Params, FKinematicMoverTickEndData& OutputState)
{
}

void UFallingMode::ProcessLanded(const FFloorCheckResult& FloorResult, FVector& Velocity, FRelativeBaseInfo& BaseInfo, FKinematicMoverTickEndData& TickEndData) const
{
}
