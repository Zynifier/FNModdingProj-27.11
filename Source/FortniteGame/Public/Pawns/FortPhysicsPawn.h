// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/Pawn.h"
#include "Math/MathFwd.h"
#include "FortPhysicsPawn.generated.h"

class APawn;

USTRUCT()
struct FReplicatedPhysicsPawnState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantize100 Translation;

	UPROPERTY()
	FQuat Rotation;

	UPROPERTY()
	FVector_NetQuantize10 LinearVelocity;

	UPROPERTY()
	FVector_NetQuantize10 AngularVelocity;

	UPROPERTY()
	uint16 SyncKey;

};

USTRUCT()
struct FVehicleSafeTeleportInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FRotator Rotation;

};

UCLASS(MinimalAPI, HideCategories=("Navigation"))
class AFortPhysicsPawn : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Unreliable)
	FORTNITEGAME_API void ClientAckGoodMove(uint32 MoveId);

	UFUNCTION(NetMulticast, Reliable)
	FORTNITEGAME_API void ClientBroadcastHitDetection(APawn* ImpulseInstigator, float Radius, float Relevancy, const FVector HalfPoints, const FVector DoublePoints);

	UFUNCTION(Server, Unreliable)
	FORTNITEGAME_API void ServerMove(const FReplicatedPhysicsPawnState& InState);

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerMoveReliable(const FReplicatedPhysicsPawnState& InState);

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerUpdateStateSync(const TArray<uint8>& StateSyncData);

protected:
	UPROPERTY(Transient, ReplicatedUsing=OnRep_SafeTeleportInfo)
	FVehicleSafeTeleportInfo SafeTeleportInfo;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_GravityMultiplier)
	float GravityMultiplier;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Networking")
	uint8 bUseNetPrediction : 1;

private:
	UFUNCTION()
	FORTNITEGAME_API void OnRep_GravityMultiplier();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_SafeTeleportInfo();

};

