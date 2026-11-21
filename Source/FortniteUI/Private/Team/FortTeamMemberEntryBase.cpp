// Copyright Epic Games, Inc. All Rights Reserved.

#include "Team/FortTeamMemberEntryBase.h"

EGameReadiness UFortTeamMemberEntryBase::GetCurrentMemberGameReadiness() const
{
	return EGameReadiness();
}

bool UFortTeamMemberEntryBase::IsCurrentMemberInFrontend() const
{
	return false;
}

bool UFortTeamMemberEntryBase::IsCurrentMemberLocal() const
{
	return false;
}

bool UFortTeamMemberEntryBase::IsCurrentMemberValid() const
{
	return false;
}
