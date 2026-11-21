// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Devices/FortCreativeTimerDevice.h"

void AFortCreativeTimerDevice::AddTimerDeviceToVolume()
{
}

void AFortCreativeTimerDevice::BroadcastUpdateToHUD()
{
}

void AFortCreativeTimerDevice::ClearTrackedTimers()
{
}

void AFortCreativeTimerDevice::CreateTrackedTimer(AController* PlayerController, ETimerDeviceState StartingState)
{
}

float AFortCreativeTimerDevice::GetTimerRemaining(AController* TrackedPlayer) const
{
	return float();
}

bool AFortCreativeTimerDevice::GetTimerState(AController* TrackedPlayer, ETimerDeviceState& OutState) const
{
	return false;
}

int32 AFortCreativeTimerDevice::GetTrackedPlayers(TArray<AController*>& OutTrackedPlayers) const
{
	return int32();
}

void AFortCreativeTimerDevice::OnGameStateSet(AFortGameState* GameState)
{
}

void AFortCreativeTimerDevice::RemoveTrackedTimer(AController* PlayerController)
{
}

void AFortCreativeTimerDevice::ServerRequestClearDisplay(const TArray<AController*>& PlayersToUpdate)
{
}

void AFortCreativeTimerDevice::ServerRequestDisplayUpdate(AController* TrackedPlayer, const TArray<AController*>& PlayersToUpdate)
{
}

void AFortCreativeTimerDevice::TimerClearHandles(AController* TrackedPlayer)
{
}

void AFortCreativeTimerDevice::TimerPause(AController* TrackedPlayer)
{
}

void AFortCreativeTimerDevice::TimerResume(AController* TrackedPlayer)
{
}

void AFortCreativeTimerDevice::TimerSetState(AController* TrackedPlayer, ETimerDeviceState NewState, bool bLoadingFromSave)
{
}

void AFortCreativeTimerDevice::TimerStart(AController* TrackedPlayer, float Duration, float TimeUntilUrgency)
{
}
