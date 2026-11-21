// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeviceTrackingInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UDeviceTrackingInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IDeviceTrackingInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Device Tracking")
	int32 GetDeviceTrackingGUID() const;

	UFUNCTION(BlueprintNativeEvent)
	void SetDeviceTrackingGUID(int32 NewDeviceTrackingGUID);

};

