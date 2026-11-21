// Copyright Epic Games, Inc. All Rights Reserved.

#include "MusicPack.h"
#include "Sound/SoundWave.h"

#if WITH_EDITOR
void UMusicPack::AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves)
{
	for (const TWeakObjectPtr<USoundWave>& Wave : Waves)
	{
		if (Wave.IsValid())
		{
			MusicLoop = Wave.Get();
			break;
		}
	}
}

void UMusicPack::OnRebuildGraph(USoundCue& SoundCue) const
{
	ApplySettings(SoundCue);

	FFortSoundCueTemplateNodeParams Params;
	Params.bResetInputPinIndex = true;

	if (bCopyrightedAudio)
	{
		if (AddLicensedContentSwitcherNode(SoundCue, Params, true, false))
		{
			Params.InputPinIndex = 2;
			Params.bSetAsParent = true;
		}
	}

	if (MusicLoop)
	{
		TArray<USoundWave*> Waves;
		Waves.Add(MusicLoop);

		Params.bResetInputPinIndex = false;
		AddWavePlayerNodes(SoundCue, Params, Waves, true, true);
	}
}

void UMusicPack::ApplyBaseSettings(USoundCue& SoundCue) const
{
	Super::ApplyBaseSettings(SoundCue);
	SoundCue.VirtualizationMode = EVirtualizationMode::PlayWhenSilent;
}
#endif
