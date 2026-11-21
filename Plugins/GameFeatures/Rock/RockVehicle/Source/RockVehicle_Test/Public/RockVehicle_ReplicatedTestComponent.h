// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RockVehicle_PhysicsLog.h"
#include "RockVehicle_ReplicatedTestComponent.generated.h"

class URockVehicle_PhysicsClientReplaySession;
class URockVehicle_PhysicsReplay;

UCLASS()
class URockVehicle_ReplicatedTestComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable)
	void NotifyTestComplete(FRockVehicle_PhysicsErrorLog ErrorLog);

	UFUNCTION(Client, Reliable)
	void RunTest(const FString& InName, int32 InTrackIdx);

	UPROPERTY(Transient)
	FString FileName;

	UPROPERTY(Transient)
	int32 TrackIdx;

	UPROPERTY(Transient)
	TObjectPtr<URockVehicle_PhysicsClientReplaySession> ClientReplaySession;

	UPROPERTY(Transient)
	TObjectPtr<URockVehicle_PhysicsReplay> ClientFNReplay;

};

