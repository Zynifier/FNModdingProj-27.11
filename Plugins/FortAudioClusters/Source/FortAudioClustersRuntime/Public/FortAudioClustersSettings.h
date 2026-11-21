// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "FortAudioClustersSettings.generated.h"

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Audio Clusters for Fortnite"))
class UFortAudioClustersSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Config")
	TMap<FGameplayTag, double> ParameterDefaults;

};

