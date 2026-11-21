// Copyright Epic Games, Inc. All Rights Reserved.

#include "Settings/Custom/FortSettingValueDiscreteDynamic_AudioOutputDevice.h"

void UFortSettingValueDiscreteDynamic_AudioOutputDevice::DefaultDeviceChanged(EAudioDeviceChangedRole InRole, const FString& DeviceId)
{
}

void UFortSettingValueDiscreteDynamic_AudioOutputDevice::DeviceAddedOrRemoved(const FString& DeviceId)
{
}

void UFortSettingValueDiscreteDynamic_AudioOutputDevice::DeviceSwitched(const FString& DeviceId)
{
}

void UFortSettingValueDiscreteDynamic_AudioOutputDevice::OnAudioOutputDevicesObtained(const TArray<FAudioOutputDeviceInfo>& AvailableDevices)
{
}

void UFortSettingValueDiscreteDynamic_AudioOutputDevice::OnCompletedDeviceSwap(const FSwapAudioOutputResult& SwapResult)
{
}
