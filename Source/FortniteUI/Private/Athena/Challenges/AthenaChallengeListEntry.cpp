// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Challenges/AthenaChallengeListEntry.h"

int32 UAthenaChallengeListEntry_Challenge::GetChallengeWeight() const
{
	return int32();
}

void UAthenaChallengeListEntry_DetailedChallenge::HandleCloseChallengeOptionsInputAction(bool& bPassThrough)
{
}

void UAthenaChallengeListEntry_DetailedChallenge::HandleUpperAreaClicked()
{
}

void UAthenaChallengeListEntry_StoreOffer::HandleClicked()
{
}

UAthenaChallengeRewardDisplay::UAthenaChallengeRewardDisplay(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UAthenaChallengeRewardDisplayEntry::UAthenaChallengeRewardDisplayEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
