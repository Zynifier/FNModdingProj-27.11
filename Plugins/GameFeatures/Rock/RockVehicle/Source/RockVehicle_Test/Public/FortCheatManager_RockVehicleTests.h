// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_RockVehicleTests.generated.h"

class URockVehicle_PhysicsReplay;
class URockVehicle_PhysicsReplaySession;
class URockVehicle_ReplicatedTestComponent;

UCLASS()
class UFortCheatManager_RockVehicleTests : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, Category="RockVehicleTests")
	void RockVehiclePhysicsReplayPlay(const FString& FileName);

	UFUNCTION(Exec, Category="RockVehicleTests")
	void RockVehiclePhysicsTest(const FString& TestName);

private:
	UPROPERTY(Transient)
	TArray<FString> TestFiles;

	UPROPERTY(Transient)
	TObjectPtr<URockVehicle_PhysicsReplay> CurrentUe3Replay;

	UPROPERTY(Transient)
	TObjectPtr<URockVehicle_PhysicsReplay> CurrentFNReplay;

	UPROPERTY(Transient)
	TObjectPtr<URockVehicle_PhysicsReplaySession> ReplaySession;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URockVehicle_ReplicatedTestComponent> CurrentTestComponent;

};

