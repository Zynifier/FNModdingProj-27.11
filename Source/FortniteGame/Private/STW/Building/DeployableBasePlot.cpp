// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Building/DeployableBasePlot.h"
#include "Net/UnrealNetwork.h"

int32 ADeployableBasePlot::GetNumOfItemsInPlot() const
{
	return int32();
}

const FUniqueNetIdRepl& ADeployableBasePlot::GetOccupantNetID() const
{
	static FUniqueNetIdRepl Dummy;
	return Dummy;
}

AFortPlayerStart* ADeployableBasePlot::GetPlayerStart()
{
	return nullptr;
}

void ADeployableBasePlot::HandleBuildingStateTransition_Implementation(EDeployableBaseBuildingState InPreviousState, EDeployableBaseBuildingState InCurrentState)
{
}

bool ADeployableBasePlot::IsBuildingActorWithinBuildableSpace(const ABuildingActor* ActorToCheck, const FVector& GridLocation) const
{
	return false;
}

bool ADeployableBasePlot::IsOccupant(const FUniqueNetIdRepl& UserId) const
{
	return false;
}

bool ADeployableBasePlot::IsOccupied() const
{
	return false;
}

void ADeployableBasePlot::OnBuildingStateTransition_Implementation(EDeployableBaseBuildingState InPreviousState, EDeployableBaseBuildingState InCurrentState)
{
}

void ADeployableBasePlot::OnCurrentBuildingStateSet_Implementation(EDeployableBaseBuildingState InCurrentBuildingState)
{
}

void ADeployableBasePlot::OnRep_BuildableSpaceExpansionVector()
{
}

void ADeployableBasePlot::OnRep_CurrentBuildingState()
{
}

void ADeployableBasePlot::OnRep_OccupantNetID()
{
}

void ADeployableBasePlot::SetContextComponent(UPrimitiveComponent* ContextComponent)
{
}

void ADeployableBasePlot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ADeployableBasePlot, OccupantNetID);
	DOREPLIFETIME(ADeployableBasePlot, CurrentBuildingState);
	DOREPLIFETIME(ADeployableBasePlot, PlotInventory);
	DOREPLIFETIME(ADeployableBasePlot, BuildableSpaceExpansionVector);
	DOREPLIFETIME(ADeployableBasePlot, BuildableAreasStructuralSupportBoxesArray);
}
