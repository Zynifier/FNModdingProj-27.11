// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortGameStateDeployableBase.h"
#include "Net/UnrealNetwork.h"

EDeployableBaseUseType AFortGameStateDeployableBase::GetDeployableBaseUseType() const
{
	return EDeployableBaseUseType();
}

float AFortGameStateDeployableBase::GetStormShieldBreatherRadiusOverride() const
{
	return float();
}

float AFortGameStateDeployableBase::GetStormShieldEndingRadiusOverride() const
{
	return float();
}

float AFortGameStateDeployableBase::GetStormShieldStartingRadiusOverride() const
{
	return float();
}

void AFortGameStateDeployableBase::OnRep_DeployableBaseManager()
{
}

bool AFortGameStateDeployableBase::ShouldRespawnAtLastPawnLocation() const
{
	return false;
}

bool AFortGameStateDeployableBase::ShouldUseStormShield() const
{
	return false;
}

void AFortGameStateDeployableBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameStateDeployableBase, DeployableBaseManager);
}
