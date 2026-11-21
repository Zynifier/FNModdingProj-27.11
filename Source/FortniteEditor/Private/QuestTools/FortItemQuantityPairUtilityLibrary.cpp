// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestTools/FortItemQuantityPairUtilityLibrary.h"

TSoftObjectPtr<UFortItemDefinition> UFortItemQuantityPairUtilityLibrary::GetEditorOnlyItemDefinition(const FFortHiddenRewardQuantityPair& HiddenReward)
{
	return TSoftObjectPtr<UFortItemDefinition>();
}

FFortHiddenRewardQuantityPair UFortItemQuantityPairUtilityLibrary::MakeFortHiddenRewardQuantityPairFromItemDefinition(const TSoftObjectPtr<UFortItemDefinition> ItemDefinitionToGrant, const int32 QuantityToGrant)
{
	return FFortHiddenRewardQuantityPair();
}

void UFortItemQuantityPairUtilityLibrary::SetEditorOnlyItemDefinition(FFortHiddenRewardQuantityPair& HiddenReward, const TSoftObjectPtr<UFortItemDefinition> ItemDefinitionToGrant)
{
}

bool UFortItemQuantityPairUtilityLibrary::UsesEditorOnlyItemDefinition(const FFortHiddenRewardQuantityPair& HiddenReward)
{
	return false;
}
