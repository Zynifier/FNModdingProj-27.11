// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/Components/FortAthenaAlertStateComponent.h"
#include "Net/UnrealNetwork.h"

float UFortAthenaAlertStateComponent::GetStealthMeterTarget() const
{
	return float();
}

float UFortAthenaAlertStateComponent::GetStealthMeterTargetTime() const
{
	return float();
}

void UFortAthenaAlertStateComponent::OnStealthMeterChanged(AFortAthenaAIBotController* BotController, float StealthMeterTarget, float StealthMeterTargetTime)
{
}

void UFortAthenaAlertStateComponent::SetStealthMeterTarget(const float InStealthMeterTarget)
{
}

void UFortAthenaAlertStateComponent::SetStealthMeterTargetTime(const float InStealthMeterTargetTime)
{
}

void UFortAthenaAlertStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAthenaAlertStateComponent, StealthMeterTarget);
	DOREPLIFETIME(UFortAthenaAlertStateComponent, StealthMeterTargetTime);
}
