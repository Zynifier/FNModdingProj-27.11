// Copyright Epic Games, Inc. All Rights Reserved.

#include "Attributes/FortRegenHealthSet.h"
#include "Net/UnrealNetwork.h"

void UFortRegenHealthSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortRegenHealthSet, HealthRegenRate);
	DOREPLIFETIME(UFortRegenHealthSet, HealthRegenDelay);
	DOREPLIFETIME(UFortRegenHealthSet, HealthRegenThreshold);
	DOREPLIFETIME(UFortRegenHealthSet, ShieldRegenRate);
	DOREPLIFETIME(UFortRegenHealthSet, ShieldRegenDelay);
	DOREPLIFETIME(UFortRegenHealthSet, ShieldRegenThreshold);
}

void UFortRegenHealthSet::Tick(float DeltaTime)
{
}

bool UFortRegenHealthSet::ShouldTick() const
{
	return false;
}
