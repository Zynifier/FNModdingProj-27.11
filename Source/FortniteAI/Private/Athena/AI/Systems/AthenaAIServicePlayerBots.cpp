// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/Systems/AthenaAIServicePlayerBots.h"

void UAthenaAIServicePlayerBots::AddPOIVolume(AFortPoiVolume* POIVolume, EAthenaAIServicePOIList POIList)
{
}

int32 UAthenaAIServicePlayerBots::FetchNextCustomBotCosmeticVariantID(const AFortPlayerPawnAthena* BotPawn)
{
	return int32();
}

bool UAthenaAIServicePlayerBots::IsWeaponSupported(AFortWeapon* FortWeapon)
{
	return false;
}

void UAthenaAIServicePlayerBots::JoinTeam(const AController* SourceTeamController, AController* DestinationTeamController)
{
}

void UAthenaAIServicePlayerBots::KillBots(bool bKillPlayers, bool bKillNPCs, uint8 TeamIndex, AActor* BotOwner)
{
}

void UAthenaAIServicePlayerBots::OnAgentGameOver(AFortAthenaAIBotController* AIBotController, AFortPawn* Pawn, AController* Instigator)
{
}

void UAthenaAIServicePlayerBots::OnAIPawnSpawned(AController* SpawnedController, bool bIsABot, AFortPawn* FortAIPawn, AFortPlayerPawn* PlayerPawn)
{
}

void UAthenaAIServicePlayerBots::OnGamePhaseChanged(const FFortGamePhaseUpdatedEvent& Event)
{
}

void UAthenaAIServicePlayerBots::OnGamePhaseLogicReady(const FFortBattleRoyaleGamePhaseLogicComponentReadyEvent& Event)
{
}

void UAthenaAIServicePlayerBots::OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UAthenaAIServicePlayerBots::OnSafeZoneUpdated(const FFortSafeZonePhaseUpdatedEvent& Event)
{
}

void UAthenaAIServicePlayerBots::OnServerGameMemberRemoved(uint8 InSquadId, uint8 InTeamIndex, AFortPlayerStateAthena* ChangedPS)
{
}

APawn* UAthenaAIServicePlayerBots::SpawnAI(const FVector& InSpawnLocation, const FRotator& InSpawnRotation, const UFortAthenaAISpawnerDataComponentList* AISpawnerComponentList)
{
	return nullptr;
}
