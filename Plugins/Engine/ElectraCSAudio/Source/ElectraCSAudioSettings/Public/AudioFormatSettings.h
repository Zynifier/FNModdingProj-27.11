// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ISoundWaveCloudStreaming.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "AudioFormatSettings.generated.h"

UENUM()
enum class EElectraCloudStreamingEnvironmentType : uint8
{
	// Development environment

	Development = 0,
	// Production environment

	Production = 1,
};

/**
 * Settings for the Electra Cloud Streaming Audio format generator.
 */
UCLASS(Config=Game, DefaultConfig)
class ELECTRACSAUDIOSETTINGS_API UElectraCloudStreamingAudioSettings : public UObject
{
	GENERATED_BODY()

public:
	/** Enables or disables cloud streaming per platform */
	UPROPERTY(EditAnywhere, Config, Category="Platform specific", meta=(DisplayName="Platform specific settings"))
	TMap<FGuid, FSoundWaveCloudStreamingPlatformProjectSettings> PlatformSettings;

	/** Authorization token needed to use the development environment */
	UPROPERTY(EditAnywhere, Config, Category="Deployment", meta=(DisplayName="Authorization token (Development)"))
	FString AuthorizationTokenDev;

	/** Authorization token needed to use the production environment */
	UPROPERTY(EditAnywhere, Config, Category="Deployment", meta=(DisplayName="Authorization token (Production)"))
	FString AuthorizationTokenProd;

	/** To which environment to deploy the cooked soundwaves */
	UPROPERTY(EditAnywhere, Config, Category="Deployment", meta=(DisplayName="Environment to deploy to"))
	EElectraCloudStreamingEnvironmentType DeploymentEnvironment;

};

