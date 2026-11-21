// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "UObject/SoftObjectPath.h"
#include "AudioWorldizationSettings.generated.h"

class UAudioWorldizationTraceDirectionPolicyBase;
class UAudioWorldizationTracePolicyBase;
class USoundControlBus;
class USoundEffectSubmixPreset;
class USoundModulatorBase;
class USoundSubmix;

USTRUCT()
struct FAudioWorldizationQuadrantSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Modulation")
	TObjectPtr<USoundControlBus> WallDistanceBus;

	UPROPERTY(EditAnywhere, Category="Modulation")
	TObjectPtr<USoundControlBus> EnclosureBus;

};

USTRUCT()
struct FAudioWorldizationGlobalSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AudioWorldizationGlobalSettings")
	float EffectCrossfadeTime;

	UPROPERTY(EditAnywhere, Category="AudioWorldizationGlobalSettings")
	FName IgnoreTraceActorTag;

	UPROPERTY(EditAnywhere, Category="Modulation")
	TObjectPtr<USoundControlBus> EnclosureBus;

	UPROPERTY(EditAnywhere, Category="Modulation")
	TObjectPtr<USoundControlBus> WallDistanceBus;

	UPROPERTY(EditAnywhere, Category="Modulation")
	TObjectPtr<USoundControlBus> ListenerAzimuthBus;

	UPROPERTY(EditAnywhere, Category="Modulation")
	TArray<FAudioWorldizationQuadrantSettings> Quadrants;

};

USTRUCT(BlueprintType)
struct AUDIOWORLDIZATION_API FAudioWorldizationSend
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AudioWorldizationSend")
	TObjectPtr<USoundSubmix> Submix;

	UPROPERTY(EditAnywhere, Category="AudioWorldizationSend")
	TSet<TObjectPtr<USoundModulatorBase>> VolumeModulators;

	UPROPERTY(EditAnywhere, Category="AudioWorldizationSend")
	TArray<TObjectPtr<USoundEffectSubmixPreset>> EffectChain;

};

USTRUCT(BlueprintType)
struct AUDIOWORLDIZATION_API FAudioWorldizationSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AudioWorldizationSettings")
	FName Identifier;

	UPROPERTY(EditAnywhere, Category="Reverb")
	TArray<FAudioWorldizationSend> Sends;

	UPROPERTY(EditAnywhere, Category="Smoothing")
	float EnclosureSmoothSpeed;

	UPROPERTY(EditAnywhere, Category="Smoothing")
	float WallDistanceSmoothSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Traces")
	float TraceRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Traces")
	int32 TracePoints;

	UPROPERTY(EditAnywhere, Category="Traces")
	int32 TracesPerFrame;

	UPROPERTY(EditAnywhere, Category="Traces")
	float SideQuadrantDegrees;

	UPROPERTY(EditAnywhere, Category="Traces")
	float UpQuadrantDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Traces")
	FVector TraceOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Traces")
	TEnumAsByte<ECollisionChannel> TraceChannel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Traces")
	TArray<TEnumAsByte<ECollisionChannel>> ResponseChannels;

	UPROPERTY(EditAnywhere, Category="Traces")
	TSubclassOf<UAudioWorldizationTracePolicyBase> TracePolicy;

	UPROPERTY(EditAnywhere, Category="Traces")
	TSubclassOf<UAudioWorldizationTraceDirectionPolicyBase> TraceDirectionPolicy;

};

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Audio Worldization"))
class UAudioWorldizationDefaultSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="AudioWorldizationDefaultSettings")
	FAudioWorldizationGlobalSettings GlobalSettings;

	UPROPERTY(EditAnywhere, Config, Category="AudioWorldizationDefaultSettings")
	FAudioWorldizationSettings DefaultSettings;

	UPROPERTY(EditAnywhere, Config, Category="Parameters", meta=(AllowedClasses="/Script/AudioModulation.SoundModulationParameter"))
	TArray<FSoftObjectPath> ModulationParameters;

};

