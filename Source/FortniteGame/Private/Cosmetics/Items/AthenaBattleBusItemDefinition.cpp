// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/AthenaBattleBusItemDefinition.h"

TSoftClassPtr<ABattleBusCosmeticInstanceBase> UAthenaBattleBusItemDefinition::GetBusPrefabClass() const
{
	return TSoftClassPtr<ABattleBusCosmeticInstanceBase>();
}

USoundBase* UAthenaBattleBusItemDefinition::GetFlightLoopingMusic() const
{
	return nullptr;
}

USoundBase* UAthenaBattleBusItemDefinition::GetFlightLoopingSound() const
{
	return nullptr;
}

USoundBase* UAthenaBattleBusItemDefinition::GetIgnitionSound() const
{
	return nullptr;
}

USoundBase* UAthenaBattleBusItemDefinition::GetLobbyLoopingMusic() const
{
	return nullptr;
}

USoundBase* UAthenaBattleBusItemDefinition::GetLobbyLoopingSound() const
{
	return nullptr;
}
