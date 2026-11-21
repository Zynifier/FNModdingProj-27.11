// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Player/FortPlayerControllerPvE.h"

void AFortPlayerControllerPvE::ClientHideIdleWarning_Implementation()
{
}

void AFortPlayerControllerPvE::ClientShowIdleWarning_Implementation(float TimeUntilKick)
{
}

void AFortPlayerControllerPvE::ClientUpdateQuickBarRecordsCache_Implementation(const FQuickBar& PrimaryQuickBarRecord, const FQuickBar& SecondaryQuickBarRecord)
{
}

void AFortPlayerControllerPvE::HandleQuickBarChanged(EFortQuickBars QuickBarType, const TArray<int32>& Slots)
{
}

void AFortPlayerControllerPvE::PreparePlayerForDisplay()
{
}

void AFortPlayerControllerPvE::RefreshHarvestingWeapon()
{
}

void AFortPlayerControllerPvE::RequestIdleDetectionState(EFortIdleDetectionState NewIdleDetectionState, const FString& Reason)
{
}

void AFortPlayerControllerPvE::ResetPlayerDeathReportForForcePlayerRestart()
{
}

void AFortPlayerControllerPvE::ServerFriendPlayerAdded_Implementation(AFortPlayerStatePvE* FriendPS, bool bIsEpicFriend)
{
}

void AFortPlayerControllerPvE::ServerTriggerSetupTeleportCameraEvent_Implementation()
{
}
bool AFortPlayerControllerPvE::ServerTriggerSetupTeleportCameraEvent_Validate()
{
	return true;
}

void AFortPlayerControllerPvE::ServerUpdateQuickBarRecordsCache_Implementation(const FQuickBar& PrimaryQuickBarRecord, const FQuickBar& SecondaryQuickBarRecord)
{
}
bool AFortPlayerControllerPvE::ServerUpdateQuickBarRecordsCache_Validate(const FQuickBar& PrimaryQuickBarRecord, const FQuickBar& SecondaryQuickBarRecord)
{
	return true;
}
