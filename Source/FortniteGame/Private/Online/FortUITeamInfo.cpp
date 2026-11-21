// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortUITeamInfo.h"
#include "UObject/Class.h"

bool FFortTeamMemberInfo::operator==(const FFortTeamMemberInfo& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FFortTeamMemberInfo& Value)
{
	return 0;
}

void UFortUITeamInfo::GetTeamHitPointFractions(TArray<float>& HealthFractions, TArray<float>& ShieldFractions) const
{
}

bool UFortUITeamInfo::GetTeamMember(int32 MemberIndex, FFortTeamMemberInfo& OutMember) const
{
	return false;
}

void UFortUITeamInfo::GetTeamMemberIDs(TArray<FUniqueNetIdRepl>& TeamMemberIDs) const
{
}

void UFortUITeamInfo::GetTeamMembers(TArray<FFortTeamMemberInfo>& TeamMembers) const
{
}

bool UFortUITeamInfo::IsTeamMemberSynchronizing(const FUniqueNetIdRepl& PlayerID)
{
	return false;
}
