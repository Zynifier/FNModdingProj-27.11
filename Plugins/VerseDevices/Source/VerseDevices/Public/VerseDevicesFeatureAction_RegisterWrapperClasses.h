// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "VerseDevicesFeatureAction_RegisterWrapperClasses.generated.h"

class UVerseDeviceWrapperClassMap;

UCLASS(MinimalAPI, meta=(DisplayName="Register Device Verse Wrapper Classes"))
class UVerseDevicesFeatureAction_RegisterWrapperClasses : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Devices")
	TSoftObjectPtr<UVerseDeviceWrapperClassMap> DeviceToWrapperClassMapAsset;

};

