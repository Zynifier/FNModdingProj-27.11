// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/PannerDetails.h"
#include "HarmonixDsp/Streaming/TrackChannelInfo.h"
#include "HarmonixDsp/StretcherAndPitchShifter.h"
#include "KeyzoneSettings.generated.h"

class USoundWave;

USTRUCT()
struct HARMONIXDSP_API FKeyzoneSettings
{
	GENERATED_BODY()

public:
	// Not null when this keyzone is not being proxied
// Made private since we generally want the Proxy Data

	UPROPERTY(EditDefaultsOnly, Category="Audio Sample")
	TObjectPtr<USoundWave> SoundWave;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="127", ClampMin="0", UIMax="127", UIMin="0"))
	int8 RootNote;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="127", ClampMin="0", UIMax="127", UIMin="0"))
	int8 MinNote;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="127", ClampMin="0", UIMax="127", UIMin="0"))
	int8 MaxNote;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="127", ClampMin="0", UIMax="127", UIMin="0"))
	int8 MinVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="127", ClampMin="0", UIMax="127", UIMin="0"))
	int8 MaxVelocity;

	// on disk this is the index into the sample file name table

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	uint8 SampleIndex;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	uint8 Priority;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FPannerDetails Pan;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="100", ClampMin="-100", UIMax="100", UIMin="-100"))
	float FineTuneCents;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1.0", ClampMin="0.0", PostEditType="Trivial", UIMax="1.0", UIMin="0.0"))
	float Gain;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool bUnpitched;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool bVelocityToGain;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FTimeStretchConfig TimeStretchConfig;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool bIsNoteOffZone;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="100", ClampMin="0", UIMax="100", UIMin="0"))
	float RandomWeight;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMin="-1", UIMin="-1"))
	int32 SampleStartOffset;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMin="-1", UIMin="-1"))
	int32 SampleEndOffset;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	TArray<FTrackChannelInfo> TrackMap;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	bool UseSingletonVoicePool;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(EditCondition="false"))
	FString SamplePath;
#endif

};

