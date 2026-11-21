// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayAbilitySpecHandle.h"
#include "FortAdvancedMeleeComponent.generated.h"

class UFortGameplayAbility;

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAdvancedMeleeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated)
	TArray<FGameplayAbilitySpecHandle> FightListHandles;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Melee Attack")
	float AttackRangePrimary;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Melee Attack")
	float AttackRangeJab;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Melee Attack")
	float AttackRangeSpin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Melee Attack")
	float AttackRangeSecondary;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TSoftClassPtr<UFortGameplayAbility> PrimarySwing;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TSoftClassPtr<UFortGameplayAbility> JabSwing;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TSoftClassPtr<UFortGameplayAbility> SpinSwing;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TSoftClassPtr<UFortGameplayAbility> SecondarySwing;

};

