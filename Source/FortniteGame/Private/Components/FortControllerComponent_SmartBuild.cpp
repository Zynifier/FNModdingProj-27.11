// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_SmartBuild.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_SmartBuild::ClientEquipBuildingItems_Implementation()
{
}

void UFortControllerComponent_SmartBuild::OnRep_UseSmartBuild()
{
}

void UFortControllerComponent_SmartBuild::ServerSetUseSmartBuild_Implementation(const bool bInUseSmartBuild)
{
}

void UFortControllerComponent_SmartBuild::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_SmartBuild, bUseSmartBuild);
}
