// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "PBWLedgeConfigurationData.h"
#include "LedgeLaunchWorldSubsystem.generated.h"

class UObject;
class UPBWLedgeConfigurationData;

UCLASS(Config=ClamberingCode, DefaultConfig)
class ULedgeLaunchWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TSoftObjectPtr<UPBWLedgeConfigurationData> ConfigurationData;

	UPROPERTY(Transient)
	UPBWLedgeConfigurationData* CachedConfigurationData;

	UPROPERTY(Transient)
	TMap<UClass*, FLedgeLaunchConfigEntry> CachedLedgeLaunchMap;

};

