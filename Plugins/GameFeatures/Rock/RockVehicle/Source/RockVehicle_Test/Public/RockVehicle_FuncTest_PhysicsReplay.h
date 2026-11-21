// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "RockVehicle_FuncTest_PhysicsReplay.generated.h"

class URockVehicle_PhysicsReplay;
class URockVehicle_PhysicsReplaySession;
class URockVehicle_ReplicatedTestComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Input", "Rendering"))
class ARockVehicle_FuncTest_PhysicsReplay : public AFunctionalTest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="RockVehicle_FuncTest_PhysicsReplay")
	FString TestFileNameContains;

	UPROPERTY(Transient)
	TObjectPtr<URockVehicle_PhysicsReplay> CurrentUe3Replay;

	UPROPERTY(Transient)
	TObjectPtr<URockVehicle_PhysicsReplay> CurrentFNReplay;

	UPROPERTY(Transient)
	TObjectPtr<URockVehicle_PhysicsReplaySession> ReplaySession;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URockVehicle_ReplicatedTestComponent> CurrentTestComponent;

};

