// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortPlayerControllerSpectating.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerControllerSpectating::AdjustNormalizedDistanceToPlayer(const float Val)
{
}

bool AFortPlayerControllerSpectating::AreNotificationsEnabled() const
{
	return false;
}

void AFortPlayerControllerSpectating::BlendCameraPlacement(const FTransform InTransform, const FTransform InTargetTransform, const float BlendDuration, const ESpectateBlendEasing InEasing)
{
}

bool AFortPlayerControllerSpectating::CanRespawnAfterDeath() const
{
	return false;
}

AFortPlayerState* AFortPlayerControllerSpectating::FindPlayerStateByUID(const FUniqueNetIdRepl& UID) const
{
	return nullptr;
}

bool AFortPlayerControllerSpectating::FollowHoveredPlayer()
{
	return false;
}

void AFortPlayerControllerSpectating::FollowLastDamagerOfViewTarget()
{
}

void AFortPlayerControllerSpectating::FollowNextPlayer()
{
}

void AFortPlayerControllerSpectating::FollowNextSquadMember()
{
}

void AFortPlayerControllerSpectating::FollowNextTeamMember()
{
}

void AFortPlayerControllerSpectating::FollowPlayerByName(const FString& PlayerName)
{
}

void AFortPlayerControllerSpectating::FollowPrevPlayer()
{
}

void AFortPlayerControllerSpectating::FollowPrevSquadMember()
{
}

void AFortPlayerControllerSpectating::FollowPrevTeamMember()
{
}

EFortSpectatorBlendType AFortPlayerControllerSpectating::GetBlendType() const
{
	return EFortSpectatorBlendType();
}

UFortSpectatorCameraComponent* AFortPlayerControllerSpectating::GetCurrentSpectatorCameraComponent() const
{
	return nullptr;
}

AFortPlayerState* AFortPlayerControllerSpectating::GetFollowedPlayer() const
{
	return nullptr;
}

void AFortPlayerControllerSpectating::HandleNewNotificationRequest(const FText& NotificationText, const FNotificationUISettings& NotificationSettings) const
{
}

void AFortPlayerControllerSpectating::HandleSquadIdModeChanged(ESpectatorSquadIdMode SquadIdMode)
{
}

void AFortPlayerControllerSpectating::HandleTimelineScrubbed(UWorld* InWorld)
{
}

bool AFortPlayerControllerSpectating::HasBroadcasterToken() const
{
	return false;
}

bool AFortPlayerControllerSpectating::IsAllowedChangeCamera()
{
	return false;
}

bool AFortPlayerControllerSpectating::IsCameraBlending() const
{
	return false;
}

bool AFortPlayerControllerSpectating::IsFollowedPlayerInBus() const
{
	return false;
}

bool AFortPlayerControllerSpectating::IsPlayerInRelevancy(const AFortPlayerState* FPS) const
{
	return false;
}

bool AFortPlayerControllerSpectating::IsValidToFollow(AFortPlayerState* FPS) const
{
	return false;
}

bool AFortPlayerControllerSpectating::JumpToHoveredActor()
{
	return false;
}

void AFortPlayerControllerSpectating::OnNextCameraMode()
{
}

void AFortPlayerControllerSpectating::OnRep_FollowedPlayerRemoteClientInfo(AFortBroadcastRemoteClientInfo* PreviousFollowedPlayerRemoteClientInfo)
{
}

void AFortPlayerControllerSpectating::PlayerBecameRelevant(AFortPlayerState* FPS)
{
}

void AFortPlayerControllerSpectating::ResetAllCameras()
{
}

void AFortPlayerControllerSpectating::ResetCamera()
{
}

void AFortPlayerControllerSpectating::ResetCameraBoundsVolume()
{
}

void AFortPlayerControllerSpectating::SetBlendType(EFortSpectatorBlendType NewBlendType)
{
}

void AFortPlayerControllerSpectating::SetFollowedPlayer(AFortPlayerState* NewPlayerToFollow)
{
}

void AFortPlayerControllerSpectating::SetNewCameraType(ESpectatorCameraType NewCameraType, bool bReset)
{
}

void AFortPlayerControllerSpectating::SetNotificationsEnabled(bool bNewState)
{
}

void AFortPlayerControllerSpectating::SpectatorClearSavedCameraShots()
{
}

void AFortPlayerControllerSpectating::SpectatorSpecialAction()
{
}

void AFortPlayerControllerSpectating::ToggleSpectatorHUD()
{
}

void AFortPlayerControllerSpectating::UpdateReplayEvents(EPlayEventType Type)
{
}

void AFortPlayerControllerSpectating::ZoomIn(const float Val)
{
}

void AFortPlayerControllerSpectating::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerControllerSpectating, FollowedPlayerRemoteClientInfo);
}
