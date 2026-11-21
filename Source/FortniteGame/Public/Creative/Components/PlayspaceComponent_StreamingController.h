// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Sound/SoundAttenuation.h"
#include "PlayspaceComponent.h"
#include "PlayspaceComponent_StreamingController.generated.h"

class AController;
class AFortCreativeStreamingController;
class AFortPlayspace;
class ULevelSequence;
class UPlayspaceComponent_StreamingController;

USTRUCT(BlueprintType)
struct FDeviceAudioSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="DeviceAudioSettings")
	float fVolumeMultiplier;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeviceAudioSettings")
	bool bOverrideAttenuation;

	UPROPERTY(BlueprintReadWrite, Transient, Category="DeviceAudioSettings")
	FSoundAttenuationSettings AttenuationSettings;

};

USTRUCT(BlueprintType)
struct FVideoPlayerDeviceMediaMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="VideoPlayerDeviceMediaMetadata")
	FString UID;

	UPROPERTY(BlueprintReadWrite, Transient, Category="VideoPlayerDeviceMediaMetadata")
	FDateTime ServerTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="VideoPlayerDeviceMediaMetadata")
	FDateTime StartTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="VideoPlayerDeviceMediaMetadata")
	TArray<AController*> Instigators;

	UPROPERTY(BlueprintReadWrite, Transient, Category="VideoPlayerDeviceMediaMetadata")
	int32 InstanceId;

	UPROPERTY(BlueprintReadWrite, Transient, Category="VideoPlayerDeviceMediaMetadata")
	bool bLooping;

	UPROPERTY(BlueprintReadWrite, Category="VideoPlayerDeviceMediaMetadata")
	ULevelSequence* Sequence;

	UPROPERTY(BlueprintReadWrite, Category="VideoPlayerDeviceMediaMetadata")
	bool bOverride;

};

UINTERFACE(BlueprintType, Blueprintable)
class FORTNITEGAME_API UFortStreamingDeviceInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortStreamingDeviceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="FortStreamingInterface")
	void GetDeviceStreamingAudioSettings(FDeviceAudioSettings& OutAudioSettings) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="FortStreamingInterface")
	void GetDeviceStreamingPriority(float& OutStreamingPriority) const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortStreamingInterface")
	void GetVideoDeviceMediaMetadata(FVideoPlayerDeviceMediaMetadata& OutMediaMetadata) const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortStreamingInterface")
	void IsDeviceEnabled(bool& OutIsEnabled) const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortStreamingInterface")
	void IsExcludedFromPriority(bool& OutIsExcluded) const;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UPlayspaceComponent_StreamingController : public UPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UPlayspaceComponent_StreamingController* GetOrCreateComponent(AFortPlayspace* Owner);

	UFUNCTION(BlueprintCallable)
	AFortCreativeStreamingController* GetStreamingController();

private:
	UPROPERTY(Transient, Replicated)
	AFortCreativeStreamingController* FortCreativeStreamingController;

};

