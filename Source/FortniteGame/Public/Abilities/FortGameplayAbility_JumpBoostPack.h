// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_JumpBoostPack.generated.h"

enum class EJumpBoostPackState : uint8;

UENUM(BlueprintType)
enum class EJumpBoostPackState : uint8
{
	Idle = 0,
	Boost = 1,
	Hovering = 2,
	Falling = 3,
	None = 4,
};

UCLASS(MinimalAPI)
class UFortGameplayAbility_JumpBoostPack : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="JumpBoostPack")
	void HandleCurrentStateChanged(EJumpBoostPackState InPreviousState);

	UFUNCTION(BlueprintNativeEvent, Category="JumpBoostPack")
	void OnAbilityCanceled();

	UFUNCTION(BlueprintNativeEvent, Category="JumpBoostPack")
	void OnCurrentStateChanged(EJumpBoostPackState InPreviousState, EJumpBoostPackState InCurrentState);

	UFUNCTION(BlueprintNativeEvent, Category="JumpBoostPack")
	void OnFuelIsEmpty();

	UFUNCTION(BlueprintNativeEvent, Category="JumpBoostPack")
	void OnFuelIsFull();

	UFUNCTION(BlueprintCallable, Category="JumpBoostPack")
	void SetCurrentState(EJumpBoostPackState InState);

protected:
	UPROPERTY(ReplicatedUsing=OnRep_ServerCurrentState)
	EJumpBoostPackState ServerCurrentState;

	UPROPERTY(BlueprintReadOnly, Category="JumpBoostPack")
	EJumpBoostPackState CurrentState;

	UPROPERTY(Transient)
	float DelayRegenStartTime;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_bAbilityMarkedForPendingKill, Category="JumpBoostPack")
	bool bAbilityMarkedForPendingKill;

private:
	UFUNCTION()
	void OnRep_bAbilityMarkedForPendingKill();

	UFUNCTION()
	void OnRep_ServerCurrentState(EJumpBoostPackState PreviousState);

};

