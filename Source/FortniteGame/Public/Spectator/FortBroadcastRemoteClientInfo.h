// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Athena/AthenaQuickChatActiveEntry.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "Building/BuildingTypes.h"
#include "Building/BuildingWeakSpot.h"
#include "Player/ScreenSpaceHitLocation.h"
#include "FortBroadcastRemoteClientInfo.generated.h"

class ABuildingSMActor;
class UFortPlayerAugmentItemDefinition;

UCLASS()
class AFortBroadcastRemoteClientInfo : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION(NetMulticast, Reliable)
	void ClientRemotePlayerAddMapMarker(FFortWorldMarkerData InMarkerData);

	UFUNCTION(NetMulticast, Reliable)
	void ClientRemotePlayerDamagedResourceBuilding(ABuildingSMActor* BuildingSMActor, EFortResourceType::Type PotentialResourceType, int32 PotentialResourceCount, bool bDestroyed, bool bJustHitWeakspot);

	UFUNCTION(NetMulticast, Reliable)
	void ClientRemotePlayerHitMarkers(const TArray<FScreenSpaceHitLocation>& ScreenSpaceHitLocations);

	UFUNCTION(NetMulticast, Reliable)
	void ClientRemotePlayerRemoveMapMarker(FMarkerID MarkerID);

	UFUNCTION()
	void OnPlayerFullScreenMapActiveChanged(bool bFullscreenMapActive);

	UFUNCTION()
	void OnRep_bActive();

	UFUNCTION()
	void OnRep_RemoteAugments();

	UFUNCTION()
	void OnRep_RemoteBuildableClass();

	UFUNCTION()
	void OnRep_RemoteBuildingClockwiseRotation();

	UFUNCTION()
	void OnRep_RemoteBuildingMaterial();

	UFUNCTION()
	void OnRep_RemoteCanDBNORevive();

	UFUNCTION()
	void OnRep_RemoteChatEntry();

	UFUNCTION()
	void OnRep_RemoteEditActor();

	UFUNCTION()
	void OnRep_RemoteEditTileData();

	UFUNCTION()
	void OnRep_RemoteEventScore();

	UFUNCTION()
	void OnRep_RemoteIsFullScreenMapActive();

	UFUNCTION()
	void OnRep_RemoteIsInteracting();

	UFUNCTION()
	void OnRep_RemoteIsInventoryActive();

	UFUNCTION()
	void OnRep_RemotePoiTagID();

	UFUNCTION()
	void OnRep_RemoteRespawnTime();

	UFUNCTION()
	void OnRep_RemoteWeakspotData();

	UFUNCTION()
	void OnServerAddMapMarker(const FFortWorldMarkerData& InMarkerData);

	UFUNCTION()
	void OnServerRemoveMapMarker(FMarkerID InMarkerID);

	UFUNCTION(Server, Reliable)
	void ServerSetPlayerAugments(const TArray<UFortPlayerAugmentItemDefinition*>& InAugments);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerBuildableClass(TSubclassOf<ABuildingSMActor> BuildableClass);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerBuildingMaterial(EFortResourceType::Type Material);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerBuildingRotation(bool ClockwiseRotation);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerCanDBNORevive(bool bCanDBNORevive);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerEditTileData(const TArray<int32>& EditTileData);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerEventScore(int32 EventScore);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerFullScreenMapActive(bool bFullScreenMapActive);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerHitMarkers(const TArray<FScreenSpaceHitLocation>& ScreenSpaceHitLocations);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerInteracting(bool bInteracting);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlayerInventoryActive(bool bInventorypActive);

	UPROPERTY(ReplicatedUsing=OnRep_bActive)
	bool bActive;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteIsInteracting)
	bool bRemoteIsInteracting;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteEditActor)
	TWeakObjectPtr<ABuildingSMActor> RemoteEditActor;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteEditTileData)
	TArray<int32> RemoteEditTileData;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteBuildableClass)
	TSubclassOf<ABuildingSMActor> RemoteBuildableClass;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteBuildingMaterial)
	TEnumAsByte<EFortResourceType::Type> RemoteBuildingMaterial;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteBuildingClockwiseRotation)
	int32 RemoteBuildingClockwiseRotationCounter;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteIsFullScreenMapActive)
	bool bRemoteIsFullScreenMapActive;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteIsInventoryActive)
	bool bRemoteIsInventoryActive;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteCanDBNORevive)
	bool bRemoteCanDBNORevive;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteChatEntry)
	FAthenaQuickChatActiveEntry RemoteChatEntry;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteWeakspotData)
	FBuildingWeakSpotData RemoteWeakspotData;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteRespawnTime)
	float RemoteRespawnTime;

	UPROPERTY(ReplicatedUsing=OnRep_RemotePoiTagID)
	int16 RemotePoiTagID;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteEventScore)
	int32 RemoteEventScore;

	UPROPERTY(Replicated)
	TArray<FFortWorldMarkerData> MarkerData;

	UPROPERTY(ReplicatedUsing=OnRep_RemoteAugments)
	TArray<UFortPlayerAugmentItemDefinition*> RemoteAugments;

};

