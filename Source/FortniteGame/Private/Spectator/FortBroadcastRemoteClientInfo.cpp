// Copyright Epic Games, Inc. All Rights Reserved.

#include "Spectator/FortBroadcastRemoteClientInfo.h"
#include "Net/UnrealNetwork.h"

void AFortBroadcastRemoteClientInfo::ClientRemotePlayerAddMapMarker_Implementation(FFortWorldMarkerData InMarkerData)
{
}

void AFortBroadcastRemoteClientInfo::ClientRemotePlayerDamagedResourceBuilding_Implementation(ABuildingSMActor* BuildingSMActor, EFortResourceType::Type PotentialResourceType, int32 PotentialResourceCount, bool bDestroyed, bool bJustHitWeakspot)
{
}

void AFortBroadcastRemoteClientInfo::ClientRemotePlayerHitMarkers_Implementation(const TArray<FScreenSpaceHitLocation>& ScreenSpaceHitLocations)
{
}

void AFortBroadcastRemoteClientInfo::ClientRemotePlayerRemoveMapMarker_Implementation(FMarkerID MarkerID)
{
}

void AFortBroadcastRemoteClientInfo::OnPlayerFullScreenMapActiveChanged(bool bFullscreenMapActive)
{
}

void AFortBroadcastRemoteClientInfo::OnRep_bActive()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteAugments()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteBuildableClass()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteBuildingClockwiseRotation()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteBuildingMaterial()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteCanDBNORevive()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteChatEntry()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteEditActor()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteEditTileData()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteEventScore()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteIsFullScreenMapActive()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteIsInteracting()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteIsInventoryActive()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemotePoiTagID()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteRespawnTime()
{
}

void AFortBroadcastRemoteClientInfo::OnRep_RemoteWeakspotData()
{
}

void AFortBroadcastRemoteClientInfo::OnServerAddMapMarker(const FFortWorldMarkerData& InMarkerData)
{
}

void AFortBroadcastRemoteClientInfo::OnServerRemoveMapMarker(FMarkerID InMarkerID)
{
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerAugments_Implementation(const TArray<UFortPlayerAugmentItemDefinition*>& InAugments)
{
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerBuildableClass_Implementation(TSubclassOf<ABuildingSMActor> BuildableClass)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerBuildableClass_Validate(TSubclassOf<ABuildingSMActor> BuildableClass)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerBuildingMaterial_Implementation(EFortResourceType::Type Material)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerBuildingMaterial_Validate(EFortResourceType::Type Material)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerBuildingRotation_Implementation(bool ClockwiseRotation)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerBuildingRotation_Validate(bool ClockwiseRotation)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerCanDBNORevive_Implementation(bool bCanDBNORevive)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerCanDBNORevive_Validate(bool bCanDBNORevive)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerEditTileData_Implementation(const TArray<int32>& EditTileData)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerEditTileData_Validate(const TArray<int32>& EditTileData)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerEventScore_Implementation(int32 EventScore)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerEventScore_Validate(int32 EventScore)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerFullScreenMapActive_Implementation(bool bFullScreenMapActive)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerFullScreenMapActive_Validate(bool bFullScreenMapActive)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerHitMarkers_Implementation(const TArray<FScreenSpaceHitLocation>& ScreenSpaceHitLocations)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerHitMarkers_Validate(const TArray<FScreenSpaceHitLocation>& ScreenSpaceHitLocations)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerInteracting_Implementation(bool bInteracting)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerInteracting_Validate(bool bInteracting)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::ServerSetPlayerInventoryActive_Implementation(bool bInventorypActive)
{
}
bool AFortBroadcastRemoteClientInfo::ServerSetPlayerInventoryActive_Validate(bool bInventorypActive)
{
	return true;
}

void AFortBroadcastRemoteClientInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, bActive);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, bRemoteIsInteracting);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteEditActor);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteEditTileData);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteBuildableClass);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteBuildingMaterial);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteBuildingClockwiseRotationCounter);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, bRemoteIsFullScreenMapActive);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, bRemoteIsInventoryActive);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, bRemoteCanDBNORevive);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteChatEntry);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteWeakspotData);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteRespawnTime);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemotePoiTagID);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteEventScore);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, MarkerData);
	DOREPLIFETIME(AFortBroadcastRemoteClientInfo, RemoteAugments);
}
