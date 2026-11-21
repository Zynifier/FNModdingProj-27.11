// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortTeamPrivateInfo.h"
#include "Net/UnrealNetwork.h"

void AFortTeamPrivateInfo::OnRep_RepData()
{
}

void AFortTeamPrivateInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortTeamPrivateInfo, RepData);
	DOREPLIFETIME(AFortTeamPrivateInfo, LatentTeamRepData);
	DOREPLIFETIME(AFortTeamPrivateInfo, AverageDamageDealt);
}
