// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "RockVehicle_PhysicsLog.generated.h"

class URockVehicle_PhysicsLog;

USTRUCT()
struct FRockVehicle_PhysicsReplayRigidBodyState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FQuat Rotation;

	UPROPERTY()
	FVector LinearVelocity;

	UPROPERTY()
	FVector AngularVelocity;

};

USTRUCT()
struct FRockVehicle_PhysicsErrorLog
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FRockVehicle_PhysicsReplayRigidBodyState> FrameErrors;

};

USTRUCT()
struct FRockVehicle_PhysicsReplayInputState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Throttle;

	UPROPERTY()
	float Steer;

	UPROPERTY()
	float Pitch;

	UPROPERTY()
	float Yaw;

	UPROPERTY()
	float Roll;

	UPROPERTY()
	float DodgeForward;

	UPROPERTY()
	float DodgeRight;

	UPROPERTY()
	bool bHandbrake;

	UPROPERTY()
	bool bJump;

	UPROPERTY()
	bool bActivateBoost;

	UPROPERTY()
	bool bHoldingBoost;

	UPROPERTY()
	bool bJumped;

};

USTRUCT()
struct FRockVehicle_PhysicsLogFrame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Frame;

	UPROPERTY()
	FRockVehicle_PhysicsReplayInputState Input;

	UPROPERTY()
	TArray<FString> Logs;

	UPROPERTY()
	FRockVehicle_PhysicsReplayRigidBodyState PostFrameRBState;

	UPROPERTY()
	FRockVehicle_PhysicsReplayRigidBodyState DeltaRBState;

};

UCLASS()
class URockVehicle_PhysicsLog : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ActorArchetype;

	UPROPERTY()
	FRockVehicle_PhysicsReplayRigidBodyState InitialRBState;

	UPROPERTY()
	FName BodyName;

	UPROPERTY()
	int32 LastFrame;

	UPROPERTY()
	TArray<FRockVehicle_PhysicsLogFrame> Frames;

};

UCLASS()
class URockVehicle_PhysicsReplay : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString URL;

	UPROPERTY()
	TArray<TObjectPtr<URockVehicle_PhysicsLog>> Logs;

};

