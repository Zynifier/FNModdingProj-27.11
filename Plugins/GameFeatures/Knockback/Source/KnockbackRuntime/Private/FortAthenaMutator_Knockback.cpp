// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaMutator_Knockback.h"
#include "Net/UnrealNetwork.h"

TArray<FKnockbackMutatorData> AFortAthenaMutator_Knockback::GetAllPlayersKnockbackData()
{
	return TArray<FKnockbackMutatorData>();
}

float AFortAthenaMutator_Knockback::GetKnockbackMultiplierInitialValue() const
{
	return float();
}

float AFortAthenaMutator_Knockback::GetPercentDamageLowMaxThreshold() const
{
	return float();
}

float AFortAthenaMutator_Knockback::GetPercentDamageMediumMaxThreshold() const
{
	return float();
}

void AFortAthenaMutator_Knockback::HandleBlockedCharacterMovement(FHitResult& InOutImpact, AFortPawn* FortPawn)
{
}

void AFortAthenaMutator_Knockback::SetPlayersShouldBreakThroughStructures(const bool bActive, AFortPlayerPawn* PlayerPawn)
{
}

void AFortAthenaMutator_Knockback::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_Knockback, AllPlayersKnockbackData);
}
