// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortPartyContext.h"

void UFortPartyContext::AcceptMcpFriendRequest(const FUniqueNetIdRepl& PlayerID)
{
}

FText UFortPartyContext::GetAthenaPartyMemberReadyText(const FUniqueNetIdRepl& MemberId) const
{
	return FText();
}

EAthenaPartyMemberReadyType UFortPartyContext::GetAthenaPartyMemberReadyType(const FUniqueNetIdRepl& MemberId) const
{
	return EAthenaPartyMemberReadyType();
}

EFortFriendRequestStatus UFortPartyContext::GetConsoleFriendRequestStatusForPlayer(const FUniqueNetIdRepl& PlayerID) const
{
	return EFortFriendRequestStatus();
}

EFortFriendRequestStatus UFortPartyContext::GetFriendRequestStatusForTeamMember(const FFortTeamMemberInfo& TeamMemberInfo, FUniqueNetIdRepl& UniqueIdUsed, bool& bIsMcpId) const
{
	return EFortFriendRequestStatus();
}

bool UFortPartyContext::GetLocalPartyMemberLocation(EFortPartyMemberLocation& Location) const
{
	return false;
}

EFortPartyState UFortPartyContext::GetLocalPartyProgression() const
{
	return EFortPartyState();
}

FString UFortPartyContext::GetLocalPlayerDisplayName() const
{
	return FString();
}

UFortUITeamInfo* UFortPartyContext::GetLocalPlayerTeam() const
{
	return nullptr;
}

void UFortPartyContext::GetLocalPlayerTeamMemberInfo(FFortTeamMemberInfo& LocalPlayerInfo) const
{
}

bool UFortPartyContext::GetLocalTeamTeamMemberInfo(AFortPlayerState* TeamMemberState, FFortTeamMemberInfo& TeamMemberInfo)
{
	return false;
}

int32 UFortPartyContext::GetMaxTeamSizeForSelectedTheater() const
{
	return int32();
}

EFortFriendRequestStatus UFortPartyContext::GetMcpFriendRequestStatusForPlayer(const FUniqueNetIdRepl& PlayerID) const
{
	return EFortFriendRequestStatus();
}

int32 UFortPartyContext::GetNumPlayersInLocalParty() const
{
	return int32();
}

EFortPartyMemberDisplayState UFortPartyContext::GetPartyMemberDisplayState(const FFortTeamMemberInfo& PartyMemberInfo) const
{
	return EFortPartyMemberDisplayState();
}

ECommonInputType UFortPartyContext::GetPartyMemberInputType(const FUniqueNetIdRepl& MemberId) const
{
	return ECommonInputType();
}

bool UFortPartyContext::GetPartyMemberLocation(const FUniqueNetIdRepl& MemberId, EFortPartyMemberLocation& LocationOut) const
{
	return false;
}

bool UFortPartyContext::GetPartyPrivacySetting(EPartyType& OutPartyType, bool& OutLeaderFriendsOnly, bool& OutLeaderInvitesOnly)
{
	return false;
}

bool UFortPartyContext::IsEntirePartyInFrontEnd() const
{
	return false;
}

bool UFortPartyContext::IsLocalPlayerLFG() const
{
	return false;
}

bool UFortPartyContext::IsLocalPlayerPartyLeader() const
{
	return false;
}

bool UFortPartyContext::IsNetIdFromLocalPlayersPlatform(const FUniqueNetIdRepl& PlayerId) const
{
	return false;
}

bool UFortPartyContext::IsValidNetID(const FUniqueNetIdRepl& UniqueNetID)
{
	return false;
}

void UFortPartyContext::LeaveAction(bool bInStayWithParty)
{
}

void UFortPartyContext::LeaveParty()
{
}

void UFortPartyContext::SendMcpFriendRequest(const FUniqueNetIdRepl& PlayerID)
{
}

void UFortPartyContext::SetLocalPartyMemberLocation(EFortPartyMemberLocation location)
{
}

void UFortPartyContext::SetLocalPlayerLFG(bool bInLFG)
{
}

void UFortPartyContext::SetPartyPrivacySetting(EPartyType PartyType, bool bLeaderFriendsOnly, bool bLeaderInvitesOnly)
{
}

bool UFortPartyContext::ShouldShowCrossplayWarningDialog() const
{
	return false;
}

void UFortPartyContext::ShowInitialCrossplayPrompt()
{
}
