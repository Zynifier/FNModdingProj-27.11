// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortSpectateAFriendController.h"
#include "Net/UnrealNetwork.h"

void AFortSpectateAFriendController::OnRep_FollowAnyTeam()
{
}

void AFortSpectateAFriendController::OnRep_HasValidTarget()
{
}

void AFortSpectateAFriendController::OnRep_PlayerJoinedOn()
{
}

void AFortSpectateAFriendController::OnRep_TeamJoinedOnPlacement()
{
}

void AFortSpectateAFriendController::OnRep_TeamToFollow()
{
}

void AFortSpectateAFriendController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortSpectateAFriendController, PlayerJoinedOn);
	DOREPLIFETIME(AFortSpectateAFriendController, HasValidTarget);
	DOREPLIFETIME(AFortSpectateAFriendController, TeamToFollow);
	DOREPLIFETIME(AFortSpectateAFriendController, FollowAnyTeam);
	DOREPLIFETIME(AFortSpectateAFriendController, TeamJoinedOnPlacement);
}
