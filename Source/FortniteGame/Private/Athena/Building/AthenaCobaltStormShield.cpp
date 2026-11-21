// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Building/AthenaCobaltStormShield.h"
#include "Net/UnrealNetwork.h"

void AAthenaCobaltStormShield::ClientStormShieldShrinkTimerComplete()
{
}

void AAthenaCobaltStormShield::OnRep_ClientStormShieldShrinkTimerValue()
{
}

void AAthenaCobaltStormShield::StormShieldShrinkTimerComplete()
{
}

void AAthenaCobaltStormShield::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAthenaCobaltStormShield, CachedMutator);
	DOREPLIFETIME(AAthenaCobaltStormShield, ClientStormShieldShrinkTimerValue);
}
