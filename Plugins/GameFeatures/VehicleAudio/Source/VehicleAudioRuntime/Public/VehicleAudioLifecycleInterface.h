// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VehicleAudioLifecycleInterface.generated.h"

UINTERFACE(MinimalAPI)
class UVehicleAudioLifecycleInterface : public UInterface
{
	GENERATED_BODY()
};

class VEHICLEAUDIORUNTIME_API IVehicleAudioLifecycleInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="VehicleAudio")
	void OnInit();

	UFUNCTION(BlueprintNativeEvent, Category="VehicleAudio")
	void OnShutdown();

	UFUNCTION(BlueprintNativeEvent, Category="VehicleAudio")
	void OnUpdate(float DeltaSeconds);

};

