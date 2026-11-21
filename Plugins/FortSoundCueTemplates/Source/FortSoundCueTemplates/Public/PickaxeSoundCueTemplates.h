// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSoundCueTemplateBase.h"
#include "FortSoundCueTemplateSettings.h"
#include "FortSoundCueTemplateSimple.h"
#include "PickaxeSoundCueTemplates.generated.h"

class USoundAttenuation;
class USoundWave;

UCLASS(Abstract, HideCategories=("object", "Object"))
class FORTSOUNDCUETEMPLATES_API UPickaxeBase : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
	UPickaxeBase(const FObjectInitializer& ObjectInitializer);

	virtual void PostLoad() override;

#if WITH_EDITOR
	virtual void AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves) override;
	virtual void LoadTemplateDefaultSettings() override;

protected:
	virtual void OnRebuildGraph(USoundCue& SoundCue) const override;
	virtual void ValidateTemplateData() override;

public:
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves")
	TArray<TObjectPtr<USoundWave>> CloseVariations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Attenuation")
	TObjectPtr<USoundAttenuation> CloseAttenuationSettings;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Attenuation")
	TObjectPtr<USoundAttenuation> DistantAttenuationSettings;
#endif

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UPickaxeImpactEnemy : public UFortSoundCueTemplateSimple
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UPickaxeReady : public UPickaxeBase
{
	GENERATED_BODY()

};

UCLASS()
class UPickaxeSCTDefaults : public UFortSoundCueTemplateDefaults
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="General")
	TObjectPtr<USoundAttenuation> CloseAttenuation;

	UPROPERTY(EditAnywhere, Category="General")
	TObjectPtr<USoundAttenuation> DistantAttenuation;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	TArray<TObjectPtr<USoundWave>> DistantVariations;

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UPickaxeSwing : public UPickaxeBase
{
	GENERATED_BODY()

};

