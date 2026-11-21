// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventStatComponent.h"
#include "Net/UnrealNetwork.h"

void USpecialEventStatComponent::AdjustSpecialEventStat(AActor* Actor, const FGameplayTag LookupTag, const float Adjustment)
{
}

bool USpecialEventStatComponent::AdjustStat(const FGameplayTag LookupTag, const float Adjustment, const bool bLogError)
{
	return false;
}

const FSpecialEventStatArrayEntry& USpecialEventStatComponent::GetSpecialEventStat(bool& bOutValid, const AActor* Actor, const FGameplayTag LookupTag)
{
	static FSpecialEventStatArrayEntry Dummy;
	return Dummy;
}

const FSpecialEventStatArrayEntry& USpecialEventStatComponent::GetStat(bool& bOutValid, const FGameplayTag LookupTag)
{
	static FSpecialEventStatArrayEntry Dummy;
	return Dummy;
}

void USpecialEventStatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USpecialEventStatComponent, StatFastArray);
}
