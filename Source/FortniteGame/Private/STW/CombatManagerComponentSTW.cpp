// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/CombatManagerComponentSTW.h"
#include "Net/UnrealNetwork.h"

float UCombatManagerComponentSTW::GetEventHeatPercent(EFortCombatEvents::Type CombatEvent)
{
	return float();
}

float UCombatManagerComponentSTW::GetEventHeatPercentTotal(EFortCombatEvents::Type CombatEvent)
{
	return float();
}

void UCombatManagerComponentSTW::OnRep_CombatEventHeat()
{
}

void UCombatManagerComponentSTW::ServerTriggerCombatEvent_Implementation(EFortCombatEvents::Type TriggeredEvent, float HeatMultiplier)
{
}
bool UCombatManagerComponentSTW::ServerTriggerCombatEvent_Validate(EFortCombatEvents::Type TriggeredEvent, float HeatMultiplier)
{
	return true;
}

void UCombatManagerComponentSTW::ServerTriggerCombatEventBatch_Implementation(const TArray<FFortCombatManagerEvent>& Payload)
{
}
bool UCombatManagerComponentSTW::ServerTriggerCombatEventBatch_Validate(const TArray<FFortCombatManagerEvent>& Payload)
{
	return true;
}

void UCombatManagerComponentSTW::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCombatManagerComponentSTW, ReplicatedCombatEventHeat);
	DOREPLIFETIME(UCombatManagerComponentSTW, CurrentTotalHeat);
	DOREPLIFETIME(UCombatManagerComponentSTW, MaximumTotalHeat);
	DOREPLIFETIME(UCombatManagerComponentSTW, MaxHeatEver);
}
