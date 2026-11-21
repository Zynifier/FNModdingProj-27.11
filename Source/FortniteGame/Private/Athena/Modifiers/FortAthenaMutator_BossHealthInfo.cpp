// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_BossHealthInfo.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_BossHealthInfo::OnRep_DisplayMode()
{
}

void AFortAthenaMutator_BossHealthInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_BossHealthInfo, DisplayMode);
}
