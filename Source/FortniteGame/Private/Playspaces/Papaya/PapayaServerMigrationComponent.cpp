// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/Papaya/PapayaServerMigrationComponent.h"
#include "Net/UnrealNetwork.h"

void UPapayaServerMigrationComponent::OnGameStateReady(AGameStateBase* GameState)
{
}

void UPapayaServerMigrationComponent::OnRep_LastRequestedTimeForMigrationTimerPushback()
{
}

void UPapayaServerMigrationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPapayaServerMigrationComponent, LastRequestedTimeForMigrationTimerPushback);
}
