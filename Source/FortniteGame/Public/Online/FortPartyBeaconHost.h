// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PartyBeaconHost.h"
#include "FortPartyBeaconHost.generated.h"

UENUM()
enum class EServerInitializationState : uint8
{
	UNINITIALIZED = 0,
	STARTING_UP = 1,
	READY_FOR_PLAYERS = 2,
};

USTRUCT()
struct FPlayerSquadMapping
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PlaylistName;

	UPROPERTY()
	FString PlayerID;

	UPROPERTY()
	FString CustomMatchKey;

	UPROPERTY()
	uint32 TeamId;

	UPROPERTY()
	uint32 PartyId;

	UPROPERTY()
	int32 SeatId;

};

UCLASS()
class AFortPartyBeaconHost : public APartyBeaconHost
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TArray<FPlayerSquadMapping> PlayerSquadMapping;

	UPROPERTY(Config)
	bool bUseSquadMappingOverride;

	UPROPERTY(Config)
	TArray<FString> RegionsToUseSquadOverrides;

};

