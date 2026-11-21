// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/Components/PlayspaceComponent_CreativeModifyEmotes.h"

void UPlayspaceComponent_CreativeModifyEmotes::AddBlockedEmote(const FString& EmoteToBlock)
{
}

void UPlayspaceComponent_CreativeModifyEmotes::AddBlockedEmoteTag(const FGameplayTag& TagToBlock)
{
}

void UPlayspaceComponent_CreativeModifyEmotes::AddEmotesForPlayer(APlayerState* PlayerState)
{
}

void UPlayspaceComponent_CreativeModifyEmotes::AddEmotesToPlayersInSpatialInterface()
{
}

bool UPlayspaceComponent_CreativeModifyEmotes::AddEmoteToCategory(const FString& EmoteTemplateID, const FName& CategoryName, FEmoteActionBinding& OutCreatedEmote)
{
	return false;
}

bool UPlayspaceComponent_CreativeModifyEmotes::AddUniqueEmoteCategory(const FName& CategoryName, const FText& CategoryTitle, const FText& CategoryTitleMultipage, const bool bExclusive)
{
	return false;
}

UPlayspaceComponent_CreativeModifyEmotes* UPlayspaceComponent_CreativeModifyEmotes::GetCreativeModifyEmotesComponent(const AActor* ContextActor)
{
	return nullptr;
}

void UPlayspaceComponent_CreativeModifyEmotes::OnPlayerEnteredSpatialInterface(FEventMessageTag Channel, const FPlayerEnterSpatialActorContext& PlayerEnterSpatialActorContext)
{
}

void UPlayspaceComponent_CreativeModifyEmotes::OnPlayerExitedSpatialInterface(FEventMessageTag Channel, const FPlayerExitSpatialActorContext& PlayerExitSpatialActorContext)
{
}

void UPlayspaceComponent_CreativeModifyEmotes::RemoveBlockedEmote(const FString& EmoteToRemove)
{
}

void UPlayspaceComponent_CreativeModifyEmotes::RemoveBlockedEmoteTag(const FGameplayTag& TagToRemove)
{
}

void UPlayspaceComponent_CreativeModifyEmotes::RemoveEmoteCategory(const FName& CategoryName)
{
}

void UPlayspaceComponent_CreativeModifyEmotes::RemoveEmoteFromCategory(const FEmoteActionBinding& EmoteToRemove, const FName& CategoryName)
{
}

void UPlayspaceComponent_CreativeModifyEmotes::RemoveEmotesFromPlayerState(APlayerState* PlayerState, const TArray<FName>& CategoriesToRemove)
{
}
