// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Spectator/AthenaRemotePlayerViewData.h"

void UAthenaRemotePlayerViewData::ForwardOnBeingRevivedStateChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsBeingRevived)
{
}

void UAthenaRemotePlayerViewData::ForwardOnDBNOStateChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDBNO)
{
}

void UAthenaRemotePlayerViewData::ForwardOnDeadStateChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDead)
{
}

void UAthenaRemotePlayerViewData::ForwardOnDisconnectedChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDisconnected)
{
}

void UAthenaRemotePlayerViewData::ForwardOnHitPointsStateChanged(AFortPlayerStateAthena* InPlayerState, float InHealth, float InHealthMax, float InShield, float InShieldMax)
{
}

void UAthenaRemotePlayerViewData::ForwardOnKillScoreChanged(AFortPlayerStateAthena* InPlayerState, int32 InKillScore)
{
}

void UAthenaRemotePlayerViewData::ForwardOnLocationChanged(const FString& InLocation)
{
}

void UAthenaRemotePlayerViewData::ForwardOnPlaceChanged(AFortPlayerStateAthena* Sender, int32 InPlace)
{
}

void UAthenaRemotePlayerViewData::ForwardOnPlayerNameChanged(AFortPlayerStateAthena* InPlayerState, const FString& InPlayerName)
{
}

void UAthenaRemotePlayerViewData::ForwardOnSquadIdChanged(uint8 InSquadId)
{
}

void UAthenaRemotePlayerViewData::ForwardOnVehicleHealthChanged()
{
}

void UAthenaRemotePlayerViewData::ForwardOnVehicleStateChanged(AFortPlayerPawn* PlayerPawn, AActor* NewVehicle, AActor* OldVehicle)
{
}

void UAthenaRemotePlayerViewData::ForwardOnWeaponChanged(AFortWeapon* InNewWeapon, AFortWeapon* InPrevWeapon)
{
}

AFortWeapon* UAthenaRemotePlayerViewData::GetCurrentWeapon() const
{
	return nullptr;
}

int32 UAthenaRemotePlayerViewData::GetDistanceToStorm() const
{
	return int32();
}

void UAthenaRemotePlayerViewData::GetHealth(float& Health, float& HealthMax) const
{
}

float UAthenaRemotePlayerViewData::GetHealthPercent() const
{
	return float();
}

bool UAthenaRemotePlayerViewData::GetInAircraft() const
{
	return false;
}

bool UAthenaRemotePlayerViewData::GetIsBeingRevived() const
{
	return false;
}

bool UAthenaRemotePlayerViewData::GetIsDBNO() const
{
	return false;
}

bool UAthenaRemotePlayerViewData::GetIsDead() const
{
	return false;
}

bool UAthenaRemotePlayerViewData::GetIsDisconnected() const
{
	return false;
}

bool UAthenaRemotePlayerViewData::GetIsDrivingVehicle() const
{
	return false;
}

bool UAthenaRemotePlayerViewData::GetIsEliminated() const
{
	return false;
}

bool UAthenaRemotePlayerViewData::GetIsFollowedPlayer() const
{
	return false;
}

bool UAthenaRemotePlayerViewData::GetIsInRelevancy() const
{
	return false;
}

bool UAthenaRemotePlayerViewData::GetIsReplayRelevancyPlayer() const
{
	return false;
}

int32 UAthenaRemotePlayerViewData::GetKillScore() const
{
	return int32();
}

FString UAthenaRemotePlayerViewData::GetLocation() const
{
	return FString();
}

int32 UAthenaRemotePlayerViewData::GetMaterialCount() const
{
	return int32();
}

void UAthenaRemotePlayerViewData::GetOvershield(float& Overshield, float& OvershieldMax) const
{
}

float UAthenaRemotePlayerViewData::GetOvershieldPercent() const
{
	return float();
}

int32 UAthenaRemotePlayerViewData::GetPlace() const
{
	return int32();
}

FString UAthenaRemotePlayerViewData::GetPlayerName() const
{
	return FString();
}

AFortPlayerPawn* UAthenaRemotePlayerViewData::GetPlayerPawn() const
{
	return nullptr;
}

AFortPlayerStateAthena* UAthenaRemotePlayerViewData::GetPlayerState() const
{
	return nullptr;
}

FUniqueNetIdRepl UAthenaRemotePlayerViewData::GetPlayerUID() const
{
	return FUniqueNetIdRepl();
}

int32 UAthenaRemotePlayerViewData::GetSessionRank() const
{
	return int32();
}

void UAthenaRemotePlayerViewData::GetShield(float& Shield, float& ShieldMax) const
{
}

float UAthenaRemotePlayerViewData::GetShieldPercent() const
{
	return float();
}

uint8 UAthenaRemotePlayerViewData::GetSquadId() const
{
	return uint8();
}

FLinearColor UAthenaRemotePlayerViewData::GetTeamColor() const
{
	return FLinearColor();
}

AActor* UAthenaRemotePlayerViewData::GetVehicle() const
{
	return nullptr;
}

float UAthenaRemotePlayerViewData::GetVehicleHealth() const
{
	return float();
}

float UAthenaRemotePlayerViewData::GetVehicleHealthPercent() const
{
	return float();
}

float UAthenaRemotePlayerViewData::GetVehicleMaxHealth() const
{
	return float();
}

void UAthenaRemotePlayerViewData::SetPlayerState(AFortPlayerStateAthena* InPlayerState)
{
}

void UAthenaRemotePlayerViewData::UpdateDistanceToStorm()
{
}

void UAthenaRemotePlayerViewData::UpdatePlayerPawn()
{
}
