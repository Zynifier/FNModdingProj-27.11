// Copyright Epic Games, Inc. All Rights Reserved.

#include "GliderSoundCueTemplates.h"
#include "AudioParameter.h"
#include "Sound/SoundNodeMixer.h"
#include "Sound/SoundNodeModulatorContinuous.h"
#include "Sound/SoundWave.h"

namespace GliderSoundCueTemplates
{
	static const FName ForwardsParamName(TEXT("Forwards"));
	static const FName SidewaysParamName(TEXT("Sideways"));
	static const FName BackwardsParamName(TEXT("Backwards"));
	static const FName AnyDirectionParamName(TEXT("AnyDirection"));
}

UGliderThrustLoop::UGliderThrustLoop(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	Forward.ParameterName = GliderSoundCueTemplates::ForwardsParamName;
	Sideways.ParameterName = GliderSoundCueTemplates::SidewaysParamName;
	Backwards.ParameterName = GliderSoundCueTemplates::BackwardsParamName;
	AnyDirection.ParameterName = GliderSoundCueTemplates::AnyDirectionParamName;
#endif
}

#if WITH_EDITOR
void UGliderThrustLoop::AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves)
{
}

void UGliderThrustLoop::LoadTemplateDefaultSettings()
{
	Super::LoadTemplateDefaultSettings();

	if (const UGliderThrustSCTDefaults* GliderDefaults = GetDefaultTemplateSettings<UGliderThrustSCTDefaults>())
	{
		Forward = GliderDefaults->Forward;
		Sideways = GliderDefaults->Sideways;
		Backwards = GliderDefaults->Backwards;
		AnyDirection = GliderDefaults->AnyDirection;
	}
}

void UGliderThrustLoop::OnRebuildGraph(USoundCue& SoundCue) const
{
	ApplySettings(SoundCue);

	FFortSoundCueTemplateNodeParams Params;

	if (AddDelayNode(SoundCue, Params, StartDelay))
	{
		Params.InputPinIndex = 0;
	}

	if (AddModulatorNode(SoundCue, Params, VolumeModulationRange, PitchModulationRange))
	{
		Params.InputPinIndex = 0;
	}

	ConstructNode<USoundNodeMixer>(SoundCue, Params);
	Params.Row = 0;

	AddThrustLayer(SoundCue, Forward, Params);
	AddThrustLayer(SoundCue, Sideways, Params);
	AddThrustLayer(SoundCue, Backwards, Params);
	AddThrustLayer(SoundCue, AnyDirection, Params);
}

bool UGliderThrustLoop::GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const
{
	FAudioParameter Parameter;

	Parameter.ParamName = GliderSoundCueTemplates::ForwardsParamName;
	Parameter.FloatParam = ForwardsParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	Parameter.ParamName = GliderSoundCueTemplates::SidewaysParamName;
	Parameter.FloatParam = SidewaysParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	Parameter.ParamName = GliderSoundCueTemplates::BackwardsParamName;
	Parameter.FloatParam = BackwardsParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	Parameter.ParamName = GliderSoundCueTemplates::AnyDirectionParamName;
	Parameter.FloatParam = AnyDirectionParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	return true;
}

void UGliderThrustLoop::AddThrustLayer(USoundCue& SoundCue, const FGliderThrustData& ThrustData, FFortSoundCueTemplateNodeParams& Params) const
{
	if (ThrustData.Sound)
	{
		FFortSoundCueTemplateNodeParams LayerParams = Params;
		LayerParams.InputPinIndex = Params.Row;
		LayerParams.bResetInputPinIndex = true;

		FModulatorContinuousParams VolumeParams;
		VolumeParams.ParameterName = ThrustData.ParameterName;
		VolumeParams.Default = 0.0f;
		VolumeParams.MinInput = ThrustData.Settings.VolumeRange.X;
		VolumeParams.MaxInput = ThrustData.Settings.VolumeRange.Y;
		VolumeParams.MinOutput = ThrustData.VolumeOutput.X;
		VolumeParams.MaxOutput = ThrustData.VolumeOutput.Y;
		VolumeParams.ParamMode = ThrustData.Settings.VolumeMode;

		FModulatorContinuousParams PitchParams;
		PitchParams.ParameterName = ThrustData.ParameterName;
		PitchParams.Default = 0.0f;
		PitchParams.MinInput = ThrustData.Settings.PitchRange.X;
		PitchParams.MaxInput = ThrustData.Settings.PitchRange.Y;
		PitchParams.MinOutput = ThrustData.PitchOutput.X;
		PitchParams.MaxOutput = ThrustData.PitchOutput.Y;
		PitchParams.ParamMode = ThrustData.Settings.PitchMode;

		AddContinuousModulatorNode(SoundCue, LayerParams, VolumeParams, PitchParams);

		LayerParams.bResetInputPinIndex = false;

		TArray<USoundWave*> Waves;
		Waves.Add(ThrustData.Sound);
		AddWavePlayerNodes(SoundCue, LayerParams, Waves, true, true);
	}

	++Params.Row;
}
#endif

UGliderThrustStart::UGliderThrustStart(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	VolumeModulationRange = FVector2D(0.95f, 1.05f);
	PitchModulationRange = FVector2D(0.9f, 1.1f);
#endif
}

#if WITH_EDITOR
void UGliderThrustStart::AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves)
{
	for (const TWeakObjectPtr<USoundWave>& Wave : Waves)
	{
		if (Wave.IsValid())
		{
			Variations.Add(Wave.Get());
		}
	}
}

void UGliderThrustStart::OnRebuildGraph(USoundCue& SoundCue) const
{
	TArray<USoundWave*> ValidVariations;
	for (USoundWave* Variation : Variations)
	{
		if (Variation)
		{
			ValidVariations.Add(Variation);
		}
	}

	if (ValidVariations.Num() != 0)
	{
		ApplySettings(SoundCue);

		FFortSoundCueTemplateNodeParams Params;

		if (AddDelayNode(SoundCue, Params, StartDelay))
		{
			Params.InputPinIndex = 0;
		}

		if (AddModulatorNode(SoundCue, Params, VolumeModulationRange, PitchModulationRange))
		{
			Params.InputPinIndex = 0;
		}

		AddWavePlayerNodes(SoundCue, Params, ValidVariations, false, true);
	}
}

void UGliderThrustStart::ValidateTemplateData()
{
	Super::ValidateTemplateData();

	Variations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });

	if (VolumeModulationRange.Equals(FVector2D::UnitVector))
	{
		VolumeModulationRange = FVector2D(0.95f, 1.05f);
	}

	if (PitchModulationRange.Equals(FVector2D::UnitVector))
	{
		PitchModulationRange = FVector2D(0.9f, 1.1f);
	}
}
#endif
