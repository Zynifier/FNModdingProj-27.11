// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPlayerStartCreative.h"

AFortPlayerStartCreative::AFortPlayerStartCreative(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool AFortPlayerStartCreative::AreSpecialClaimingConditionsMet_Implementation() const
{
	return false;
}

bool AFortPlayerStartCreative::IsClaimedByPlayer(FUniqueNetIdRepl UniqueId) const
{
	return false;
}

void AFortPlayerStartCreative::OnMinigameStarted()
{
}
