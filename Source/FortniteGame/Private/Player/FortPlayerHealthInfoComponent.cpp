// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortPlayerHealthInfoComponent.h"
#include "Net/UnrealNetwork.h"

void UFortPlayerHealthInfoComponent::OnHealthChanged(AFortTeamHealthInfo* TeamHealthInfo)
{
}

void UFortPlayerHealthInfoComponent::OnRep_TeamHealthInfoArray()
{
}

void UFortPlayerHealthInfoComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayerHealthInfoComponent, TeamHealthInfoArray);
}
