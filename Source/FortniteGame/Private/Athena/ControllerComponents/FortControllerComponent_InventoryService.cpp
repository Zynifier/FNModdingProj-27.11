// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ControllerComponents/FortControllerComponent_InventoryService.h"
#include "Net/UnrealNetwork.h"

UCurveTable* UFortControllerComponent_InventoryService::GetDefaultCurrencyPayoutTable()
{
	return nullptr;
}

UFortResourceItemDefinition* UFortControllerComponent_InventoryService::GetDefaultGlobalCurrencyItemDefinition()
{
	return nullptr;
}

UFortControllerComponent_InventoryService* UFortControllerComponent_InventoryService::GetInventoryServiceComponent(const AFortPlayerControllerGameplay* FortPC)
{
	return nullptr;
}

void UFortControllerComponent_InventoryService::HandleOnItemCountChanged(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, UFortItemDefinition* Definition, int32 Delta)
{
}

void UFortControllerComponent_InventoryService::HandlePlacementChanged(AFortPlayerStateAthena* FortPlayerState, int32 NewPlacement)
{
}

bool UFortControllerComponent_InventoryService::IsGlobalCurrencyWidgetEnabled()
{
	return false;
}

void UFortControllerComponent_InventoryService::OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UFortControllerComponent_InventoryService::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_InventoryService, GlobalCurrencyTrackedData);
}
