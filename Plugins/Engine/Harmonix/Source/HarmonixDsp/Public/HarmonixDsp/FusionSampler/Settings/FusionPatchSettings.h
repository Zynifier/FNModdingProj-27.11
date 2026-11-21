// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/Effects/Settings/BiquadFilterSettings.h"
#include "HarmonixDsp/Effects/Settings/BitCrusherSettings.h"
#include "HarmonixDsp/Effects/Settings/DelaySettings.h"
#include "HarmonixDsp/Effects/Settings/DistortionSettings.h"
#include "HarmonixDsp/Effects/Settings/VocoderSettings.h"
#include "HarmonixDsp/FusionSampler/Settings/PortamentoSettings.h"
#include "HarmonixDsp/Modulators/Settings/AdsrSettings.h"
#include "HarmonixDsp/Modulators/Settings/LfoSettings.h"
#include "HarmonixDsp/Modulators/Settings/ModulatorSettings.h"
#include "HarmonixDsp/PannerDetails.h"
#include "FusionPatchSettings.generated.h"

UENUM()
enum class EKeyzoneSelectMode : uint8
{
	Layers = 0 UMETA(Json="layers"),
	Random = 1 UMETA(Json="random"),
	RandomWithRepetition = 2 UMETA(Json="random_with_repititon"),
	Cycle = 3 UMETA(Json="cycle"),
	Num = 4 UMETA(Hidden),
	Invalid = 5 UMETA(Hidden),
};

USTRUCT()
struct HARMONIXDSP_API FFusionPatchSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="12", ClampMin="-96", UIMax="12", UIMin="-96"))
	float VolumeDb;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FPannerDetails PannerDetails;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="-200", ClampMin="-2400", UIMax="-200", UIMin="-2400"))
	float DownPitchBendCents;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="2400", ClampMin="200", UIMax="2400", UIMin="200"))
	float UpPitchBendCents;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="100", ClampMin="-100", UIMax="100", UIMin="-100"))
	float FineTuneCents;

	UPROPERTY(EditDefaultsOnly, Category="Settings", meta=(ClampMax="1000", ClampMin="0", DisplayName="Start Point Offset (Ms)", UIMax="1000", UIMin="0"))
	float StartPointOffsetMs;

	UPROPERTY()
	int32 MaxVoices;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	EKeyzoneSelectMode KeyzoneSelectMode;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FPortamentoSettings Portamento;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FBiquadFilterSettings Filter;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FDelaySettings Delay;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FDistortionSettingsV1 Distortion;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FBitCrusherSettings BitCrusher;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FVocoderSettings Vocoder;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FAdsrSettingsArray Adsrs;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FLfoSettingsArray Lfos;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FModulatorSettingsArray Randomizers;

	UPROPERTY(EditDefaultsOnly, Category="Settings")
	FModulatorSettingsArray VelocityModulators;

};

