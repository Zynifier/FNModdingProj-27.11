// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/SynchronizedTeleportPlayerComponent.h"
#include "Net/UnrealNetwork.h"

void USynchronizedTeleportPlayerComponent::HandleTeleportScreenStatusChanged(AFortPlayerControllerAthena* PlayerController, bool bEnableLoadScreen, FText HUDReasonText)
{
}

void USynchronizedTeleportPlayerComponent::OnRep_FadeOutData()
{
}

void USynchronizedTeleportPlayerComponent::OnRep_IsServerWaitingForClientToCancelRespawn()
{
}

void USynchronizedTeleportPlayerComponent::ServerRestartRespawn_Implementation()
{
}

void USynchronizedTeleportPlayerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USynchronizedTeleportPlayerComponent, FadeOutData);
	DOREPLIFETIME(USynchronizedTeleportPlayerComponent, bIsServerWaitingForClientToCancelRespawn);
}
