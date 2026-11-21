// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/AsyncAction_LookupDeviceTrackingInfo.h"

void UAsyncAction_LookupDeviceTrackingInfo::HandleFinishAndDestroy(bool bSuccess)
{
}

UAsyncAction_LookupDeviceTrackingInfo* UAsyncAction_LookupDeviceTrackingInfo::LookupDeviceTrackingInfoAsync(APlayerController* InPlayerController, const TScriptInterface<IDeviceTrackingInterface>& DeviceToLookup)
{
	return nullptr;
}

void UAsyncAction_LookupDeviceTrackingInfo::OnBasicDeviceLookupFinished(const TArray<FBasicDeviceTrackingInfo> BasicDeviceTrackingInfos)
{
}

void UAsyncAction_LookupDeviceTrackingInfo::OnFailureToFindLookupDeviceInfo()
{
}

void UAsyncAction_LookupDeviceTrackingInfo::OnLookupDeviceInfoUpdated(const FDetailedDeviceTrackingInfo& CurrentSelectedDevice)
{
}
