// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_MedicPack.generated.h"

enum class EMedicPackState : uint8;

UENUM(BlueprintType)
enum class EMedicPackState : uint8
{
	Idle = 0,
	Active = 1,
	None = 2,
};

UCLASS()
class UFortGameplayAbility_MedicPack : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MedicPack")
	void HandleCurrentStateChanged(EMedicPackState InPreviousState);

	UFUNCTION(BlueprintNativeEvent, Category="MedicPack")
	void OnAbilityCanceled();

	UFUNCTION(BlueprintNativeEvent, Category="MedicPack")
	void OnCurrentStateChanged(EMedicPackState InPreviousState, EMedicPackState InCurrentState);

	UFUNCTION(BlueprintNativeEvent, Category="MedicPack")
	void OnFuelIsEmpty();

	UFUNCTION(BlueprintNativeEvent, Category="MedicPack")
	void OnFuelIsFull();

	UFUNCTION(BlueprintCallable, Category="MedicPack")
	void SetCurrentState(EMedicPackState InState);

protected:
	UPROPERTY(ReplicatedUsing=OnRep_ServerCurrentState)
	EMedicPackState ServerCurrentState;

	UPROPERTY(BlueprintReadOnly, Category="MedicPack")
	EMedicPackState CurrentState;

	UPROPERTY(Transient)
	float DelayRegenStartTime;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_bAbilityMarkedForPendingKill, Category="MedicPack")
	bool bAbilityMarkedForPendingKill;

private:
	UFUNCTION()
	void OnRep_bAbilityMarkedForPendingKill();

	UFUNCTION()
	void OnRep_ServerCurrentState(EMedicPackState PreviousState);

};

