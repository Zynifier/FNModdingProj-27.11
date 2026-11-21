// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortGameplayAbility_Stasis.h"
#include "Net/UnrealNetwork.h"

void UFortGameplayAbility_Stasis::AppendAllowedActionTags(const FGameplayTagContainer& NewAllowedActionTags)
{
}

bool UFortGameplayAbility_Stasis::IsActionAllowed(const FGameplayTag& InActionTag) const
{
	return false;
}

void UFortGameplayAbility_Stasis::RemoveAllowedActionTags(const FGameplayTagContainer& ActionTagsToRemove)
{
}

void UFortGameplayAbility_Stasis::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameplayAbility_Stasis, AllowedActionTags);
}
