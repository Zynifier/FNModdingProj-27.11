// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_SurvivorTiers.h"

UFortControllerComponent_SurvivorTiers::UFortControllerComponent_SurvivorTiers(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortControllerComponent_SurvivorTiers::GetPrestigeAndTier(int32& OutSurvivorPrestige, int32& OutSurvivorTierRaw, int32& OutSurvivorTierDisplay) const
{
}

void UFortControllerComponent_SurvivorTiers::HandleMCPSurvivorStateChanged()
{
}

void UFortControllerComponent_SurvivorTiers::HandleQuestCompleted(const TScriptInterface<IQuestInstanceInterface>& QuestInstance)
{
}
