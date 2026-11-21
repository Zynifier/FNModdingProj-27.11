// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/GameDataSTW.h"

float UGameDataSTW::GetPersonalXpBoost()
{
	return float();
}

TSoftObjectPtr<UFortTeamPerkItemDefinition> UGameDataSTW::GetRecruitmentRewardForHero(UFortHeroType* Hero)
{
	return TSoftObjectPtr<UFortTeamPerkItemDefinition>();
}

float UGameDataSTW::GetTeamXpBoost()
{
	return float();
}

int32 UGameDataSTW::GetXpPerAccountLevel()
{
	return int32();
}
