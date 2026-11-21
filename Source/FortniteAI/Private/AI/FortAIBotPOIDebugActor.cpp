// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAIBotPOIDebugActor.h"
#include "Net/UnrealNetwork.h"

void AFortAIBotPOIDebugActor::OnRep_PlayerBotsDebugMiniMap(UAthenaAIBotPOIDebugMiniMapIndicator* OldPlayerBotsDebugMiniMap)
{
}

void AFortAIBotPOIDebugActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAIBotPOIDebugActor, BotPOIDebugMiniMapIndicator);
}
