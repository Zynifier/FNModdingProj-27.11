// Copyright Epic Games, Inc. All Rights Reserved.

#include "PickaxeSoundCueTemplates.h"
#include "Sound/SoundNodeAttenuation.h"
#include "Sound/SoundNodeMixer.h"
#include "Sound/SoundWave.h"

UPickaxeBase::UPickaxeBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	VolumeModulationRange = FVector2D(0.95f, 1.05f);
	PitchModulationRange = FVector2D(0.95f, 1.05f);
#endif
}

void UPickaxeBase::PostLoad()
{
	Super::PostLoad();

#if WITH_EDITOR
	if (!CloseAttenuationSettings || !DistantAttenuationSettings)
	{
		if (const UPickaxeSCTDefaults* PickaxeDefaults = GetDefaultTemplateSettings<UPickaxeSCTDefaults>())
		{
			CloseAttenuationSettings = PickaxeDefaults->CloseAttenuation;
			DistantAttenuationSettings = PickaxeDefaults->DistantAttenuation;
		}
	}
#endif
}

#if WITH_EDITOR
void UPickaxeBase::AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves)
{
	for (const TWeakObjectPtr<USoundWave>& Wave : Waves)
	{
		if (Wave.IsValid())
		{
			CloseVariations.Add(Wave.Get());
		}
	}
}

void UPickaxeBase::LoadTemplateDefaultSettings()
{
	Super::LoadTemplateDefaultSettings();

	if (const UPickaxeSCTDefaults* PickaxeDefaults = GetDefaultTemplateSettings<UPickaxeSCTDefaults>())
	{
		CloseAttenuationSettings = PickaxeDefaults->CloseAttenuation;
		DistantAttenuationSettings = PickaxeDefaults->DistantAttenuation;
	}
}

void UPickaxeBase::OnRebuildGraph(USoundCue& SoundCue) const
{
	TArray<USoundWave*> CloseWaves;
	for (USoundWave* Variation : CloseVariations)
	{
		if (Variation)
		{
			CloseWaves.Add(Variation);
		}
	}

	const UPickaxeSCTDefaults* PickaxeDefaults = GetDefaultTemplateSettings<UPickaxeSCTDefaults>();

	TArray<USoundWave*> DistantWaves;
	for (const TObjectPtr<USoundWave>& Variation : PickaxeDefaults->DistantVariations)
	{
		if (Variation)
		{
			DistantWaves.Add(Variation);
		}
	}

	if (CloseWaves.Num() != 0 || DistantWaves.Num() != 0)
	{
		ApplySettings(SoundCue);
		SoundCue.AttenuationSettings = nullptr;

		FFortSoundCueTemplateNodeParams Params;

		if (AddDelayNode(SoundCue, Params, StartDelay))
		{
			Params.InputPinIndex = 0;
		}

		ConstructNode<USoundNodeMixer>(SoundCue, Params);

		if (CloseWaves.Num() > 0)
		{
			FFortSoundCueTemplateNodeParams CloseParams = Params;
			CloseParams.InputPinIndex = 0;

			USoundNodeAttenuation* CloseAttenuationNode = ConstructNode<USoundNodeAttenuation>(SoundCue, CloseParams);
			CloseAttenuationNode->AttenuationSettings = CloseAttenuationSettings;

			if (AddModulatorNode(SoundCue, CloseParams, VolumeModulationRange, PitchModulationRange))
			{
				CloseParams.InputPinIndex = 0;
			}

			AddWavePlayerNodes(SoundCue, CloseParams, CloseWaves, false, true);
			Params.Row += 1 + CloseWaves.Num() / 4;
		}

		if (DistantWaves.Num() > 0)
		{
			FFortSoundCueTemplateNodeParams DistantParams = Params;
			DistantParams.InputPinIndex = 1;

			USoundNodeAttenuation* DistantAttenuationNode = ConstructNode<USoundNodeAttenuation>(SoundCue, DistantParams);
			DistantAttenuationNode->AttenuationSettings = DistantAttenuationSettings;

			if (AddModulatorNode(SoundCue, DistantParams, VolumeModulationRange, PitchModulationRange))
			{
				DistantParams.InputPinIndex = 0;
			}

			AddWavePlayerNodes(SoundCue, DistantParams, DistantWaves, false, true);
			Params.Row += 1 + DistantWaves.Num() / 4;
		}
	}
}

void UPickaxeBase::ValidateTemplateData()
{
	Super::ValidateTemplateData();

	CloseVariations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });

	if (VolumeModulationRange.Equals(FVector2D::UnitVector))
	{
		VolumeModulationRange = FVector2D(0.95f, 1.05f);
	}

	if (PitchModulationRange.Equals(FVector2D::UnitVector))
	{
		PitchModulationRange = FVector2D(0.95f, 1.05f);
	}
}
#endif
