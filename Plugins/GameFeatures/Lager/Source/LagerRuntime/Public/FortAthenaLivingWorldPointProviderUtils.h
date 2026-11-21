// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "ScalableFloat.h"
#include "FortAthenaLivingWorldPointProviderUtils.generated.h"

UENUM()
enum class ELivingWorldPointProviderSpawnLimiterBehavior : uint8
{
	/** The point provider will only allow MaxNumberOfSpawn to happen before disabling itself for the whole game.*/
	Lifetime = 0,
	/** The point provider will disable itself if the MaxNumberOfSpawn is reached. It will reenable itself when the number returns below the max. */
	Concurrent = 1,
};

USTRUCT()
struct FFortAthenaLivingWorldPointProviderSpawnLimiter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldPointProviderSpawnLimiter", meta=(AllowPrivateAccess="true"))
	ELivingWorldPointProviderSpawnLimiterBehavior Behavior;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldPointProviderSpawnLimiter", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxNumberOfSpawn;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldPointProviderSpawnLimiter", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxNumberOfEventInstance;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldPointProviderSpawnLimiter", meta=(AllowPrivateAccess="true", EditCondition="Behavior == ELivingWorldPointProviderSpawnLimiterBehavior::Lifetime", EditConditionHides))
	bool bResetLimitWhenEnabling;

};

USTRUCT()
struct FPointProviderTagDebugColor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PointProviderTagDebugColor")
	FGameplayTagContainer Tags;

	UPROPERTY(EditAnywhere, Category="PointProviderTagDebugColor")
	FColor Color;

};

