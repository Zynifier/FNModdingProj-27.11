// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundEffectSubmix.h"
#include "Sound/SoundModulationDestination.h"
#include "SubmixEffectDynamicReverb.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FSubmixEffectDynamicReverbSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EarlyReflections")
	bool bBypassEarlyReflections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EarlyReflections", meta=(ClampMax="0.3", ClampMin="0.0", EditCondition="!bBypass && !bBypassEarlyReflections"))
	float ReflectionsDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EarlyReflections", meta=(AudioParam="Additive", ClampMax="1.0", ClampMin="0.0", EditCondition="!bBypass && !bBypassEarlyReflections", UIMax="1.0", UIMin="0.0"))
	FSoundModulationDestinationSettings ReflectionDampening;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EarlyReflections", meta=(AudioParam="Volume", EditCondition="!bBypass && !bBypassEarlyReflections"))
	FSoundModulationDestinationSettings ReflectionsGain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LateReflections")
	bool bBypassLateReflections;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LateReflections", meta=(ClampMax="0.1", ClampMin="0.0", EditCondition="!bBypass && !bBypassLateReflections"))
	float LateDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LateReflections", meta=(AudioParam="DecayTime", ClampMax="20.0", ClampMin="0.0", EditCondition="!bBypass && !bBypassLateReflections", UIMax="20.0", UIMin="0.0"))
	FSoundModulationDestinationSettings DecayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LateReflections", meta=(AudioParam="Additive", EditCondition="!bBypass && !bBypassLateReflections", UIMax="1.0", UIMin="0.0"))
	FSoundModulationDestinationSettings Density;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LateReflections", meta=(AudioParam="Additive", EditCondition="!bBypass && !bBypassLateReflections", UIMax="1.0", UIMin="0.0"))
	FSoundModulationDestinationSettings Diffusion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LateReflections", meta=(AudioParam="Additive", EditCondition="!bBypass && !bBypassLateReflections", UIMax="1.0", UIMin="0.0"))
	FSoundModulationDestinationSettings AirAbsorption;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LateReflections", meta=(AudioParam="DecayHFRatio", ClampMax="2.0", ClampMin="0.1", EditCondition="!bBypass && !bBypassLateReflections", UIMax="2.0", UIMin="0.1"))
	FSoundModulationDestinationSettings DecayHFRatio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LateReflections", meta=(AudioParam="Volume", EditCondition="!bBypass && !bBypassLateReflections"))
	FSoundModulationDestinationSettings LateGain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Routing", meta=(AudioParam="Volume", EditCondition="!bBypass"))
	FSoundModulationDestinationSettings WetLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Routing", meta=(AudioParam="Volume", EditCondition="!bBypass"))
	FSoundModulationDestinationSettings DryLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="General")
	bool bBypass;

};

/** Stub effect: passes audio through unchanged. Exists so the preset can create a valid effect instance. */
class FSubmixEffectDynamicReverb : public FSoundEffectSubmix
{
public:
	virtual void Init(const FSoundEffectSubmixInitData& InInitData) override {}

	virtual void OnProcessAudio(const FSoundEffectSubmixInputData& InData, FSoundEffectSubmixOutputData& OutData) override
	{
		FMemory::Memcpy(OutData.AudioBuffer->GetData(), InData.AudioBuffer->GetData(), sizeof(float) * InData.NumFrames * InData.NumChannels);
	}
};

UCLASS(HideCategories=("Object"))
class FORTNITEGAME_API USubmixEffectDynamicReverbPreset : public USoundEffectSubmixPreset
{
	GENERATED_BODY()

public:
	EFFECT_PRESET_METHODS(SubmixEffectDynamicReverb)

	UFUNCTION(BlueprintCallable, Category="Audio|Effects|Reverb")
	void SetModulationSettings(const FSubmixEffectDynamicReverbSettings& InSettings);

	UFUNCTION(BlueprintCallable, Category="Audio|Effects|Reverb")
	void SetSettings(const FSubmixEffectDynamicReverbSettings& InSettings);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SubmixEffectPreset")
	FSubmixEffectDynamicReverbSettings Settings;

};

