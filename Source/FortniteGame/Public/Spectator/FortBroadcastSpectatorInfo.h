// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "FortBroadcastSpectatorInfo.generated.h"

class AFortBroadcastRemoteClientInfo;
class AFortInventory;
class AFortPlayerStateAthena;
class AFortTeamPrivateInfo;

USTRUCT()
struct FFortBroadcastInfoPerPlayer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY()
	TObjectPtr<AFortInventory> PlayerInventory;

	UPROPERTY()
	TObjectPtr<AFortBroadcastRemoteClientInfo> PlayerClientInfo;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortBroadcastSpectatorInfo : public AInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(ReplicatedUsing=OnRep_TotalNumPlayers)
	int32 TotalNumPlayers;

	UPROPERTY(ReplicatedUsing=OnRep_TotalNumTeams)
	int32 TotalNumTeams;

private:
	UFUNCTION()
	void HandleTeamInfosSet();

	UFUNCTION()
	void OnRep_PerPlayerInfo();

	UFUNCTION()
	void OnRep_TotalNumPlayers();

	UFUNCTION()
	void OnRep_TotalNumTeams();

	UPROPERTY(Replicated)
	TArray<TObjectPtr<AFortTeamPrivateInfo>> TeamPrivateInfos;

	UPROPERTY(ReplicatedUsing=OnRep_PerPlayerInfo)
	TArray<FFortBroadcastInfoPerPlayer> PerPlayerInfo;

};

