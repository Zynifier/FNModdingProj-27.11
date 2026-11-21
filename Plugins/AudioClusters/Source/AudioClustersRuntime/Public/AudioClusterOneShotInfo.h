// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "AudioClusterOneShotInfo.generated.h"

USTRUCT(BlueprintType)
struct AUDIOCLUSTERSRUNTIME_API FAudioClusterOneShotInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="AudioClusterOneShotInfo")
	FGameplayTag Tag;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AudioClusterOneShotInfo")
	FVector Position;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AudioClusterOneShotInfo")
	float LifetimeSeconds;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AudioClusterOneShotInfo")
	float TimeRemainingSeconds;

};

