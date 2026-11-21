// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaLivingWorldDebugDensityMiniMapIndicator.h"
#include "Net/UnrealNetwork.h"

void UFortAthenaLivingWorldDebugDensityMiniMapIndicator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAthenaLivingWorldDebugDensityMiniMapIndicator, ActorDebugInfos);
	DOREPLIFETIME(UFortAthenaLivingWorldDebugDensityMiniMapIndicator, DensityGridValues);
	DOREPLIFETIME(UFortAthenaLivingWorldDebugDensityMiniMapIndicator, GridOrigin);
	DOREPLIFETIME(UFortAthenaLivingWorldDebugDensityMiniMapIndicator, MaxGridSize);
	DOREPLIFETIME(UFortAthenaLivingWorldDebugDensityMiniMapIndicator, CellSize);
	DOREPLIFETIME(UFortAthenaLivingWorldDebugDensityMiniMapIndicator, MaxDensity);
	DOREPLIFETIME(UFortAthenaLivingWorldDebugDensityMiniMapIndicator, DisplayName);
}
