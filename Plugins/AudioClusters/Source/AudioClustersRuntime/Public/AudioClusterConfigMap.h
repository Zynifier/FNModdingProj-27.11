// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "AudioClusterConfigMap.generated.h"

class UAudioClusterConfig;

UCLASS(BlueprintType)
class AUDIOCLUSTERSRUNTIME_API UAudioClusterConfigMap : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Mapping")
	TMap<FGameplayTag, TObjectPtr<UAudioClusterConfig>> TagConfigMap;

};

