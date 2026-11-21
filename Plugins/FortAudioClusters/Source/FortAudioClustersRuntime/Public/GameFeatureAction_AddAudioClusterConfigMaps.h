// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_AddAudioClusterConfigMaps.generated.h"

class UAudioClusterConfigMap;

UCLASS(MinimalAPI, meta=(DisplayName="Add Audio Cluster Config Maps"))
class UGameFeatureAction_AddAudioClusterConfigMaps : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Config")
	TArray<TSoftObjectPtr<UAudioClusterConfigMap>> ConfigMaps;

};

