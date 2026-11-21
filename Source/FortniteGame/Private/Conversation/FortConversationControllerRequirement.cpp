// Copyright Epic Games, Inc. All Rights Reserved.

#include "Conversation/FortConversationControllerRequirement.h"

bool UFortControllerRequirement::IsRequirementMet(const FControllerRequirementTestContext& RequestContext) const
{
	return false;
}

bool UFortControllerRequirement::IsRequirementMetInternal_Implementation(const FControllerRequirementTestContext& RequestContext) const
{
	return false;
}

TArray<FName> UFortControllerRequirement_HasCompletedQuestObjective::Editor_GetValidObjectives() const
{
	return TArray<FName>();
}
