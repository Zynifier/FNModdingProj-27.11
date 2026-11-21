// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScoutDroneTypes.generated.h"

class AActor;
class AFortPawn;

USTRUCT(BlueprintType)
struct FScoutDroneDeferredDestructionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneDeferredDestructionData")
	float DeposessDelay;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneDeferredDestructionData")
	float DestroyDelay;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneDeferredDestructionData")
	FGameplayTag DismissalReason;

	UPROPERTY(Transient)
	float ServerDismissStartTime;

};

USTRUCT(BlueprintType)
struct FScoutDronePickupTargets
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="ScoutDronePickupTargets")
	TArray<TObjectPtr<AActor>> Items;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ScoutDronePickupTargets")
	TObjectPtr<AFortPawn> DBNOPawn;

};

