// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortAthenaMutator_Knockback.h"
#include "FortGameplayAbility_KnockbackMutator.generated.h"

class AFortAthenaMutator_Knockback;

UCLASS()
class KNOCKBACKRUNTIME_API UFortGameplayAbility_KnockbackMutator : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	AFortAthenaMutator_Knockback* GetCachedMutator();

	UFUNCTION(BlueprintCallable)
	void SaveKnockbackData(const FKnockbackMutatorData& InKnockbackData);

	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_Knockback> CachedMutator;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameplayAbility_KnockbackMutator")
	TSubclassOf<AFortAthenaMutator_Knockback> MutatorClassToGet;

};

