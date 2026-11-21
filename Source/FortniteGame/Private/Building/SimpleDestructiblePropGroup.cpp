// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/SimpleDestructiblePropGroup.h"
#include "Net/UnrealNetwork.h"

int32 ASimpleDestructiblePropGroup::CalculateNumProps() const
{
	return int32();
}

UFortHealthSet* ASimpleDestructiblePropGroup::GetHealthAttributeSet() const
{
	return nullptr;
}

void ASimpleDestructiblePropGroup::OnRep_OrderedReplicatedInstanceData()
{
}

void ASimpleDestructiblePropGroup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASimpleDestructiblePropGroup, OrderedReplicatedInstanceData);
	DOREPLIFETIME(ASimpleDestructiblePropGroup, DamageEventServerTimestamp);
	DOREPLIFETIME(ASimpleDestructiblePropGroup, bLastDamageEventFromFire);
}

UAbilitySystemComponent* ASimpleDestructiblePropGroup::GetAbilitySystemComponent() const
{
	return nullptr;
}
