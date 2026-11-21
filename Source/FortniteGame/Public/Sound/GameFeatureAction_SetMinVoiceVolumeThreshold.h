// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_SetMinVoiceVolumeThreshold.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Set Min Voice Volume Threshold"))
class UGameFeatureAction_SetMinVoiceVolumeThreshold : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Thresholds", meta=(AssetBundles="Client"))
	bool bEnableFallbackValue;

	UPROPERTY(EditAnywhere, Category="Thresholds", meta=(AssetBundles="Client", ClampMin="0.000100", EditCondition="bEnableFallbackValue"))
	float FallbackVolumeThreshold;

	UPROPERTY(EditAnywhere, Category="Thresholds", meta=(AssetBundles="Client", ClampMin="0.000100"))
	TMap<FString, float> PerPlatformVolumeThresholds;

};

