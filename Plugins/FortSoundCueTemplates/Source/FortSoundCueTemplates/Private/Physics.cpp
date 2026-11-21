// Copyright Epic Games, Inc. All Rights Reserved.

#include "Physics.h"
#include "AudioParameter.h"
#include "Sound/SoundNodeMixer.h"
#include "Sound/SoundNodeModulatorContinuous.h"
#include "Sound/SoundNodeParamCrossFade.h"
#include "Sound/SoundWave.h"

namespace PhysicsSoundCueTemplates
{
	static const FName ImpactTypeParamName(TEXT("ImpactType"));
	static const FName StrengthParamName(TEXT("Strength"));
	static const FName LightLayerName(TEXT("Light"));
	static const FName MediumLayerName(TEXT("Medium"));
	static const FName HeavyLayerName(TEXT("Heavy"));
	static const FName SpeedParamName(TEXT("Speed"));
	static const FName RollingParamName(TEXT("Rolling"));
	static const FName SlidingParamName(TEXT("Sliding"));
	static const FName FlyingParamName(TEXT("Flying"));
	static const FName FloatingParamName(TEXT("Floating"));
}

UPhysicsImpact::UPhysicsImpact(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	StrengthParamPreviewValue = 1.0f;
	ImpactTypeParamPreviewValue = 0;
	VolumeModulationRange = FVector2D(0.95f, 1.05f);
	PitchModulationRange = FVector2D(0.9f, 1.1f);
	ImpactTypeParameterName = PhysicsSoundCueTemplates::ImpactTypeParamName;
	StrengthParameterName = PhysicsSoundCueTemplates::StrengthParamName;
#endif
}

#if WITH_EDITOR
void UPhysicsImpact::AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves)
{
}

void UPhysicsImpact::LoadTemplateDefaultSettings()
{
	Super::LoadTemplateDefaultSettings();

	if (const UPhysicsImpactSCTDefaults* ImpactDefaults = GetDefaultTemplateSettings<UPhysicsImpactSCTDefaults>())
	{
		Light = ImpactDefaults->Light;
		Medium = ImpactDefaults->Medium;
		Heavy = ImpactDefaults->Heavy;
	}
}

void UPhysicsImpact::OnRebuildGraph(USoundCue& SoundCue) const
{
	ApplySettings(SoundCue);

	FFortSoundCueTemplateNodeParams Params;
	Params.bResetInputPinIndex = true;

	AddDelayNode(SoundCue, Params, StartDelay);
	AddModulatorNode(SoundCue, Params, VolumeModulationRange, PitchModulationRange);
	AddSwitchNode(SoundCue, Params, ImpactTypeParameterName);

	Params.Row = 0;
	Params.InputPinIndex = 1;
	Params.bResetInputPinIndex = false;

	AddImpactLayer(SoundCue, Light, PhysicsSoundCueTemplates::LightLayerName, Params);
	AddImpactLayer(SoundCue, Medium, PhysicsSoundCueTemplates::MediumLayerName, Params);
	AddImpactLayer(SoundCue, Heavy, PhysicsSoundCueTemplates::HeavyLayerName, Params);
}

bool UPhysicsImpact::GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const
{
	FAudioParameter Parameter;

	Parameter.ParamName = PhysicsSoundCueTemplates::StrengthParamName;
	Parameter.FloatParam = StrengthParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	Parameter.ParamName = PhysicsSoundCueTemplates::ImpactTypeParamName;
	Parameter.IntParam = ImpactTypeParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Integer;
	OutParameters.Add(Parameter);

	return true;
}

void UPhysicsImpact::AddImpactLayer(USoundCue& SoundCue, const FPhysicsImpactData& ImpactData, const FName& LayerName, FFortSoundCueTemplateNodeParams& Params) const
{
	if (ImpactData.Variations.Num() != 0)
	{
		FFortSoundCueTemplateNodeParams LayerParams = Params;
		LayerParams.bResetInputPinIndex = true;

		FModulatorContinuousParams VolumeParams;
		VolumeParams.ParameterName = StrengthParameterName;
		VolumeParams.Default = 0.0f;
		VolumeParams.MinInput = ImpactData.Settings.VolumeRange.X;
		VolumeParams.MaxInput = ImpactData.Settings.VolumeRange.Y;
		VolumeParams.MinOutput = ImpactData.VolumeOutput.X;
		VolumeParams.MaxOutput = ImpactData.VolumeOutput.Y;
		VolumeParams.ParamMode = ImpactData.Settings.VolumeMode;

		FModulatorContinuousParams PitchParams;
		PitchParams.ParameterName = StrengthParameterName;
		PitchParams.Default = 0.0f;
		PitchParams.MinInput = ImpactData.Settings.PitchRange.X;
		PitchParams.MaxInput = ImpactData.Settings.PitchRange.Y;
		PitchParams.MinOutput = ImpactData.PitchOutput.X;
		PitchParams.MaxOutput = ImpactData.PitchOutput.Y;
		PitchParams.ParamMode = ImpactData.Settings.PitchMode;

		AddContinuousModulatorNode(SoundCue, LayerParams, VolumeParams, PitchParams);

		LayerParams.bResetInputPinIndex = false;
		AddWavePlayerNodes(SoundCue, LayerParams, ToRawPtrTArrayUnsafe(ImpactData.Variations), false, true);

		Params.Row += ImpactData.Variations.Num() / 4 + 1;
		++Params.InputPinIndex;
	}
}
#endif

