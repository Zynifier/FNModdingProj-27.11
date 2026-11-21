// Copyright Epic Games, Inc. All Rights Reserved.

#include "EmoteSoundCueTemplates.h"
#include "Sound/SoundNodeMixer.h"
#include "Sound/SoundNodeWavePlayer.h"
#include "Sound/SoundWave.h"

UEmoteBase::UEmoteBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	bLinkMuteOthersPin = false;
	bLooping = false;
	bCopyrightedAudio = false;
	LoopDelay = FVector2D::ZeroVector;
#endif
}

void UEmoteBase::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

#if WITH_EDITORONLY_DATA
	if ((Ar.IsLoading() || Ar.IsSaving()) && SoundWave)
	{
		Variations.Add(SoundWave);
		SoundWave = nullptr;
	}
#endif
}

#if WITH_EDITOR
void UEmoteBase::AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves)
{
	for (const TWeakObjectPtr<USoundWave>& Wave : Waves)
	{
		if (Wave.IsValid())
		{
			Variations.Add(Wave.Get());
		}
	}
}

void UEmoteBase::OnRebuildGraph(USoundCue& SoundCue) const
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
		Params.bResetInputPinIndex = true;

		if (bCopyrightedAudio)
		{
			if (AddLicensedContentSwitcherNode(SoundCue, Params, bLooping, bLinkMuteOthersPin))
			{
				Params.InputPinIndex = 2;
				Params.bSetAsParent = true;
			}
		}

		AddDelayNode(SoundCue, Params, StartDelay);

		if (IntroSoundWave)
		{
			ConstructNode<USoundNodeMixer>(SoundCue, Params);
			AddModulatorNode(SoundCue, Params, VolumeModulationRange, PitchModulationRange);

			Params.bSetAsParent = false;
			USoundNodeWavePlayer* IntroWavePlayer = ConstructNode<USoundNodeWavePlayer>(SoundCue, Params);
			IntroWavePlayer->SetSoundWave(IntroSoundWave);
			IntroWavePlayer->bLooping = false;

			++Params.Row;
			++Params.InputPinIndex;
		}

		Params.bSetAsParent = true;
		AddDelayNode(SoundCue, Params, LoopDelay);
		AddModulatorNode(SoundCue, Params, VolumeModulationRange, PitchModulationRange);

		Params.bResetInputPinIndex = false;
		AddWavePlayerNodes(SoundCue, Params, ToRawPtrTArrayUnsafe(Variations), bLooping, true);
	}
}

void UEmoteBase::ApplyBaseSettings(USoundCue& SoundCue) const
{
	Super::ApplyBaseSettings(SoundCue);
	SoundCue.VirtualizationMode = EVirtualizationMode::PlayWhenSilent;
}

void UEmoteBase::ValidateTemplateData()
{
	Super::ValidateTemplateData();

	Variations.RemoveAllSwap([](const USoundWave* Variation) { return Variation == nullptr; });
	LoopDelay = FVector2D(FMath::Min(LoopDelay.X, LoopDelay.Y), FMath::Max(LoopDelay.X, LoopDelay.Y));
}

void UEmoteFoley::ApplyConcurrencySettings(USoundCue& SoundCue) const
{
	SoundCue.bOverrideConcurrency = true;
	SoundCue.ConcurrencyOverrides.bLimitToOwner = false;
	SoundCue.ConcurrencyOverrides.MaxCount = 3;
	SoundCue.ConcurrencyOverrides.ResolutionRule = EMaxConcurrentResolutionRule::StopFarthestThenOldest;
}
#endif
