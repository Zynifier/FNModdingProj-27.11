// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortGameStateComponent_KillFeedExtension.h"

UFortGameStateComponent_KillFeedExtension::UFortGameStateComponent_KillFeedExtension(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FString UFortGameStateComponent_KillFeedExtension::CheckForOverrideKillerStyle_Implementation(const AFortPlayerStateAthena* KillerPlayerStateAthena, const FString& KillerStyle) const
{
	return FString();
}

FString UFortGameStateComponent_KillFeedExtension::CheckForOverrideVictimStyle_Implementation(const AFortPlayerStateAthena* VictimPlayerStateAthena, const FString& VictimStyle) const
{
	return FString();
}
