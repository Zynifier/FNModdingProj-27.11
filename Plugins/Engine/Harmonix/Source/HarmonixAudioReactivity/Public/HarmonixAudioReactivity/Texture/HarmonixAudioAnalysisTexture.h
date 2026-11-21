// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixAudioReactivity/Texture/HarmonixAudioAnalysisType.h"
#include "HarmonixAudioReactivity/Texture/HarmonixHysteresisTextureBase.h"
#include "HarmonixAudioAnalysisTexture.generated.h"

class UMusicClockComponent;

UCLASS(HideCategories=("Object", "Texture", "Adjustments", "Compression", "LevelOfDetail", "Compositing", "ImportSettings"))
class HARMONIXAUDIOREACTIVITY_API UHarmonixAudioAnalysisTexture : public UHarmonixHysteresisTextureBase
{
	GENERATED_BODY()

public:
	// Which musical clock (if any) should we synchronize to?

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="AudioAnalysisTexture")
	TWeakObjectPtr<UMusicClockComponent> MusicClock;

private:
	// Which type of audio filter should we read audio analyzer data from?

	UPROPERTY(EditAnywhere, Category="AudioAnalysisTexture")
	EHarmonixAudioAnalysisType Type;

	// Which analyzer slot should we read audio data from?

	UPROPERTY(EditAnywhere, Category="AudioAnalysisTexture")
	FName InstanceName;

	UPROPERTY(EditAnywhere, Category="AudioAnalysisTexture")
	bool ResetMonoPeakOnUpdate;

	// Should we print warnings if we try to use an analyzer type/slot that's not enabled?

	UPROPERTY(EditAnywhere, Category="AudioAnalysisTexture")
	bool WarnIfNotEnabled;

};

