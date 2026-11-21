// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/QuestInteractableComponent.h"
#include "Net/UnrealNetwork.h"

TArray<FName> UQuestInteractableComponent::Editor_GetValidObjectives() const
{
	return TArray<FName>();
}

UFortQuestManager* UQuestInteractableComponent::GetQuestManagerForActor(AActor* InActor)
{
	return nullptr;
}

void UQuestInteractableComponent::OnCalendarUpdated()
{
}

void UQuestInteractableComponent::OnDisplayDynamicQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool bDisplayStatusUpdate, bool bDisplayAnnouncementUpdate)
{
}

void UQuestInteractableComponent::OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UQuestInteractableComponent::OnRep_Ready()
{
}

void UQuestInteractableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UQuestInteractableComponent, bReady);
}
