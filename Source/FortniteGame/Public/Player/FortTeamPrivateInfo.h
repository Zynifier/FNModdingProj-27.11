// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/Info.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Athena/FortPlayerStateAthena.h"
#include "FortTeamPrivateInfo.generated.h"

class AFortPlayerStateAthena;
class AFortTeamInfo;

USTRUCT()
struct FLatentRepPlayerData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY(NotReplicated)
	float LastPawnNotRelevantTime;

	UPROPERTY(NotReplicated)
	bool bPawnIsRelevant;

	UPROPERTY(NotReplicated)
	bool bWasPawnRelevantLastUpdate;

private:
	UPROPERTY(NotReplicated)
	FVector CurrentLocation;

	UPROPERTY(NotReplicated)
	float CurrentYaw;

	UPROPERTY(NotReplicated)
	float LastLocationReplicationTime;

	UPROPERTY(NotReplicated)
	float PrevLocationReplicatedTime;

	UPROPERTY()
	FVector_NetQuantize100 LastRepLocation;

	UPROPERTY(NotReplicated)
	FVector_NetQuantize100 PrevRepLocation;

	UPROPERTY(NotReplicated)
	FVector LerpStartLocation;

	UPROPERTY(NotReplicated)
	float LastYawReplicationTime;

	UPROPERTY(NotReplicated)
	float PrevYawReplicatedTime;

	UPROPERTY()
	float LastRepYaw;

	UPROPERTY(NotReplicated)
	float PrevRepYaw;

	UPROPERTY(NotReplicated)
	float LerpStartYaw;

	UPROPERTY()
	EFortPawnState PawnStateMask;

	UPROPERTY(NotReplicated)
	EFortPawnState CurrPawnStateMask;

	UPROPERTY()
	uint16 CurieStateBitfield;

};

USTRUCT()
struct FLatentRepTeamDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FLatentRepPlayerData> PlayerData;

	UPROPERTY(NotReplicated)
	int32 CurrPlayerUpdateIndex;

};

USTRUCT()
struct FPrivateTeamDataItem : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Value;

	UPROPERTY()
	FUniqueNetIdRepl PlayerId;

};

USTRUCT()
struct FPrivateTeamDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FPrivateTeamDataItem> Items;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortTeamPrivateInfo : public AInfo
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnRep_RepData();

	UPROPERTY(Transient)
	TObjectPtr<AFortTeamInfo> TeamInfo;

	UPROPERTY(ReplicatedUsing=OnRep_RepData)
	FPrivateTeamDataArray RepData;

	UPROPERTY(Replicated)
	FLatentRepTeamDataArray LatentTeamRepData;

	UPROPERTY(Transient, Replicated)
	uint16 AverageDamageDealt;

};

