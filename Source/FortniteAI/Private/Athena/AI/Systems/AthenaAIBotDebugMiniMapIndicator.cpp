// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/Systems/AthenaAIBotDebugMiniMapIndicator.h"
#include "Net/UnrealNetwork.h"

void UAthenaAIBotDebugMiniMapIndicator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAthenaAIBotDebugMiniMapIndicator, BotDebugInfoList);
	DOREPLIFETIME(UAthenaAIBotDebugMiniMapIndicator, DebugMinimapIconBrush);
}
