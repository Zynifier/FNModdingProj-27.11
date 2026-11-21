// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Subsystems/WorldSubsystem.h"
#include "AudioClusterActorInfo.h"
#include "AudioClusterOneShotInfo.h"
#include "AudioClustersSubsystem.generated.h"

class UAudioClusterConfigMap;

UCLASS()
class AUDIOCLUSTERSRUNTIME_API UAudioClustersSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Audio Clusters")
	bool AddConfigMap(UAudioClusterConfigMap* Map);

	UFUNCTION(BlueprintCallable, Category="Audio Clusters")
	bool Register(const FAudioClusterActorInfo& ActorInfo);

	UFUNCTION(BlueprintCallable, Category="Audio Clusters")
	bool RegisterOneShot(const FAudioClusterOneShotInfo& OneShotInfo);

	UFUNCTION(BlueprintCallable, Category="Audio Clusters")
	bool RemoveConfigMap(UAudioClusterConfigMap* Map);

	UFUNCTION(BlueprintCallable, Category="Audio Clusters")
	void SetListenerPosition(const FVector& InListenerPosition);

	UFUNCTION(BlueprintCallable, Category="Audio Clusters")
	bool SetParam(const FGameplayTag& Tag, double Value);

	UFUNCTION(BlueprintCallable, Category="Audio Clusters")
	bool Unregister(const FAudioClusterActorInfo& ActorInfo);

	UFUNCTION(BlueprintCallable, Category="Audio Clusters")
	void UpdateClusters(float DeltaTimeSeconds);

};

