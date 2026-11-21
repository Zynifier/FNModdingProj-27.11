// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InfiltrationStatusComponent.generated.h"

class AFortAthenaMutator_Infiltration;
class AFortPlayerControllerAthena;
enum class EIntelStateEnum : uint8;

UCLASS(HideCategories=("Object", "LOD", "Physics", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Collision"), ClassGroup=("Fortnite"), meta=(BlueprintSpawnableComponent))
class UInfiltrationStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGroundTimerChanged, float, NewTimeRemaining);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIntelStateChanged, EIntelStateEnum, CurrentState);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIsCurrentlyDefendedChanged, bool, bInRange);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMutatorReady);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRoundResetEvent);

public:
	UFUNCTION(BlueprintPure)
	uint8 GetAttackingTeam() const;

	UFUNCTION(BlueprintPure)
	EIntelStateEnum GetCurrentIntelState() const;

	UFUNCTION(BlueprintPure)
	uint8 GetDefendingTeam() const;

	UFUNCTION(BlueprintPure)
	float GetGroundTimeRemaining() const;

	UFUNCTION(BlueprintPure)
	bool GetIsCurrentlyDefended() const;

	UFUNCTION(BlueprintPure)
	bool IsBeingHeldByLocalPlayer(AFortPlayerControllerAthena* LocalPlayer) const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerAttacking(AFortPlayerControllerAthena* LocalPlayer) const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerDefending(AFortPlayerControllerAthena* LocalPlayer) const;

	UFUNCTION()
	void OnRoundReset();

	UFUNCTION(BlueprintCallable)
	void TryExecuteMutatorReady();

	UPROPERTY(BlueprintAssignable)
	FOnIntelStateChanged OnIntelStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnIsCurrentlyDefendedChanged OnIsCurrentlyDefendedChanged;

	UPROPERTY(BlueprintAssignable)
	FOnGroundTimerChanged OnGroundTimerChanged;

	UPROPERTY(BlueprintAssignable)
	FOnRoundResetEvent OnRoundResetEvent;

	UPROPERTY(BlueprintAssignable)
	FOnMutatorReady OnMutatorReadyEvent;

protected:
	UFUNCTION()
	void OnRep_CachedMutator();

	UPROPERTY(ReplicatedUsing=OnRep_CachedMutator)
	TWeakObjectPtr<AFortAthenaMutator_Infiltration> CachedMutator;

};

