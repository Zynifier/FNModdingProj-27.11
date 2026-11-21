// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialRelevancyHealthComponent.h"
#include "Net/UnrealNetwork.h"

void UDamageRecordEntry::OnRep_DamageTotal()
{
}

void UDamageRecordEntry::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UDamageRecordEntry, DamageTotal);
	DOREPLIFETIME(UDamageRecordEntry, EndReplicationTime);
	DOREPLIFETIME(UDamageRecordEntry, DamageTags);
	DOREPLIFETIME(UDamageRecordEntry, EffectContext);
}

float USpecialRelevancyHealthComponent::ClientGetHealth() const
{
	return float();
}

float USpecialRelevancyHealthComponent::ClientGetHealthPercent() const
{
	return float();
}

float USpecialRelevancyHealthComponent::GetHealth(const AActor* RelevancyActor) const
{
	return float();
}

float USpecialRelevancyHealthComponent::GetHealthFromRelevancyIndex(int32 Index) const
{
	return float();
}

float USpecialRelevancyHealthComponent::GetHealthPercent(const AActor* RelevancyActor) const
{
	return float();
}

float USpecialRelevancyHealthComponent::GetHealthPercentFromRelevancyIndex(int32 Index) const
{
	return float();
}

void USpecialRelevancyHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USpecialRelevancyHealthComponent, OwnerMaxHealthCached);
}
