// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/SpecialActor/FortSquadStart.h"

FTransform AFortSquadStart::GetPlayerStartTransform(const int32 Index) const
{
	return FTransform();
}

const FGameplayTagContainer& AFortSquadStart::GetSquadStartGameplayTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}
