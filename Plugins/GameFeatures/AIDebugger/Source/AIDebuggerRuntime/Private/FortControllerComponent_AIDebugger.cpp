// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortControllerComponent_AIDebugger.h"
#include "Net/UnrealNetwork.h"

UAIDebuggerRendererComponent* UFortControllerComponent_AIDebugger::GetOrCreateRenderer() const
{
	return nullptr;
}

bool UFortControllerComponent_AIDebugger::IsVisualizationEnabled(const EAIDebuggerVisualization VisualizationType) const
{
	return false;
}

void UFortControllerComponent_AIDebugger::OnPlayerExitedIsland(FEventMessageTag Channel, const FPlayerExitSpatialActorContextWithPawn& PlayerExitSpatialActorContext)
{
}

void UFortControllerComponent_AIDebugger::OnRep_EnabledVisualizers()
{
}

void UFortControllerComponent_AIDebugger::SetVisualizationEnable_Implementation(const EAIDebuggerVisualization VisualizationType, const bool bEnable)
{
}

void UFortControllerComponent_AIDebugger::VisualizeNavMeshID_Implementation(const int32 NavMeshID)
{
}

void UFortControllerComponent_AIDebugger::VisualizeNextNavMesh_Implementation()
{
}

void UFortControllerComponent_AIDebugger::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_AIDebugger, EnabledVisualizers);
	DOREPLIFETIME(UFortControllerComponent_AIDebugger, NumNavMeshes);
}
