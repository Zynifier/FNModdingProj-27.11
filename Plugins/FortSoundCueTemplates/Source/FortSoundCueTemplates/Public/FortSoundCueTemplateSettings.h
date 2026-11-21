// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DeveloperSettings.h"
#include "Math/MathFwd.h"
#include "Sound/SoundNodeModulatorContinuous.h"
#include "FortSoundCueTemplateSettings.generated.h"

class UAudioBus;
class UFortSoundCueTemplateBase;
class UFortSoundCueTemplateDefaultSettings;
class UFortSoundCueTemplateDefaults;
class USoundAttenuation;
class USoundClass;
class USoundConcurrency;
class USoundSourceBus;
class USoundSubmixBase;
class USoundWave;

USTRUCT()
struct FFortBusPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Submix")
	TObjectPtr<USoundSourceBus> SourceBus;

	UPROPERTY(EditDefaultsOnly, Category="Submix")
	TObjectPtr<UAudioBus> AudioBus;

	UPROPERTY(EditDefaultsOnly, Category="Submix")
	float SendAmount;

};

USTRUCT()
struct FORTSOUNDCUETEMPLATES_API FFortContinuousModulatorConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Params")
	FVector2D VolumeRange;

	UPROPERTY(EditAnywhere, Category="Params")
	FVector2D PitchRange;

	UPROPERTY(EditAnywhere, Category="Params")
	TEnumAsByte<ModulationParamMode> VolumeMode;

	UPROPERTY(EditAnywhere, Category="Params")
	TEnumAsByte<ModulationParamMode> PitchMode;

};

USTRUCT()
struct FFortSubmixPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Submix")
	TObjectPtr<USoundSubmixBase> Submix;

	UPROPERTY(EditDefaultsOnly, Category="Submix")
	float SendAmount;

};

UCLASS()
class UFortSoundCueTemplateDefaultSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION()
	UFortSoundCueTemplateDefaults* GetSettingsForTemplateType(TSubclassOf<UFortSoundCueTemplateBase> TemplateType);

	UPROPERTY(EditDefaultsOnly, Category="DefaultSettings")
	TMap<TSubclassOf<UFortSoundCueTemplateBase>, TObjectPtr<UFortSoundCueTemplateDefaults>> TemplateDefaults;

};

UCLASS()
class UFortSoundCueTemplateDefaults : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="General")
	TObjectPtr<USoundClass> SoundClass;

	UPROPERTY(EditDefaultsOnly, Category="General")
	TObjectPtr<USoundAttenuation> Attenuation;

	UPROPERTY(EditDefaultsOnly, Category="General")
	TObjectPtr<USoundConcurrency> Concurrency;

	UPROPERTY(EditDefaultsOnly, Category="General")
	float VolumeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="General")
	float PitchMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Submix")
	TArray<FFortSubmixPair> SubmixSends;

	UPROPERTY(EditDefaultsOnly, Category="Submix")
	TArray<FFortBusPair> PreEffectBusSends;

	UPROPERTY(EditDefaultsOnly, Category="Submix")
	TArray<FFortBusPair> PostEffectBusSends;

	UPROPERTY(EditDefaultsOnly, Category="Copyright")
	TObjectPtr<USoundWave> LicensedTrackAlternative;

	UPROPERTY(EditDefaultsOnly, Category="Copyright")
	TObjectPtr<USoundSubmixBase> LicensedSubmix;

};

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Fortnite Sound Cue Templates"))
class UFortSoundCueTemplateSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UFUNCTION()
	UFortSoundCueTemplateDefaults* GetDefaultSettingsForTemplateType(TSubclassOf<UFortSoundCueTemplateBase> TemplateType) const;

	UPROPERTY(EditDefaultsOnly, Config, Category="Config")
	TSoftObjectPtr<UFortSoundCueTemplateDefaultSettings> DefaultTemplateSettings;

};

