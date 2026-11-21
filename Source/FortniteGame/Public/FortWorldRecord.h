// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGenericRecord.h"
#include "Items/FortCloudSaveItemDefinition.h"
#include "Items/FortPersistentTypes.h"
#include "FortWorldRecord.generated.h"

USTRUCT()
struct FPlayerStatsRecord
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortReplicatedStat"))
	int32 Stats[35];

};

USTRUCT()
struct FStatRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName StatName;

	UPROPERTY()
	int32 StatValue;

};

USTRUCT()
struct FStatManagerPeriodRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FStatRecord> StatRecords;

};

USTRUCT()
struct FFortPlayerRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString DisplayName;

	UPROPERTY()
	FString UniqueId;

	UPROPERTY()
	TArray<uint8> BackpackData;

	UPROPERTY()
	bool bPlayerIsNew;

	UPROPERTY()
	FPlayerStatsRecord PlayerStatsData;

	UPROPERTY()
	FStatManagerPeriodRecord CampaignPeriodRecord;

};

UCLASS()
class UFortWorldRecord : public UFortGenericRecord
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FFortCloudSaveInfo CloudInfo;

	UPROPERTY(Transient)
	int32 CurrentZoneIndex;

	UPROPERTY(Transient)
	TArray<FFortPlayerRecord> SavedPlayers;

	UPROPERTY(Transient)
	FFortZoneInstanceDetails ZoneInstanceInfo;

protected:
	UPROPERTY()
	FString WUID;

};

