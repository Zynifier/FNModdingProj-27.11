// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlayerFoley.h"
#include "AudioParameter.h"
#include "Sound/SoundNodeMixer.h"
#include "Sound/SoundNodeQualityLevel.h"
#include "Sound/SoundWave.h"

namespace PlayerFoleySoundCueTemplates
{
	static const FName PlayerRelationParamName(TEXT("PlayerRelation"));
	static const FName StanceParamName(TEXT("Stance"));
	static const FName ElevationParamName(TEXT("Elevation"));
}

UPlayerFoleyBase::UPlayerFoleyBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	MaxVariations = 10;
	MaxVariationsMobile = 5;
	RelationToPlayer = EFortFootstepPlayerRelation::Friendly;
	StepType = EFortFootstepStanceType::Walk;
	Elevation = 0.0f;
	Distance = 0.0f;
	PitchModulationRange = FVector2D(0.95f, 1.05f);
	VolumeModulationRange = FVector2D(0.95f, 1.05f);
#endif
}

UPlayerFoley::UPlayerFoley(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	bUsingStances = false;
	VariationVolume = 1.0f;
	WalkVolume = 1.0f;
	RunVolume = 1.0f;
	SprintVolume = 1.0f;
	CrouchWalkVolume = 1.0f;
	CrouchRunVolume = 1.0f;
	WalkVolumeAboveBelow = 1.0f;
	RunVolumeAboveBelow = 1.0f;
	SprintVolumeAboveBelow = 1.0f;
	CrouchWalkVolumeAboveBelow = 1.0f;
	CrouchRunVolumeAboveBelow = 1.0f;
#endif
}

#if WITH_EDITOR
void UPlayerFoley::AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves)
{
	for (const TWeakObjectPtr<USoundWave>& WeakWave : Waves)
	{
		if (USoundWave* Wave = WeakWave.Get())
		{
			const FString WaveName = Wave->GetName();
			if (WaveName.Contains(TEXT("CrouchRun")))
			{
				if (WaveName.Contains(TEXT("_AboveBelow_")))
				{
					CrouchRunVariationsAboveBelow.Add(Wave);
				}
				else
				{
					CrouchRunVariations.Add(Wave);
				}
			}
			else if (WaveName.Contains(TEXT("CrouchWalk")))
			{
				if (WaveName.Contains(TEXT("_AboveBelow_")))
				{
					CrouchWalkVariationsAboveBelow.Add(Wave);
				}
				else
				{
					CrouchWalkVariations.Add(Wave);
				}
			}
			else if (WaveName.Contains(TEXT("Walk")))
			{
				if (WaveName.Contains(TEXT("_AboveBelow_")))
				{
					WalkVariationsAboveBelow.Add(Wave);
				}
				else
				{
					WalkVariations.Add(Wave);
				}
			}
			else if (WaveName.Contains(TEXT("Run")))
			{
				if (WaveName.Contains(TEXT("_AboveBelow_")))
				{
					RunVariationsAboveBelow.Add(Wave);
				}
				else
				{
					RunVariations.Add(Wave);
				}
			}
			else if (WaveName.Contains(TEXT("Sprint")))
			{
				if (WaveName.Contains(TEXT("_AboveBelow_")))
				{
					SprintVariationsAboveBelow.Add(Wave);
				}
				else
				{
					SprintVariations.Add(Wave);
				}
			}
			else
			{
				WaveVariations.Add(Wave);
			}
		}
	}
}

