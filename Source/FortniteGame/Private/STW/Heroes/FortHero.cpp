// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Heroes/FortHero.h"

UFortHeroType* UFortHero::GetHeroTypeBP() const
{
	return nullptr;
}

int32 UFortHero::GetUnclampedLevel() const
{
	return int32();
}

bool UFortHero::IsInExpeditionSquad() const
{
	return false;
}

bool UFortHero::IsLevelClamped() const
{
	return false;
}
