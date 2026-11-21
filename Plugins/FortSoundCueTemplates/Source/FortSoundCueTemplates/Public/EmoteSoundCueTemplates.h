// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortSoundCueTemplateBase.h"
#include "EmoteSoundCueTemplates.generated.h"

class USoundWave;

UCLASS(Abstract, HideCategories=("object", "Object"))
class FORTSOUNDCUETEMPLATES_API UEmoteBase : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
	UEmoteBase(const FObjectInitializer& ObjectInitializer);

	virtual void Serialize(FArchive& Ar) override;

#if WITH_EDITOR
	virtual void AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves) override;

protected:
	virtual void OnRebuildGraph(USoundCue& SoundCue) const override;
	virtual void ApplyBaseSettings(USoundCue& SoundCue) const override;
	virtual void ValidateTemplateData() override;

public:
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="OldEmoteData", meta=(DeprecatedProperty, DeprecationMessage="Use Variations array instead."))
	TObjectPtr<USoundWave> SoundWave;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="EmoteData")
	TArray<TObjectPtr<USoundWave>> Variations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="EmoteData")
	uint8 bLooping : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="EmoteData")
	uint8 bCopyrightedAudio : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="EmoteIntroData")
	TObjectPtr<USoundWave> IntroSoundWave;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="EmoteData")
	FVector2D LoopDelay;
#endif

#if WITH_EDITORONLY_DATA
private:
	bool bLinkMuteOthersPin;
#endif

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UEmoteFoley : public UEmoteBase
{
	GENERATED_BODY()

#if WITH_EDITOR
protected:
	virtual void ApplyConcurrencySettings(USoundCue& SoundCue) const override;
#endif

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UEmoteMusic : public UEmoteBase
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UEmoteMusic3P : public UEmoteBase
{
	GENERATED_BODY()

};

