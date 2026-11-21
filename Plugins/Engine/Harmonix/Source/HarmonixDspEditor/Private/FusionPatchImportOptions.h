// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundWave.h"
#include "Sound/SoundWaveLoadingBehavior.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "FusionPatchImportOptions.generated.h"

UCLASS(Config=Editor)
class UFusionPatchImportOptions : public UObject
{
	GENERATED_BODY()

public:
	/** The directory to save samples to */
	UPROPERTY(EditAnywhere, Config, Category="Import Options", meta=(ContentDir, DisplayName="Sound Waves Import Folder"))
	FDirectoryPath SamplesImportDir;

	/** The loading behavior to apply to the imported samples */
	UPROPERTY(EditAnywhere, Category="Import Options", meta=(DisplayName="Sound Wave Loading Behavior"))
	ESoundWaveLoadingBehavior SampleLoadingBehavior;

	/** The compression type to apply to the imported samples */
	UPROPERTY(EditAnywhere, Category="Import Options", meta=(DisplayName="Sound Wave Compression Type"))
	ESoundAssetCompressionType SampleCompressionType;

};

