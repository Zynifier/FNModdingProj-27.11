// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspace/FortBuildingSettingsComponentBase.h"
#include "Net/UnrealNetwork.h"

void UFortBuildingSettingsComponentBase::OnRep_Settings()
{
}

void UFortBuildingSettingsComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortBuildingSettingsComponentBase, Building);
	DOREPLIFETIME(UFortBuildingSettingsComponentBase, BuildingOnWater);
	DOREPLIFETIME(UFortBuildingSettingsComponentBase, Editing);
	DOREPLIFETIME(UFortBuildingSettingsComponentBase, EditingHostile);
	DOREPLIFETIME(UFortBuildingSettingsComponentBase, TrapPlacement);
}
