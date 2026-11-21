// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortSoundCueTemplateBase.h"
#include "FortSoundCueTemplateSettings.h"
#include "FortSoundCueTemplateSimple.h"
#include "GliderSoundCueTemplates.generated.h"

class USoundWave;

USTRUCT(BlueprintType)
struct FGliderThrustData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Params")
	FName ParameterName;

	UPROPERTY(EditAnywhere, Category="Params")
	FVector2D PitchOutput = FVector2D(0.0f, 1.0f);

	UPROPERTY(EditAnywhere, Category="Params")
	FVector2D VolumeOutput = FVector2D(0.0f, 1.0f);

	UPROPERTY(EditAnywhere, Category="Params")
	TObjectPtr<USoundWave> Sound;

	UPROPERTY(EditAnywhere, Category="Config")
	FFortContinuousModulatorConfig Settings;

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UGliderClose : public UFortSoundCueTemplateSimple
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UGliderOpen : public UFortSoundCueTemplateSimple
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UGliderThrustLoop : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
	UGliderThrustLoop(const FObjectInitializer& ObjectInitializer);

#if WITH_EDITOR
	virtual void AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves) override;
	virtual void LoadTemplateDefaultSettings() override;

protected:
	virtual void OnRebuildGraph(USoundCue& SoundCue) const override;
	virtual bool GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const override;

private:
	void AddThrustLayer(USoundCue& SoundCue, const FGliderThrustData& ThrustData, FFortSoundCueTemplateNodeParams& Params) const;

public:
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Thrust")
	FGliderThrustData Forward;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Thrust")
	FGliderThrustData Sideways;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Thrust")
	FGliderThrustData Backwards;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Thrust")
	FGliderThrustData AnyDirection;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(UIMax="1", UIMin="0"))
	float ForwardsParamPreviewValue;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(UIMax="1", UIMin="0"))
	float SidewaysParamPreviewValue;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(UIMax="1", UIMin="0"))
	float BackwardsParamPreviewValue;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Auditioning", meta=(UIMax="1", UIMin="0"))
	float AnyDirectionParamPreviewValue;
#endif

};

UCLASS()
class UGliderThrustSCTDefaults : public UFortSoundCueTemplateDefaults
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Glider")
	FGliderThrustData Forward;

	UPROPERTY(EditDefaultsOnly, Category="Glider")
	FGliderThrustData Sideways;

	UPROPERTY(EditDefaultsOnly, Category="Glider")
	FGliderThrustData Backwards;

	UPROPERTY(EditDefaultsOnly, Category="Glider")
	FGliderThrustData AnyDirection;

};

UCLASS(BlueprintType, HideCategories=("object", "object", "Object"))
class FORTSOUNDCUETEMPLATES_API UGliderThrustStart : public UFortSoundCueTemplateBase
{
	GENERATED_BODY()

public:
	UGliderThrustStart(const FObjectInitializer& ObjectInitializer);

#if WITH_EDITOR
	virtual void AddSoundWaves(TArray<TWeakObjectPtr<USoundWave>>& Waves) override;

protected:
	virtual void OnRebuildGraph(USoundCue& SoundCue) const override;
	virtual void ValidateTemplateData() override;

public:
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Thrust")
	TArray<TObjectPtr<USoundWave>> Variations;
#endif

};

