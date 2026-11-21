// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameFeatureAction.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "GameFeatureAction_AddAudioCluster.generated.h"

class AActor;
class AFortPawn;

USTRUCT()
struct FGameFeatureAudioClusterEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Audio", meta=(Categories="Fort.Audio.Cluster"))
	FGameplayTag ClusterTag;

	UPROPERTY(EditAnywhere, Category="Audio")
	TArray<TSoftClassPtr<AActor>> ActorClasses;

};

UCLASS(MinimalAPI, meta=(DisplayName="Add Audio Clusters"))
class UGameFeatureAction_AddAudioCluster : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Audio", meta=(ShowOnlyInnerProperties, TitleProperty="{ClusterTag}"))
	TArray<FGameFeatureAudioClusterEntry> Clusters;

	UPROPERTY(EditAnywhere, Category="Audio", meta=(ShowOnlyInnerProperties))
	TMap<FName, FGameplayTag> OverrideTable;

	UPROPERTY(EditAnywhere, Category="Audio")
	FName DisabledActorTag;

private:
	UFUNCTION()
	void HandleRegisteredActorDeath(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

};

