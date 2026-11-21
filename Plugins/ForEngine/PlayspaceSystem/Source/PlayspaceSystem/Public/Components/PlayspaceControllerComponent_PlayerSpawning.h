// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "Math/MathFwd.h"
#include "PlayspaceControllerComponent_PlayerSpawning.generated.h"

class ACameraActor;
class APlayerController;

USTRUCT(BlueprintType)
struct PLAYSPACESYSTEM_API FReplicatedSpawnInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Spawn Info")
	FVector SpawnLocation;

	UPROPERTY(BlueprintReadOnly, Category="Spawn Info")
	FRotator SpawnRotation;

	UPROPERTY(BlueprintReadOnly, Category="Spawn Info")
	float ServerSpawnTime;

	UPROPERTY(BlueprintReadOnly, Category="Spawn Info")
	FVector LastLocation;

	UPROPERTY(BlueprintReadOnly, Category="Spawn Info")
	float MinTimeForCameraFadeTransition;

	UPROPERTY(BlueprintReadOnly, Category="Spawn Info")
	bool bIsPlayerRespawning;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerQueuedToSpawn, APlayerController*, Controller, const FReplicatedSpawnInfo&, SpawnInfo);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class PLAYSPACESYSTEM_API UPlayspaceControllerComponent_PlayerSpawning : public UControllerComponent
{
	GENERATED_BODY()

public:
	UPlayspaceControllerComponent_PlayerSpawning(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, Category="Player Spawning Component")
	const FReplicatedSpawnInfo& GetSpawnInfo() const;

protected:
	UPROPERTY(BlueprintAssignable)
	FOnPlayerQueuedToSpawn OnPlayerQueuedToSpawn;

	UPROPERTY(Transient)
	TObjectPtr<ACameraActor> SpawnCameraActor;

private:
	UFUNCTION(Client, Reliable)
	void ClientReplicatedSpawnInfo(const FReplicatedSpawnInfo& InReplicatedSpawnInfo);

	UFUNCTION()
	void OnRep_ReplicatedSpawnInfo();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerMarkReadyForSpawning();

	UPROPERTY(Transient)
	bool bClientReadyForSpawning;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedSpawnInfo)
	FReplicatedSpawnInfo ReplicatedSpawnInfo;

};

