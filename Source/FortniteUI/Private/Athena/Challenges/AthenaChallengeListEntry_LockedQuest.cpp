// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Challenges/AthenaChallengeListEntry_LockedQuest.h"

const FTimespan& UAthenaChallengeListEntry_LockedQuest::GetStartingUnlockTime() const
{
	static FTimespan Dummy;
	return Dummy;
}

FTimespan UAthenaChallengeListEntry_LockedQuest::GetTimeSinceEventStart() const
{
	return FTimespan();
}
