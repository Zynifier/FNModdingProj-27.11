// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameState.h"
#include "Net/UnrealNetwork.h"

void AFortGameState::Client_InitiateEndOfDayRecap_Implementation(const FEndOfDayRecap& EndOfDayRecap)
{
}

void AFortGameState::Client_RefreshEventCalendar_Implementation()
{
}

void AFortGameState::CopyGameSessionIdToClipboard()
{
}

void AFortGameState::DbgBoxSendToAllInternal_DoNotCall_Implementation(const FVector& Center, const FVector& Extent, const FRotator& Rotation, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
}

void AFortGameState::DbgCapsuleSendToAllInternal_DoNotCall_Implementation(const FVector& Center, float HalfHeight, float Radius, const FQuat& Rotation, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
}

void AFortGameState::DbgLineSendToAllInternal_DoNotCall_Implementation(const FVector& LineStart, const FVector& LineEnd, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
}

void AFortGameState::DbgSphereSendToAllInternal_DoNotCall_Implementation(const FVector& Center, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness)
{
}

bool AFortGameState::DBNOEnabledForGameMode() const
{
	return false;
}

void AFortGameState::DemoEndOfDayRecap()
{
}

AFortPlayerState* AFortGameState::GetFortPlayerStateFromUniqueNetId(const FUniqueNetIdRepl& InPlayerId) const
{
	return nullptr;
}

EFortGameplayState::Type AFortGameState::GetGameplayState() const
{
	return EFortGameplayState::Type();
}

FString AFortGameState::GetGameSessionID() const
{
	return FString();
}

FGameplayTagContainer AFortGameState::GetHUDElementsToHide(const APawn* Pawn) const
{
	return FGameplayTagContainer();
}

FGameplayTagContainer AFortGameState::GetHUDElementsToShow(const APawn* Pawn) const
{
	return FGameplayTagContainer();
}

float AFortGameState::GetMatchTime() const
{
	return float();
}

TScriptInterface<IFortMiniMapInterface> AFortGameState::GetMiniMapInterface()
{
	return TScriptInterface<IFortMiniMapInterface>();
}

bool AFortGameState::GetPlayerRespawningBlocked_Temporarily() const
{
	return false;
}

AFortPoiManager* AFortGameState::GetPoiManager() const
{
	return nullptr;
}

double AFortGameState::GetRealMatchTime() const
{
	return double();
}

double AFortGameState::GetServerWorldRealTimeSeconds() const
{
	return double();
}

int32 AFortGameState::GetWorldDaysElapsed() const
{
	return int32();
}

void AFortGameState::HandleProfilingStatusChanged_Implementation(bool bStarted, EProfileCaptureType CaptureType, const FString& StatusMessage)
{
}

void AFortGameState::OnFinishedShowingAdditionalPlaylistLevel()
{
}

void AFortGameState::OnFinishedStreamingAdditionalPlaylistLevel()
{
}

void AFortGameState::OnRep_AdditionalPlaylistLevelsStreamed()
{
}

void AFortGameState::OnRep_AnnouncementManager()
{
}

void AFortGameState::OnRep_CurrentWUID()
{
}

void AFortGameState::OnRep_FeedbackManager()
{
}

void AFortGameState::OnRep_GameplayState()
{
}

void AFortGameState::OnRep_GameSessionID()
{
}

void AFortGameState::OnRep_MatchmakingLinkId()
{
}

void AFortGameState::OnRep_MatchmakingLinkType()
{
}

void AFortGameState::OnRep_MissionManager()
{
}

void AFortGameState::OnRep_MusicManagerBank()
{
}

void AFortGameState::OnRep_MusicManagerSubclass()
{
}

void AFortGameState::OnRep_PawnForReplayRelevancy(AFortPawn* OldPawnForReplayRelevancy)
{
}

void AFortGameState::OnRep_PoiManager()
{
}

void AFortGameState::OnRep_RecorderPlayerState()
{
}

void AFortGameState::OnRep_ReplicatedWorldRealTimeSecondsDouble()
{
}

void AFortGameState::OnRep_Teams()
{
}

void AFortGameState::OnRep_WorldDaysElapsed()
{
}

void AFortGameState::OnRep_WorldManager()
{
}

void AFortGameState::RunPerfMemCheatScript_Implementation(bool bStartStatFiles)
{
}

void AFortGameState::SetPlayerRespawningBlocked_Temporarily(bool bBlock)
{
}

void AFortGameState::UpdateServerRealTimeSeconds()
{
}

void AFortGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameState, CurrentWUID);
	DOREPLIFETIME(AFortGameState, ParTime);
	DOREPLIFETIME(AFortGameState, WorldLevel);
	DOREPLIFETIME(AFortGameState, CraftingBonus);
	DOREPLIFETIME(AFortGameState, CurrentReadyToContinueTimer);
	DOREPLIFETIME(AFortGameState, TeamCount);
	DOREPLIFETIME(AFortGameState, MatchmakingLinkId);
	DOREPLIFETIME(AFortGameState, MatchmakingLinkType);
	DOREPLIFETIME(AFortGameState, PoiManager);
	DOREPLIFETIME(AFortGameState, bDBNOEnabledForGameMode);
	DOREPLIFETIME(AFortGameState, bFishingCollectionEnabled);
	DOREPLIFETIME(AFortGameState, bCharacterCollectionEnabled);
	DOREPLIFETIME(AFortGameState, MatchStartTime);
	DOREPLIFETIME(AFortGameState, RealMatchStartTime);
	DOREPLIFETIME(AFortGameState, bPlayerRespawningBlocked_Temporarily);
	DOREPLIFETIME(AFortGameState, ReplicatedWorldRealTimeSecondsDouble);
	DOREPLIFETIME(AFortGameState, AdditionalPlaylistLevelsStreamed);
	DOREPLIFETIME(AFortGameState, WorldDaysElapsed);
	DOREPLIFETIME(AFortGameState, FeedbackManager);
	DOREPLIFETIME(AFortGameState, MissionManager);
	DOREPLIFETIME(AFortGameState, AnnouncementManager);
	DOREPLIFETIME(AFortGameState, WorldManager);
	DOREPLIFETIME(AFortGameState, GameplayState);
	DOREPLIFETIME(AFortGameState, MusicManagerSubclass);
	DOREPLIFETIME(AFortGameState, MusicManagerBank);
	DOREPLIFETIME(AFortGameState, GameSessionId);
	DOREPLIFETIME(AFortGameState, PawnForReplayRelevancy);
	DOREPLIFETIME(AFortGameState, RecorderPlayerState);
	DOREPLIFETIME(AFortGameState, Teams);
	DOREPLIFETIME(AFortGameState, PendingTeamChangeRequests);
	DOREPLIFETIME(AFortGameState, TreasureChestInfos);
	DOREPLIFETIME(AFortGameState, AmmoBoxInfos);
}
