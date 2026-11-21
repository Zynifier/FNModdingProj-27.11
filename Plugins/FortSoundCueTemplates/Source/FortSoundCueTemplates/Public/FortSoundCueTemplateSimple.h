// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSoundCueTemplateBase.h"
#include "FortSoundCueTemplateSimple.generated.h"

class USoundWave;

UCLASS(Abstract, HideCategories=("object", "Object"))
class FORTSOUNDCUETEMPLATES_API UFortSoundCueTemplateSimple : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
	virtual void PostInitProperties() override;

#if WITH_EDITOR
	virtual void AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves) override;

protected:
	virtual void OnRebuildGraph(USoundCue& SoundCue) const override;
	virtual void ValidateTemplateData() override;

public:
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves")
	TArray<TObjectPtr<USoundWave>> Variations;
#endif

};

