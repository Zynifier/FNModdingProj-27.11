// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "AthenaResurrectionComponent.generated.h"

class ABuildingGameplayActorCloneMachine;
class ABuildingGameplayActorSpawnMachine;
class AFortPlayerStart;
class USoundCue;

USTRUCT()
struct FCloneMachineRepData
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	TObjectPtr<ABuildingGameplayActorCloneMachine> CloneMachine;

	UPROPERTY()
	FVector Location;

};

UCLASS(MinimalAPI, HideCategories=("Trigger"))
class UAthenaResurrectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Unreliable)
	void ClientNotifyCloneMachineUnderAttack(const USoundCue* DamageSound);

	UFUNCTION(Client, Unreliable)
	void ClientNotifyCloneMchineDestroyed(const USoundCue* DestroyedSound);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerOnBeginResurrectionInteraction(ABuildingGameplayActorSpawnMachine* SpawnMachine);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerOnInterruptResurrectionInteraction(ABuildingGameplayActorSpawnMachine* SpawnMachine);

protected:
	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayerIdsForResurrection)
	TArray<FUniqueNetIdRepl> PlayerIdsForResurrection;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerStart> ResurrectionLocation;

	UPROPERTY(Replicated)
	FCloneMachineRepData CloneMachineRepData;

	UPROPERTY(Transient)
	float NotifyPlayerDamageThrottle;

private:
	UFUNCTION()
	void OnRep_PlayerIdsForResurrection();

	UFUNCTION()
	void OnTeamChanged(uint8 OldTeam);

	UFUNCTION()
	void UpdatePlayerIdsForResurrectionForNewTeam();

	UPROPERTY(Transient)
	FMarkerID ResurrectionMachineMarkerID;

	UPROPERTY(Transient)
	int32 ClosestSpawnMachineIndex;

	UPROPERTY(Transient)
	bool bActiveBeingRebooted;

};

