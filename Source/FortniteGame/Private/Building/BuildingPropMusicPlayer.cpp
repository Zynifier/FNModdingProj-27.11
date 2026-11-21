// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingPropMusicPlayer.h"
#include "Net/UnrealNetwork.h"

UDataTable* ABuildingPropMusicPlayer::GetMusicDataTable_Implementation() const
{
	return nullptr;
}

FString ABuildingPropMusicPlayer::GetSavedTrackName_Implementation() const
{
	return FString();
}

void ABuildingPropMusicPlayer::LoadThenPlaySong_Implementation()
{
}

void ABuildingPropMusicPlayer::OnRep_PlayingSongData()
{
}

void ABuildingPropMusicPlayer::StartSongForOptionsChange()
{
}

void ABuildingPropMusicPlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingPropMusicPlayer, MusicArray);
	DOREPLIFETIME(ABuildingPropMusicPlayer, PlayingSongData);
}
