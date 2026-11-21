// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortScoutDroneEvents.generated.h"

class AActor;
class AFortScoutDrone;

USTRUCT(BlueprintType)
struct FOnFortScoutDroneDeployed
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="OnFortScoutDroneDeployed")
	TWeakObjectPtr<AFortScoutDrone> DeployedDrone;

};

USTRUCT(BlueprintType)
struct FOnFortScoutDroneDismissed
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="OnFortScoutDroneDismissed")
	FGameplayTag DismissalReason;

};

USTRUCT(BlueprintType)
struct FOnFortScoutDroneFinishedLongInteract
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FOnFortScoutDroneMarkedEnemies
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="OnFortScoutDroneMarkedEnemies")
	FGameplayTag Source;

	UPROPERTY(BlueprintReadWrite, Category="OnFortScoutDroneMarkedEnemies")
	TArray<TObjectPtr<AActor>> MarkedActors;

};

