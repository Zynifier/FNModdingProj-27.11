// Copyright Epic Games, Inc. All Rights Reserved.

#include "Attributes/FortHealthSet.h"
#include "Net/UnrealNetwork.h"

void UFortHealthSet::ClearDamageDoneOverrideDelegate()
{
}

bool UFortHealthSet::IsTacticalOvershieldEnabled()
{
	return false;
}

void UFortHealthSet::OnRep_BlockedDamage(const FFortGameplayAttributeData& OldValue)
{
}

void UFortHealthSet::OnRep_CurrentOvershield(const FFortGameplayAttributeData& OldValue)
{
}

void UFortHealthSet::OnRep_CurrentShield(const FFortGameplayAttributeData& OldValue)
{
}

void UFortHealthSet::OnRep_Health(const FFortGameplayAttributeData& OldValue)
{
}

void UFortHealthSet::OnRep_MaxHealth(const FFortGameplayAttributeData& OldValue)
{
}

void UFortHealthSet::OnRep_MaxOvershield(const FFortGameplayAttributeData& OldValue)
{
}

void UFortHealthSet::OnRep_MaxSignalInStorm(const FFortGameplayAttributeData& OldValue)
{
}

void UFortHealthSet::OnRep_Shield(const FFortGameplayAttributeData& OldValue)
{
}

void UFortHealthSet::OnRep_SignalInStorm(const FFortGameplayAttributeData& OldValue)
{
}

void UFortHealthSet::SetDamageDoneOverrideDelegate(FOnDamageDoneOverrideSignature InOnDamageDoneOverrideDelegate)
{
}

void UFortHealthSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortHealthSet, Health);
	DOREPLIFETIME(UFortHealthSet, MaxHealth);
	DOREPLIFETIME(UFortHealthSet, Shield);
	DOREPLIFETIME(UFortHealthSet, CurrentShield);
	DOREPLIFETIME(UFortHealthSet, MaxOvershield);
	DOREPLIFETIME(UFortHealthSet, CurrentOvershield);
	DOREPLIFETIME(UFortHealthSet, SignalInStorm);
	DOREPLIFETIME(UFortHealthSet, MaxSignalInStorm);
	DOREPLIFETIME(UFortHealthSet, Armor);
	DOREPLIFETIME(UFortHealthSet, DamageResistance);
	DOREPLIFETIME(UFortHealthSet, DamageVulnerability);
	DOREPLIFETIME(UFortHealthSet, ReflectDamageAbsolute);
	DOREPLIFETIME(UFortHealthSet, ReflectDamageFromSource);
	DOREPLIFETIME(UFortHealthSet, DamageReduction);
	DOREPLIFETIME(UFortHealthSet, HealingSourceBaseMultiplier);
	DOREPLIFETIME(UFortHealthSet, DamageScaleLight);
	DOREPLIFETIME(UFortHealthSet, DamageScaleNormal);
	DOREPLIFETIME(UFortHealthSet, DamageScaleCritical);
	DOREPLIFETIME(UFortHealthSet, DamageScaleVulnerable);
	DOREPLIFETIME(UFortHealthSet, DamageScaleInvulnerable);
	DOREPLIFETIME(UFortHealthSet, HealingSource);
	DOREPLIFETIME(UFortHealthSet, HealingBonusTarget);
	DOREPLIFETIME(UFortHealthSet, BlockingAngle);
	DOREPLIFETIME(UFortHealthSet, BlockingDamageResistance);
	DOREPLIFETIME(UFortHealthSet, DamageResistanceCap);
	DOREPLIFETIME(UFortHealthSet, BlockedDamage);
}
