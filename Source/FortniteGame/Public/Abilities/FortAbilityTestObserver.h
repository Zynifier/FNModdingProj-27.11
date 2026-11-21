// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortAbilityTestObserver.generated.h"

class APawn;
class UGameplayAbility;

UCLASS(BlueprintType, Blueprintable)
class AFortAbilityTestObserver : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Test")
	void StartObserving(APawn* Pawn);

	UFUNCTION(BlueprintCallable, Category="Test")
	void StopObserving();

	UFUNCTION(BlueprintPure, Category="Test")
	bool WasAbilityActivated(UGameplayAbility* Ability) const;

	UFUNCTION(BlueprintPure, Category="Test")
	bool WasAbilityTagActivated(const FGameplayTag& AbilityTag) const;

};

