// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_CeilingFallingTrap.generated.h"

class AFortProjectileBase;
class UGameplayEffect;

UCLASS()
class UFortGameplayAbility_CeilingFallingTrap : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ceiling Falling Trap")
	TSubclassOf<AFortProjectileBase> TrapProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ceiling Falling Trap")
	TSubclassOf<UGameplayEffect> TrapCostClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ceiling Falling Trap")
	FGameplayTag ActivateTrapTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ceiling Falling Trap")
	FGameplayTag DelayBeginTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ceiling Falling Trap")
	FGameplayTag ReloadBeginTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ceiling Falling Trap")
	float ProjectileSpawnDelay;

};

