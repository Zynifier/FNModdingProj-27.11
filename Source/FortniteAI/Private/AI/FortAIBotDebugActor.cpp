// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAIBotDebugActor.h"
#include "Net/UnrealNetwork.h"

void AFortAIBotDebugActor::OnRep_BotDebugMiniMapIndicator(UAthenaAIBotDebugMiniMapIndicator* OldBotDebugMiniMap)
{
}

void AFortAIBotDebugActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAIBotDebugActor, BotDebugMiniMapIndicator);
}
