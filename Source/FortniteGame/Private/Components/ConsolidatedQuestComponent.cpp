// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/ConsolidatedQuestComponent.h"

TArray<FName> UConsolidatedQuestComponent::Editor_GetValidObjectives() const
{
	return TArray<FName>();
}

UFortQuestItemDefinition* UConsolidatedQuestComponent::GetQuestItemDefinition() const
{
	return nullptr;
}

bool UConsolidatedQuestComponent::IsInteractable(AFortPlayerController* InteractingController)
{
	return false;
}

void UConsolidatedQuestComponent::OnCalendarUpdated()
{
}

void UConsolidatedQuestComponent::OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UConsolidatedQuestComponent::SetObjectiveBackendName(const FName& InObjectiveBackendName)
{
}

void UConsolidatedQuestComponent::SetQuestItemDefinition(UFortQuestItemDefinition* InQuestItemDefinition)
{
}

void UConsolidatedQuestComponent::UpdateCompletedForPlayer(AFortPlayerController* InPlayerController, bool bCompleted)
{
}