UPhysicsStateLoop::UPhysicsStateLoop(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	SpeedParamPreviewValue = 1.0f;
	RollingParamPreviewValue = 0.0f;
	SlidingParamPreviewValue = 0.0f;
	FlyingParamPreviewValue = 0.0f;
	FloatingParamPreviewValue = 0.0f;
	SpeedParameterName = PhysicsSoundCueTemplates::SpeedParamName;
	Rolling.ParameterName = PhysicsSoundCueTemplates::RollingParamName;
	Sliding.ParameterName = PhysicsSoundCueTemplates::SlidingParamName;
	Flying.ParameterName = PhysicsSoundCueTemplates::FlyingParamName;
	Floating.ParameterName = PhysicsSoundCueTemplates::FloatingParamName;
#endif
}

#if WITH_EDITOR
void UPhysicsStateLoop::AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves)
{
}

void UPhysicsStateLoop::LoadTemplateDefaultSettings()
{
	Super::LoadTemplateDefaultSettings();

	if (const UPhysicsStateSCTDefaults* StateDefaults = GetDefaultTemplateSettings<UPhysicsStateSCTDefaults>())
	{
		Rolling = StateDefaults->Rolling;
		Sliding = StateDefaults->Sliding;
		Flying = StateDefaults->Flying;
		Floating = StateDefaults->Floating;
	}
}

void UPhysicsStateLoop::OnRebuildGraph(USoundCue& SoundCue) const
{
	ApplySettings(SoundCue);

	FFortSoundCueTemplateNodeParams Params;
	Params.bResetInputPinIndex = true;

	AddDelayNode(SoundCue, Params, StartDelay);
	AddModulatorNode(SoundCue, Params, VolumeModulationRange, PitchModulationRange);
	ConstructNode<USoundNodeMixer>(SoundCue, Params);

	Params.Row = 0;
	Params.bResetInputPinIndex = false;

	AddStateLayer(SoundCue, Rolling, Params);
	AddStateLayer(SoundCue, Sliding, Params);
	AddStateLayer(SoundCue, Flying, Params);
	AddStateLayer(SoundCue, Floating, Params);
}

bool UPhysicsStateLoop::GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const
{
	FAudioParameter Parameter;

	Parameter.ParamName = PhysicsSoundCueTemplates::SpeedParamName;
	Parameter.FloatParam = SpeedParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	Parameter.ParamName = PhysicsSoundCueTemplates::RollingParamName;
	Parameter.FloatParam = RollingParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	Parameter.ParamName = PhysicsSoundCueTemplates::SlidingParamName;
	Parameter.FloatParam = SlidingParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	Parameter.ParamName = PhysicsSoundCueTemplates::FlyingParamName;
	Parameter.FloatParam = FlyingParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	Parameter.ParamName = PhysicsSoundCueTemplates::FloatingParamName;
	Parameter.FloatParam = FloatingParamPreviewValue;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	return true;
}

void UPhysicsStateLoop::AddStateLayer(USoundCue& SoundCue, const FPhysicsStateData& StateData, FFortSoundCueTemplateNodeParams& Params) const
{
	if (StateData.SlowLoop || StateData.FastLoop)
	{
		FFortSoundCueTemplateNodeParams LayerParams = Params;
		LayerParams.bResetInputPinIndex = true;

		FModulatorContinuousParams VolumeParams;
		VolumeParams.ParameterName = StateData.ParameterName;
		VolumeParams.Default = 0.0f;

		FModulatorContinuousParams PitchParams;

		AddContinuousModulatorNode(SoundCue, LayerParams, VolumeParams, PitchParams);

		VolumeParams.ParameterName = SpeedParameterName;
		VolumeParams.Default = 0.0f;
		VolumeParams.MinInput = StateData.Settings.VolumeRange.X;
		VolumeParams.MaxInput = StateData.Settings.VolumeRange.Y;
		VolumeParams.MinOutput = StateData.VolumeOutput.X;
		VolumeParams.MaxOutput = StateData.VolumeOutput.Y;
		VolumeParams.ParamMode = StateData.Settings.VolumeMode;

		PitchParams.ParameterName = SpeedParameterName;
		PitchParams.Default = 0.0f;
		PitchParams.MinInput = StateData.Settings.PitchRange.X;
		PitchParams.MaxInput = StateData.Settings.PitchRange.Y;
		PitchParams.MinOutput = StateData.PitchOutput.X;
		PitchParams.MaxOutput = StateData.PitchOutput.Y;
		PitchParams.ParamMode = StateData.Settings.PitchMode;

		AddContinuousModulatorNode(SoundCue, LayerParams, VolumeParams, PitchParams);

		USoundNode* CrossFadeNode = AddParamCrossFadeNode(SoundCue, LayerParams, SpeedParameterName, TArray<FDistanceDatum>());

		LayerParams.bResetInputPinIndex = false;

		TArray<USoundWave*> SlowWaves;
		SlowWaves.Add(StateData.SlowLoop);
		AddWavePlayerNodes(SoundCue, LayerParams, SlowWaves, true, true);

		++LayerParams.InputPinIndex;

		TArray<USoundWave*> FastWaves;
		FastWaves.Add(StateData.FastLoop);
		AddWavePlayerNodes(SoundCue, LayerParams, FastWaves, true, true);

		if (USoundNodeParamCrossFade* ParamCrossFadeNode = Cast<USoundNodeParamCrossFade>(CrossFadeNode))
		{
			ParamCrossFadeNode->CrossFadeInput.SetNum(2);
			ParamCrossFadeNode->CrossFadeInput[0] = StateData.CrossfadeInputSlow;
			ParamCrossFadeNode->CrossFadeInput[1] = StateData.CrossfadeInputFast;
		}

		++Params.Row;
		++Params.InputPinIndex;
	}

	++Params.Row;
}
#endif
