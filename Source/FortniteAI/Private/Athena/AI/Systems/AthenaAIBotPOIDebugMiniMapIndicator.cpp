// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/Systems/AthenaAIBotPOIDebugMiniMapIndicator.h"
#include "Net/UnrealNetwork.h"

void UAthenaAIBotPOIDebugMiniMapIndicator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAthenaAIBotPOIDebugMiniMapIndicator, BotPOIDebugInfoList);
	DOREPLIFETIME(UAthenaAIBotPOIDebugMiniMapIndicator, BotPOIExcludedZonesDebugInfoList);
	DOREPLIFETIME(UAthenaAIBotPOIDebugMiniMapIndicator, ClusteredLootLocationsDebug);
	DOREPLIFETIME(UAthenaAIBotPOIDebugMiniMapIndicator, ClusteredLootNamesDebug);
	DOREPLIFETIME(UAthenaAIBotPOIDebugMiniMapIndicator, ClusteredLootDrawDebugLevel);
	DOREPLIFETIME(UAthenaAIBotPOIDebugMiniMapIndicator, DynamicPOIDrawDebugLevel);
}
