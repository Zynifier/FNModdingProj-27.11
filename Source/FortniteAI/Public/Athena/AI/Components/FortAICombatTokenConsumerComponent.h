// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortPawnComponent.h"
#include "FortAICombatTokenConsumerComponent.generated.h"

class AFortAthenaAIBotController;
class UFortAICombatTokenProviderComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortAICombatTokenConsumerComponent : public UFortPawnComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	float TokenHoldMinDuration;

	UPROPERTY(Transient)
	float TokenHoldMaxDuration;

	UPROPERTY(Transient)
	AFortAthenaAIBotController* CachedOwnerBotController;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortAICombatTokenProviderComponent> CurrentTargetTokenProvider;

	UPROPERTY(Transient)
	FGameplayTagQuery CurrentTokenTagQuery;

	UPROPERTY(Transient)
	bool bHasToken;

};

