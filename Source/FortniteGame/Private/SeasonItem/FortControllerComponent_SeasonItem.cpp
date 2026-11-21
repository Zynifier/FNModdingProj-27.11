// Copyright Epic Games, Inc. All Rights Reserved.

#include "SeasonItem/FortControllerComponent_SeasonItem.h"

void UFortControllerComponent_SeasonItem::ClientSetAthenaSeasonItemMapIconState_Implementation(const FGameplayTag& ItemTag, const EAthenaSeasonMapIconState IconState)
{
}

void UFortControllerComponent_SeasonItem::ServerSetAthenaSeasonItemMapIconState_Implementation(const FGameplayTag& ItemTag, const EAthenaSeasonMapIconState IconState)
{
}
bool UFortControllerComponent_SeasonItem::ServerSetAthenaSeasonItemMapIconState_Validate(const FGameplayTag& ItemTag, const EAthenaSeasonMapIconState IconState)
{
	return true;
}
