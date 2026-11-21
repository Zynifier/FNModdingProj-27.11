// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundNodeDistanceCrossFade.h"
#include "Components/FortFootstepComponent.h"
#include "FortSoundCueTemplateBase.h"
#include "FortSoundCueTemplateSettings.h"
#include "PlayerFoley.generated.h"

class USoundAttenuation;
class USoundClass;
class USoundWave;

UCLASS(Abstract, HideCategories=("object", "Object"))
class FORTSOUNDCUETEMPLATES_API UPlayerFoleyBase : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
	UPlayerFoleyBase(const FObjectInitializer& ObjectInitializer);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TemplateSettings")
	int32 MaxVariations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TemplateSettings")
	int32 MaxVariationsMobile;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning")
	EFortFootstepPlayerRelation RelationToPlayer;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(EditCondition="bUsingStances"))
	EFortFootstepStanceType StepType;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(ClampMax="1.0", ClampMin="-1.0"))
	float Elevation;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(ClampMin="0.0"))
	float Distance;
#endif

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UPlayerFoley : public UPlayerFoleyBase
{
	GENERATED_BODY()

public:
	UPlayerFoley(const FObjectInitializer& ObjectInitializer);

#if WITH_EDITOR
	virtual void AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves) override;

protected:
	virtual void OnRebuildGraph(USoundCue& SoundCue) const override;
	virtual bool GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const override;
	virtual void ValidateTemplateData() override;

private:
	USoundNode* AddVariationLayer(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const TArray<TObjectPtr<USoundWave>>& Waves, float Volume) const;
	void AddElevationLayers(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, TArray<USoundNode*>& OutElevationNodes) const;

public:
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves")
	TArray<TObjectPtr<USoundWave>> WaveVariations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> WalkVariations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> RunVariations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> SprintVariations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> CrouchWalkVariations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> CrouchRunVariations;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> WalkVariationsAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> RunVariationsAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> SprintVariationsAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> CrouchWalkVariationsAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Waves|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	TArray<TObjectPtr<USoundWave>> CrouchRunVariationsAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes")
	float VariationVolume;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance", meta=(EditCondition="bUsingStances"))
	float WalkVolume;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance", meta=(EditCondition="bUsingStances"))
	float RunVolume;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance", meta=(EditCondition="bUsingStances"))
	float SprintVolume;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance", meta=(EditCondition="bUsingStances"))
	float CrouchWalkVolume;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance", meta=(EditCondition="bUsingStances"))
	float CrouchRunVolume;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	float WalkVolumeAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	float RunVolumeAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	float SprintVolumeAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	float CrouchWalkVolumeAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MixVolumes|Stance|AboveBelow", meta=(EditCondition="bUsingStances"))
	float CrouchRunVolumeAboveBelow;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TemplateSettings")
	bool bUsingStances;
#endif

};

UCLASS()
class UPlayerFoleyDefaults : public UFortSoundCueTemplateDefaults
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SoundClass")
	TObjectPtr<USoundClass> LocalPlayerSoundClass;

	UPROPERTY(EditDefaultsOnly, Category="SoundClass")
	TObjectPtr<USoundClass> TeammateSoundClass;

	UPROPERTY(EditDefaultsOnly, Category="SoundClass")
	TObjectPtr<USoundClass> HostileSoundClass;

	UPROPERTY(EditDefaultsOnly, Category="Attenuation")
	TObjectPtr<USoundAttenuation> LocalPlayerAttenuation;

	UPROPERTY(EditDefaultsOnly, Category="Attenuation")
	TObjectPtr<USoundAttenuation> AboveAttenuation;

	UPROPERTY(EditDefaultsOnly, Category="Attenuation")
	TObjectPtr<USoundAttenuation> BelowAttenuation;

	UPROPERTY(EditDefaultsOnly, Category="Attenuation")
	TObjectPtr<USoundAttenuation> ParallelAttenuation;

	UPROPERTY(EditDefaultsOnly, Category="CrossfadeData")
	TArray<FDistanceDatum> ElevationCrossfadeDistances;

};