void UPlayerFoley::OnRebuildGraph(USoundCue& SoundCue) const
{
	ApplySettings(SoundCue);

	FFortSoundCueTemplateNodeParams Params;
	Params.bResetInputPinIndex = true;

	AddModulatorNode(SoundCue, Params, VolumeModulationRange, PitchModulationRange);
	AddSwitchNode(SoundCue, Params, PlayerFoleySoundCueTemplates::PlayerRelationParamName);

	Params.bResetInputPinIndex = false;

	static const FName ParameterUnsetPinName(Params.ParentNode->GetInputPinName(0).ToString());

	TArray<USoundNode*> ElevationNodes;
	USoundNode* StanceSwitchNode = nullptr;
	USoundNode* AboveBelowStanceSwitchNode = nullptr;
	int32 StanceRow = 0;
	int32 StanceColumn = 0;

	if (const UPlayerFoleyDefaults* FoleyDefaults = GetDefaultTemplateSettings<UPlayerFoleyDefaults>())
	{
		FFortSoundCueTemplateNodeParams LayerParams = Params;
		AddSoundClassNode(SoundCue, LayerParams, FoleyDefaults->LocalPlayerSoundClass);

		Params.InputPinIndex = 1;
		++LayerParams.Column;

		AddAttenuationNode(SoundCue, LayerParams, FoleyDefaults->LocalPlayerAttenuation);
		ConstructNode<USoundNodeMixer>(SoundCue, LayerParams);
		++LayerParams.Column;

		USoundNode* VariationNode = AddVariationLayer(SoundCue, LayerParams, WaveVariations, VariationVolume);

		if (bUsingStances)
		{
			StanceColumn = --LayerParams.Column;
			AddSwitchNode(SoundCue, LayerParams, PlayerFoleySoundCueTemplates::StanceParamName);
			LayerParams.PendingPinLinks.Add({ 0, ParameterUnsetPinName });

			AddVariationLayer(SoundCue, LayerParams, WalkVariations, WalkVolume);
			AddVariationLayer(SoundCue, LayerParams, RunVariations, RunVolume);
			AddVariationLayer(SoundCue, LayerParams, SprintVariations, SprintVolume);
			AddVariationLayer(SoundCue, LayerParams, CrouchWalkVariations, CrouchWalkVolume);
			AddVariationLayer(SoundCue, LayerParams, CrouchRunVariations, CrouchRunVolume);

			StanceSwitchNode = LayerParams.ParentNode;
			StanceRow = LayerParams.Row;
		}

		++Params.Row;
		LayerParams = Params;
		if (Params.ParentNode)
		{
			LayerParams.PendingPinLinks.Add({ 0, ParameterUnsetPinName });
		}

		AddSoundClassNode(SoundCue, LayerParams, FoleyDefaults->TeammateSoundClass);
		AddElevationLayers(SoundCue, LayerParams, ElevationNodes);
		AddChildNode(SoundCue, ElevationNodes[0], VariationNode, 0);
		AddChildNode(SoundCue, ElevationNodes[1], VariationNode, 0);

		if (bUsingStances)
		{
			AddChildNode(SoundCue, ElevationNodes[1], StanceSwitchNode, 1);

			LayerParams.ParentNode = ElevationNodes[0];
			LayerParams.Row = StanceRow;
			LayerParams.Column = StanceColumn;
			AddSwitchNode(SoundCue, LayerParams, PlayerFoleySoundCueTemplates::StanceParamName);
			LayerParams.PendingPinLinks.Add({ 0, ParameterUnsetPinName });

			AddVariationLayer(SoundCue, LayerParams, WalkVariationsAboveBelow, WalkVolumeAboveBelow);
			AddVariationLayer(SoundCue, LayerParams, RunVariationsAboveBelow, RunVolumeAboveBelow);
			AddVariationLayer(SoundCue, LayerParams, SprintVariationsAboveBelow, SprintVolumeAboveBelow);
			AddVariationLayer(SoundCue, LayerParams, CrouchWalkVariationsAboveBelow, CrouchWalkVolumeAboveBelow);
			AddVariationLayer(SoundCue, LayerParams, CrouchRunVariationsAboveBelow, CrouchRunVolumeAboveBelow);

			AboveBelowStanceSwitchNode = LayerParams.ParentNode;
		}

		++Params.Row;
		LayerParams = Params;

		AddSoundClassNode(SoundCue, LayerParams, FoleyDefaults->HostileSoundClass);
		AddElevationLayers(SoundCue, LayerParams, ElevationNodes);
		AddChildNode(SoundCue, ElevationNodes[0], VariationNode, 0);
		AddChildNode(SoundCue, ElevationNodes[1], VariationNode, 0);

		if (bUsingStances)
		{
			AddChildNode(SoundCue, ElevationNodes[0], AboveBelowStanceSwitchNode, 1);
			AddChildNode(SoundCue, ElevationNodes[1], StanceSwitchNode, 1);
		}

		++Params.Row;
	}
}

bool UPlayerFoley::GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const
{
	FAudioParameter Parameter;

	if (RelationToPlayer != EFortFootstepPlayerRelation::Max_None)
	{
		Parameter.ParamName = PlayerFoleySoundCueTemplates::PlayerRelationParamName;
		Parameter.IntParam = static_cast<int32>(RelationToPlayer);
		Parameter.ParamType = EAudioParameterType::Integer;
		OutParameters.Add(Parameter);
	}

	Parameter.ParamName = PlayerFoleySoundCueTemplates::ElevationParamName;
	Parameter.FloatParam = Elevation + 2.0f;
	Parameter.ParamType = EAudioParameterType::Float;
	OutParameters.Add(Parameter);

	if (bUsingStances && StepType != EFortFootstepStanceType::Max_None)
	{
		Parameter.ParamName = PlayerFoleySoundCueTemplates::StanceParamName;
		Parameter.IntParam = static_cast<int32>(StepType);
		Parameter.ParamType = EAudioParameterType::Integer;
		OutParameters.Add(Parameter);
	}

	return true;
}

