// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortSoundCueTemplateSimple.h"
#include "Sound/SoundWave.h"

void UFortSoundCueTemplateSimple::PostInitProperties()
{
	Super::PostInitProperties();
}

#if WITH_EDITOR
void UFortSoundCueTemplateSimple::AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves)
{
	for (const TWeakObjectPtr<USoundWave>& Wave : Waves)
	{
		if (Wave.IsValid())
		{
			Variations.Add(Wave.Get());
		}
	}
}

void UFortSoundCueTemplateSimple::OnRebuildGraph(USoundCue& SoundCue) const
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

void UFortSoundCueTemplateSimple::ValidateTemplateData()
{
	Super::ValidateTemplateData();

	Variations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
}
#endif
