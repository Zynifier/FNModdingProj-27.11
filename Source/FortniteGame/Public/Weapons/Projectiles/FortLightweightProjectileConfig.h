// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScalableFloat.h"
#include "FortLightweightProjectileConfig.generated.h"

class UBulletWhipTrackerAudioData;
class UNiagaraDataChannelAsset;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AFortLightweightProjectileConfig : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLightweightProjectileConfig")
	FScalableFloat Speed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLightweightProjectileConfig")
	FScalableFloat GravityScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLightweightProjectileConfig")
	FScalableFloat HitscanDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLightweightProjectileConfig")
	FScalableFloat Lifetime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLightweightProjectileConfig")
	TObjectPtr<UNiagaraDataChannelAsset> ProjectileFXDataChannel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLightweightProjectileConfig")
	TObjectPtr<UBulletWhipTrackerAudioData> WhipTrackerData;

};

