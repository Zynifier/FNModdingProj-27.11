// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Components/PlayspaceComponent_DeviceTracking.h"
#include "FortPlaylistUserOptions.h"
#include "FortUserOptionEventContainerProxy.generated.h"

UCLASS()
class UFortUserOptionEventContainerProxy : public UFortUserOptionProxy
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnMatchmakingDialogDeactivated();

	UFUNCTION()
	void OnRequestedDeviceChanged(const int32 DeviceGUID);

	UPROPERTY()
	TMap<int32, FBasicDeviceTrackingInfo> DeviceGuidToBasicDeviceInfo;

};

