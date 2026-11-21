// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/CreativeRegisteredPlayersInterface.h"

void ICreativeRegisteredPlayersInterface::OnAllPlayersUnregistered()
{
}

void ICreativeRegisteredPlayersInterface::OnMinigameEnded()
{
}

void ICreativeRegisteredPlayersInterface::OnMinigameStarted()
{
}

void ICreativeRegisteredPlayersInterface::OnPlayerAdded(FUniqueNetIdRepl NetId, bool bIsLocalPlayer)
{
}

void ICreativeRegisteredPlayersInterface::OnPlayerRegistered(const AFortPlayerState* PlayerState)
{
}

void ICreativeRegisteredPlayersInterface::OnPlayerRemoved(FUniqueNetIdRepl NetId, bool bIsLocalPlayer)
{
}

void ICreativeRegisteredPlayersInterface::OnPlayerUnregistered(const AFortPlayerState* PlayerState)
{
}
