// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "FortScoutDroneAnalyticsComponent.generated.h"

UCLASS(Abstract, HideCategories=("Trigger", "PhysicsVolume"))
class UFortScoutDroneAnalyticsComponent : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	float SessionStartTime;

	UPROPERTY(Transient)
	float SessionLength;

	UPROPERTY(EditDefaultsOnly, Category="Analytics Settings")
	FScalableFloat MinSessionLength;

	UPROPERTY(Transient)
	float DistanceTraveled;

	UPROPERTY(Transient)
	int32 NumberOfContainersInteractedWith;

	UPROPERTY(Transient)
	FGameplayTag DismissalReason;

	UPROPERTY(Transient)
	int32 NumberOfItemsPickedUp;

	UPROPERTY(Transient)
	TArray<FString> DBNOCarriedPlayers;

	UPROPERTY(Transient)
	int32 NumberOfEnemiesPassivelyMarked;

	UPROPERTY(Transient)
	int32 NumberOfEnemiesMarkedOnCaw;

	UPROPERTY(Transient)
	int32 NumberOfCaws;

	UPROPERTY(EditDefaultsOnly, Category="Distance Tracking")
	FScalableFloat DistanceTraveledUpdateInterval;

	UPROPERTY(Transient)
	FTimerHandle DistanceTraveledUpdateTimerHandle;

	UPROPERTY(Transient)
	FVector LastRecorderDroneLocation;

};

