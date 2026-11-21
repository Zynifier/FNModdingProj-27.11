// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortRegisteredPlayerInfo.h"

UAbilitySystemComponent* UFortRegisteredPlayerInfo::GetAbilitySystemComponent() const
{
	return nullptr;
}

FString UFortRegisteredPlayerInfo::GetPlayerName() const
{
	return FString();
}

AFortPlayerState* UFortRegisteredPlayerInfo::GetPlayerState() const
{
	return nullptr;
}

void UFortRegisteredPlayerInfo::HandleDifferentHeroLoadoutActivated(const UFortMcpProfileCampaign* Profile)
{
}
