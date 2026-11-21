// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_AdHocSquads.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_AdHocSquads::HavePlayerLeaveAdHocSquad(AFortPlayerControllerAthena* LeavingPlayerController, const EAdHocSquads_LeaveSquadReason LeaveReason)
{
}

bool AFortAthenaMutator_AdHocSquads::IsPlayersSquadFull(const AFortPlayerControllerAthena* PlayerController) const
{
	return false;
}

bool AFortAthenaMutator_AdHocSquads::PlayerInitiatedSquadInvite(const AFortPlayerPawn* InFortPlayerPawn)
{
	return false;
}

void AFortAthenaMutator_AdHocSquads::PlayerSquadInviteEnded(AFortPlayerStateAthena* PlayerStateInviting, const EAdHocSquads_InviteStatus InviteEndedReason)
{
}

bool AFortAthenaMutator_AdHocSquads::ShouldAllowAdHocSquads()
{
	return false;
}

bool AFortAthenaMutator_AdHocSquads::SquadUpPlayers(EAdHocSquads_SquadUpResult& OutSquadUpResult, uint8& OutNewSharedSquad, AFortPlayerControllerAthena* SquadUpInstigatorPlayerController, AFortPlayerControllerAthena* SquadUpFollowerPlayerController)
{
	return false;
}

void AFortAthenaMutator_AdHocSquads::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_AdHocSquads, InviteDataArray);
}

void UFortCheatManager_AdHocSquads::AdHocSquadsDebugAssignPlayerToSquad(const int32 SquadIndex)
{
}

void UFortCheatManager_AdHocSquads::AdHocSquadsDebugResetPlayerSquad()
{
}

void UFortCheatManager_AdHocSquads::AdHocSquadsToggleVoiceChatSquadding()
{
}
