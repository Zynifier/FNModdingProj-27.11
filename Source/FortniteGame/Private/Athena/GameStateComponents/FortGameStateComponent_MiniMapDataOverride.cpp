// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/GameStateComponents/FortGameStateComponent_MiniMapDataOverride.h"
#include "Net/UnrealNetwork.h"

UFortGameStateComponent_MiniMapDataOverride::UFortGameStateComponent_MiniMapDataOverride(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const FGameplayTagContainer UFortGameStateComponent_MiniMapDataOverride::GetContextTagsForLocationTag(const FGameplayTag LocationTag) const
{
	return FGameplayTagContainer();
}

void UFortGameStateComponent_MiniMapDataOverride::OnRep_MiniMapDataOverridesRepDatas()
{
}

void UFortGameStateComponent_MiniMapDataOverride::OverrideLocations(const FGameplayTagContainer& ContextTags, const FGameplayTagContainer& LocationTags)
{
}

void UFortGameStateComponent_MiniMapDataOverride::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_MiniMapDataOverride, MiniMapDataOverrideRepDatas);
}
