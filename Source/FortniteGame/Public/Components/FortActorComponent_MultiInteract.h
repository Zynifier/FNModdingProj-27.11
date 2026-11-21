// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "ScalableFloat.h"
#include "FortActorComponent_MultiInteract.generated.h"

class AActor;
class AFortPlayerStateAthena;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMultiInteractActorCountChangedDelegate, int32, InteractingActorCount, float, MultiInteractMultiplier, float, InteractingDuration);

USTRUCT()
struct FMultiInteractServerTimeData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Time;

	UPROPERTY()
	uint8 Id;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortActorComponent_MultiInteract : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortActorComponent_MultiInteract(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddInteractingActor(AActor* InteractingActorToAdd);

	UFUNCTION(BlueprintPure)
	int32 GetInteractingActorCount(const bool bIncludePlayers = true, const bool bIncludeNonPlayers = true) const;

	UFUNCTION(BlueprintPure)
	float GetInteractionDuration() const;

	UFUNCTION(BlueprintPure)
	float GetMultiplier() const;

	UFUNCTION(BlueprintPure)
	float GetServerInteractionDuration() const;

	UFUNCTION()
	void HandleInteractingActorDestroyed(AActor* DestroyedActor);

	UFUNCTION(BlueprintPure)
	bool HasMaxInteractingActors() const;

	UFUNCTION(BlueprintPure)
	bool IsMultipleInteractionEnabled() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveInteractingActor(AActor* InteractingActorToRemove);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateForPlayerJustJoinedInteraction(const AFortPlayerStateAthena* JoinedPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateForPlayerJustLeftInteraction(const AFortPlayerStateAthena* LeftPlayer);

	UPROPERTY(BlueprintAssignable)
	FOnMultiInteractActorCountChangedDelegate ActorCountChangedDelegate;

protected:
	UFUNCTION()
	void OnRep_InteractingNonPlayerActorCount();

	UFUNCTION()
	void OnRep_InteractingPlayers();

	UFUNCTION()
	void OnRep_ServerInteractionData();

	UPROPERTY(Transient)
	int32 InteractingPlayerCount;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerInteractionData)
	FMultiInteractServerTimeData ServerInteractionData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="MultiInteract")
	bool bOnlyUpdateForLocalInteractingPlayer;

	UPROPERTY(EditDefaultsOnly, Category="MultiInteract")
	FScalableFloat MultiInteractMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="MultiInteract")
	FScalableFloat MaxInteractingActorCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="MultiInteract")
	FScalableFloat GradualCounterMultiplier;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_InteractingPlayers)
	TArray<TObjectPtr<AFortPlayerStateAthena>> InteractingPlayers;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> InteractingNonPlayerActors;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_InteractingNonPlayerActorCount)
	int32 InteractingNonPlayerActorCount;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerStateAthena>> PreviousInteractingPlayers;

};

