// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineHotfixManager.h"
#include "FortHotfixManager.generated.h"

UENUM()
enum class EFortGameServiceHotConfigResult : uint8
{
	Success_ReplacedDomain = 0,
	Success_DomainAlreadySet = 1,
	Failure_ConfigSectionNotFound = 2,
	Failure_PlatformNotFound = 3,
	Failure_GameServiceNotFound = 4,
	Failure_EpicAppNotFound = 5,
	Failure_ConfigParsingFailed = 6,
	Unknown = 7,
};

USTRUCT()
struct FFortHotfixGameServiceHotConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FString Environment;

	UPROPERTY(Config)
	FString ConfigPath;

};

UCLASS(MinimalAPI)
class UFortHotfixManager : public UOnlineHotfixManager
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	FString GameServiceHotConfigUrl;

	UPROPERTY(Config)
	TArray<FFortHotfixGameServiceHotConfig> GameServiceHotConfigPaths;

	UPROPERTY(Config)
	bool bEnableUnloadedPluginHotfixing;

};

