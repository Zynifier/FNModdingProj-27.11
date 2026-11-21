// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortEmoteVolume.h"

#if WITH_EDITOR
TArray<FName> AFortEmoteVolume::Editor_GetValidObjectives() const
{
	return TArray<FName>();
}
#endif

const TArray<FEmoteActionBinding> AFortEmoteVolume::GetGrantedEmotes() const
{
	return TArray<FEmoteActionBinding>();
}

const FName AFortEmoteVolume::GetRequiredObjectiveName() const
{
	return FName();
}

const UFortQuestItemDefinition* AFortEmoteVolume::GetRequiredQuest() const
{
	return nullptr;
}

bool AFortEmoteVolume::IsPlayerOverlapping(const AFortPlayerController* PlayerController) const
{
	return false;
}

bool AFortEmoteVolume::WasPlayerGrantedEmotes(const AFortPlayerController* PlayerController) const
{
	return false;
}
