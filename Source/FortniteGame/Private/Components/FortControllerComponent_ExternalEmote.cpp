// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_ExternalEmote.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_ExternalEmote::AddExternalEmoteCategories(const TArray<FExternalEmoteCategory>& NewCategories, const bool bAllowMerging, const bool bAllowUnownedEmotes)
{
}

void UFortControllerComponent_ExternalEmote::AddExternalEmotes(const TArray<FEmoteActionBinding>& NewEmotes, const bool bAllowUnownedEmotes)
{
}

void UFortControllerComponent_ExternalEmote::AddExternalEmoteSimple(const FPrimaryAssetId& Emote, const bool bAllowUnownedEmotes)
{
}

void UFortControllerComponent_ExternalEmote::AddExternalMultiEmoteCategories(const TArray<FExternalMultiEmoteCategory>& NewCategories)
{
}

const TArray<FExternalEmoteCategory>& UFortControllerComponent_ExternalEmote::GetExternalEmotes() const
{
	static TArray<FExternalEmoteCategory> Dummy;
	return Dummy;
}

const TArray<FExternalMultiEmoteCategory>& UFortControllerComponent_ExternalEmote::GetExternalMultiEmotes() const
{
	static TArray<FExternalMultiEmoteCategory> Dummy;
	return Dummy;
}

const TArray<FEmoteActionBinding>& UFortControllerComponent_ExternalEmote::GetUncategorizedEmotes() const
{
	static TArray<FEmoteActionBinding> Dummy;
	return Dummy;
}

void UFortControllerComponent_ExternalEmote::OnRep_ExternalEmotes(TArray<FExternalEmoteCategory>& PreviousExternalEmotes)
{
}

void UFortControllerComponent_ExternalEmote::OnRep_ExternalMultiEmotes(TArray<FExternalMultiEmoteCategory>& PreviousExternalMultiEmotes)
{
}

void UFortControllerComponent_ExternalEmote::OnRep_UncategorizedEmotes(TArray<FEmoteActionBinding>& PreviousUncategorizedEmotes)
{
}

void UFortControllerComponent_ExternalEmote::PlayEmoteAtIndex(const int32 CategoryIndex, const int32 EmoteIndex)
{
}

void UFortControllerComponent_ExternalEmote::PlayUncategorizedEmoteAtIndex(const int32 EmoteIndex)
{
}

void UFortControllerComponent_ExternalEmote::RemoveExternalEmote(const FPrimaryAssetId& EmoteToRemove)
{
}

void UFortControllerComponent_ExternalEmote::RemoveExternalEmoteByActionBinding(const FEmoteActionBinding& EmoteToRemove)
{
}

void UFortControllerComponent_ExternalEmote::RemoveExternalEmoteCategories(const TArray<FName>& CategoriesToRemove)
{
}

void UFortControllerComponent_ExternalEmote::RemoveExternalEmotes(const TArray<FPrimaryAssetId>& EmotesToRemove)
{
}

void UFortControllerComponent_ExternalEmote::RemoveExternalEmotesByActionBinding(const TArray<FEmoteActionBinding>& EmotesToRemove)
{
}

void UFortControllerComponent_ExternalEmote::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_ExternalEmote, ExternalEmotes);
	DOREPLIFETIME(UFortControllerComponent_ExternalEmote, ExternalMultiEmotes);
	DOREPLIFETIME(UFortControllerComponent_ExternalEmote, UncategorizedEmotes);
}
