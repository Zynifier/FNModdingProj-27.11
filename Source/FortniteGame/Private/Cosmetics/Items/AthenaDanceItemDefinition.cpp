// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/AthenaDanceItemDefinition.h"

FText UAthenaDanceItemDefinition::GetChatTriggerCommandName() const
{
	return FText();
}

TSoftClassPtr<UFortGameplayAbility> UAthenaDanceItemDefinition::GetCustomDanceAbility() const
{
	return TSoftClassPtr<UFortGameplayAbility>();
}
