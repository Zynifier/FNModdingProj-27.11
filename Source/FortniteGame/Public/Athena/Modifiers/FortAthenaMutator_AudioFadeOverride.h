// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_AudioFadeOverride.generated.h"

class USoundMix;

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_AudioFadeOverride : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAudioFade(bool bFadeOut, float FadeTime);

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AudioFadeOverride")
	TObjectPtr<USoundMix> FadeoutSoundMix;

private:
	UFUNCTION()
	void HandleAudioFade(bool bFadeOut, float FadeTime);

};

