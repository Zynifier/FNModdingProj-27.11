// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RockVehicle_PhysicsLog.h"
#include "RockVehicle_PhysicsSession.generated.h"

class AActor;
class URockVehicle_PhysicsLog;
class URockVehicle_PhysicsReplayTrack;

UCLASS()
class URockVehicle_PhysicsClientReplaySession : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<URockVehicle_PhysicsReplayTrack> Track;

	UPROPERTY()
	FRockVehicle_PhysicsErrorLog ErrorLog;

	UPROPERTY()
	int32 CurrentFrame;

	UPROPERTY()
	float StartedGameTime;

	UPROPERTY()
	float LastGameTime;

};

UCLASS()
class URockVehicle_PhysicsReplaySession : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<URockVehicle_PhysicsReplayTrack>> Tracks;

	UPROPERTY()
	int32 CurrentFrame;

	UPROPERTY()
	float StartedGameTime;

};

UCLASS()
class URockVehicle_PhysicsReplayTrack : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> Actor;

	UPROPERTY()
	TObjectPtr<AActor> Shadow;

	UPROPERTY()
	TObjectPtr<URockVehicle_PhysicsLog> RecordLog;

	UPROPERTY()
	TObjectPtr<URockVehicle_PhysicsLog> PlaybackLog;

};

