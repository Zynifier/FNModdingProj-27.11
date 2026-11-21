// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AudioClusterActorInfo.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct AUDIOCLUSTERSRUNTIME_API FAudioClusterActorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="AudioClusterActorInfo")
	TWeakObjectPtr<AActor> Actor;

	UPROPERTY(BlueprintReadWrite, Transient, Category="AudioClusterActorInfo")
	FGameplayTag Tag;

};

