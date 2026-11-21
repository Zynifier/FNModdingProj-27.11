// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BattleLab/BattleLabDeviceGameplayActor.h"
#include "Net/UnrealNetwork.h"

void ABattleLabDeviceGameplayActor::OnRep_BattleLabDeviceItemData()
{
}

void ABattleLabDeviceGameplayActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABattleLabDeviceGameplayActor, BattleLabDeviceItemData);
}
