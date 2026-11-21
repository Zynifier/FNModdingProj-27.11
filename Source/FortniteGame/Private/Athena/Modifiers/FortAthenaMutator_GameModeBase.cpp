// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"

const FText& AFortAthenaMutator_GameModeBase::GetPOINameForTag(const FGameplayTag& POITag) const
{
	static FText Dummy;
	return Dummy;
}

void AFortAthenaMutator_GameModeBase::HandleEndMatchStingerWaitingOnPlacement_Local(AFortPlayerStateAthena* Sender, int32 NewPlace)
{
}

void AFortAthenaMutator_GameModeBase::OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3)
{
}

void AFortAthenaMutator_GameModeBase::OnPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContainerTags)
{
}

void UFortAudioEventForwarder::HandleGamePhaseChanged(const FFortGamePhaseUpdatedEvent& Event)
{
}
