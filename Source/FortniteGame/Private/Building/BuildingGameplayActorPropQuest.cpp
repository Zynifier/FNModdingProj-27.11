// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorPropQuest.h"

FGameplayTagContainer ABuildingGameplayActorPropQuest::GetQuestTargetTags() const
{
	return FGameplayTagContainer();
}

void ABuildingGameplayActorPropQuest::HandleComponentOverlap_DisoveryRadius(AActor* OtherActor, FFortOverlapData OverlapData)
{
}

void ABuildingGameplayActorPropQuest::OverlapTagsRecheck(FFortOverlapData OverlapData)
{
}

bool ABuildingGameplayActorPropQuest::PlayerTagsCheck(const AFortPlayerController* FortPC, const FGameplayTagContainer RequiredPlayerTags, const FGameplayTagContainer ProhibitedPlayerTags)
{
	return false;
}

void ABuildingGameplayActorPropQuest::QuestLog(const FString StringToLog)
{
}

void ABuildingGameplayActorPropQuest::SendInteractionMessage(AActor* Author, const FGameplayTagContainer& SubjectTags)
{
}
