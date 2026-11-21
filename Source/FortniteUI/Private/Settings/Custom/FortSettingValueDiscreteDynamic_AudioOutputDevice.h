// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioDeviceNotificationSubsystem.h"
#include "AudioMixerBlueprintLibrary.h"
#include "Settings/FortSettingValueDiscreteDynamic.h"
#include "FortSettingValueDiscreteDynamic_AudioOutputDevice.generated.h"

UCLASS()
class UFortSettingValueDiscreteDynamic_AudioOutputDevice : public UFortSettingValueDiscreteDynamic
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void DefaultDeviceChanged(EAudioDeviceChangedRole InRole, const FString& DeviceId);

	UFUNCTION()
	void DeviceAddedOrRemoved(const FString& DeviceId);

	UFUNCTION()
	void DeviceSwitched(const FString& DeviceId);

	UFUNCTION()
	void OnAudioOutputDevicesObtained(const TArray<FAudioOutputDeviceInfo>& AvailableDevices);

	UFUNCTION()
	void OnCompletedDeviceSwap(const FSwapAudioOutputResult& SwapResult);

};

