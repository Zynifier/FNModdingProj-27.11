// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Sound/SoundNodeDistanceCrossFade.h"
#include "FortSoundCueTemplateBase.h"
#include "FortSoundCueTemplateSettings.h"
#include "Physics.generated.h"

class USoundWave;

USTRUCT(BlueprintType)
struct FPhysicsImpactData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Params")
	FVector2D VolumeOutput = FVector2D(0.0f, 1.0f);

	UPROPERTY(EditAnywhere, Category="Params")
	FVector2D PitchOutput = FVector2D(0.0f, 1.0f);

	UPROPERTY(VisibleAnywhere, Category="Params")
	FFortContinuousModulatorConfig Settings;

	UPROPERTY(EditAnywhere, Category="Params")
	TArray<TObjectPtr<USoundWave>> Variations;

};

USTRUCT(BlueprintType)
struct FPhysicsStateData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Params")
	FName ParameterName;

	UPROPERTY(EditAnywhere, Category="Params")
	FVector2D VolumeOutput = FVector2D(0.0f, 1.0f);

	UPROPERTY(EditAnywhere, Category="Params")
	FVector2D PitchOutput = FVector2D(0.0f, 1.0f);

	UPROPERTY(VisibleAnywhere, Category="Params")
	FFortContinuousModulatorConfig Settings;

	UPROPERTY(EditAnywhere, Category="Params")
	FDistanceDatum CrossfadeInputSlow;

	UPROPERTY(EditAnywhere, Category="Params")
	TObjectPtr<USoundWave> SlowLoop;

	UPROPERTY(EditAnywhere, Category="Params")
	FDistanceDatum CrossfadeInputFast;

	UPROPERTY(EditAnywhere, Category="Params")
	TObjectPtr<USoundWave> FastLoop;

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UPhysicsImpact : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
	UPhysicsImpact(const FObjectInitializer& ObjectInitializer);

#if WITH_EDITOR
	virtual void AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves) override;
	virtual void LoadTemplateDefaultSettings() override;

protected:
	virtual void OnRebuildGraph(USoundCue& SoundCue) const override;
	virtual bool GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const override;

private:
	void AddImpactLayer(USoundCue& SoundCue, const FPhysicsImpactData& ImpactData, const FName& LayerName, FFortSoundCueTemplateNodeParams& Params) const;

public:
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Data")
	FName ImpactTypeParameterName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Data")
	FName StrengthParameterName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Data")
	FPhysicsImpactData Light;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Data")
	FPhysicsImpactData Medium;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Data")
	FPhysicsImpactData Heavy;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(ClampMax="2", ClampMin="0"))
	int32 ImpactTypeParamPreviewValue;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(ClampMax="1", ClampMin="0"))
	float StrengthParamPreviewValue;
#endif

};

UCLASS()
class UPhysicsImpactSCTDefaults : public UFortSoundCueTemplateDefaults
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Data")
	FName ImpactTypeParameterName;

	UPROPERTY(VisibleAnywhere, Category="Data")
	FName StrengthParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FPhysicsImpactData Light;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FPhysicsImpactData Medium;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FPhysicsImpactData Heavy;

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UPhysicsStateLoop : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
	UPhysicsStateLoop(const FObjectInitializer& ObjectInitializer);

#if WITH_EDITOR
	virtual void AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves) override;
	virtual void LoadTemplateDefaultSettings() override;

protected:
	virtual void OnRebuildGraph(USoundCue& SoundCue) const override;
	virtual bool GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const override;

private:
	void AddStateLayer(USoundCue& SoundCue, const FPhysicsStateData& StateData, FFortSoundCueTemplateNodeParams& Params) const;

public:
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Data")
	FName SpeedParameterName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Data")
	FPhysicsStateData Rolling;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Data")
	FPhysicsStateData Sliding;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Data")
	FPhysicsStateData Flying;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Data")
	FPhysicsStateData Floating;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(ClampMax="1", ClampMin="0"))
	float SpeedParamPreviewValue;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(ClampMax="1", ClampMin="0"))
	float RollingParamPreviewValue;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(ClampMax="1", ClampMin="0"))
	float SlidingParamPreviewValue;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(ClampMax="1", ClampMin="0"))
	float FlyingParamPreviewValue;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(ClampMax="1", ClampMin="0"))
	float FloatingParamPreviewValue;
#endif

};

UCLASS()
class UPhysicsStateSCTDefaults : public UFortSoundCueTemplateDefaults
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Data")
	FName SpeedParameterName;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FPhysicsStateData Rolling;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FPhysicsStateData Sliding;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FPhysicsStateData Flying;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	FPhysicsStateData Floating;

};