void UPlayerFoley::ValidateTemplateData()
{
	Super::ValidateTemplateData();

	WaveVariations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	WalkVariations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	RunVariations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	SprintVariations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	CrouchWalkVariations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	CrouchRunVariations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	WalkVariationsAboveBelow.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	RunVariationsAboveBelow.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	SprintVariationsAboveBelow.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	CrouchWalkVariationsAboveBelow.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	CrouchRunVariationsAboveBelow.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
}

USoundNode* UPlayerFoley::AddVariationLayer(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const TArray<TObjectPtr<USoundWave>>& Waves, float Volume) const
{
	FFortSoundCueTemplateNodeParams LayerParams = Params;
	USoundNodeMixer* MixerNode = ConstructNode<USoundNodeMixer>(SoundCue, LayerParams);
	USoundNodeQualityLevel* QualityLevelNode = ConstructNode<USoundNodeQualityLevel>(SoundCue, LayerParams);

	Params.PendingPinLinks.Reset();
	LayerParams.InputPinIndex = 0;

	const UPlayerFoleyDefaults* FoleyDefaults = GetDefaultTemplateSettings<UPlayerFoleyDefaults>();
	if (MixerNode->InputVolume.Num() > 0)
	{
		MixerNode->InputVolume[0] = Volume * FoleyDefaults->VolumeMultiplier;
	}

	TArray<TObjectPtr<USoundWave>> LayerWaves = Waves;
	LayerWaves.SetNum(FMath::Min(MaxVariations, Waves.Num()));
	AddWavePlayerNodes(SoundCue, LayerParams, ToRawPtrTArrayUnsafe(AsConst(LayerWaves)), false, false);
	++LayerParams.InputPinIndex;
	LayerParams.Row += 1 + LayerWaves.Num() / 4;
	USoundNode& HighQualityNode = *QualityLevelNode->ChildNodes[LayerParams.InputPinIndex - 1];
	AddSoundNodeChild(*QualityLevelNode, HighQualityNode, LayerParams.InputPinIndex++);

	LayerWaves = Waves;
	LayerWaves.SetNum(FMath::Min(MaxVariationsMobile, Waves.Num()));
	AddWavePlayerNodes(SoundCue, LayerParams, ToRawPtrTArrayUnsafe(AsConst(LayerWaves)), false, false);
	++LayerParams.InputPinIndex;
	LayerParams.Row += 1 + LayerWaves.Num() / 4;
	USoundNode& LowQualityNode = *QualityLevelNode->ChildNodes[LayerParams.InputPinIndex - 1];
	AddSoundNodeChild(*QualityLevelNode, LowQualityNode, LayerParams.InputPinIndex++);

	Params.Row = LayerParams.Row;
	++Params.InputPinIndex;

	return MixerNode;
}

void UPlayerFoley::AddElevationLayers(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, TArray<USoundNode*>& OutElevationNodes) const
{
	OutElevationNodes.Reset();

	const UPlayerFoleyDefaults* FoleyDefaults = GetDefaultTemplateSettings<UPlayerFoleyDefaults>();

	Params.bResetInputPinIndex = false;
	const int32 StartRow = Params.Row;

	AddParamCrossFadeNode(SoundCue, Params, PlayerFoleySoundCueTemplates::ElevationParamName, FoleyDefaults->ElevationCrossfadeDistances);

	FFortSoundCueTemplateNodeParams LayerParams = Params;
	USoundNode* BelowAttenuationNode = AddAttenuationNode(SoundCue, LayerParams, FoleyDefaults->BelowAttenuation);
	USoundNode* BelowMixerNode = ConstructNode<USoundNodeMixer>(SoundCue, LayerParams);
	OutElevationNodes.Add(BelowMixerNode);

	LayerParams = Params;
	LayerParams.Row = StartRow + 1;
	USoundNode* ParallelAttenuationNode = AddAttenuationNode(SoundCue, LayerParams, FoleyDefaults->ParallelAttenuation);
	USoundNode* ParallelMixerNode = ConstructNode<USoundNodeMixer>(SoundCue, LayerParams);
	OutElevationNodes.Add(ParallelMixerNode);

	LayerParams = Params;
	LayerParams.Row = StartRow + 2;
	USoundNode* AboveAttenuationNode = AddAttenuationNode(SoundCue, LayerParams, FoleyDefaults->AboveAttenuation);
	AddChildNode(SoundCue, AboveAttenuationNode, BelowMixerNode, 0);

	int32 NodePosY = static_cast<int32>(GetInitialHeightOffset() + GetNodeHeightOffset() * Params.Row);
	BelowAttenuationNode->GraphNode->NodePosY = NodePosY;
	BelowMixerNode->GraphNode->NodePosY = NodePosY;

	NodePosY += 60;
	ParallelAttenuationNode->GraphNode->NodePosY = NodePosY;
	ParallelMixerNode->GraphNode->NodePosY = NodePosY + 30;

	NodePosY += 60;
	AboveAttenuationNode->GraphNode->NodePosY = NodePosY;

	Params.Row = StartRow + 2;
}
#endif
