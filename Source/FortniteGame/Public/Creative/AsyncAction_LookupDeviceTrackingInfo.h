// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Creative/Components/PlayspaceComponent_DeviceTracking.h"
#include "AsyncAction_LookupDeviceTrackingInfo.generated.h"

class APlayerController;
class IDeviceTrackingInterface;
class UAsyncAction_LookupDeviceTrackingInfo;

USTRUCT(BlueprintType)
struct FTrackedDevicesByEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="TrackedDevicesByEvent")
	FName EventPropertyName;

	UPROPERTY(BlueprintReadOnly, Category="TrackedDevicesByEvent")
	TArray<FBasicDeviceTrackingInfo> DevicesOnEvent;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeviceTrackingLookupComplete, const FCreativeDeviceInstanceInfo&, LookupDevice, const TArray<FTrackedDevicesByEvent>&, EventFunctionToBoundDevices);

UCLASS(MinimalAPI, BlueprintType)
class UAsyncAction_LookupDeviceTrackingInfo : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Online", meta=(BlueprintInternalUseOnly="true"))
	static UAsyncAction_LookupDeviceTrackingInfo* LookupDeviceTrackingInfoAsync(APlayerController* InPlayerController, const TScriptInterface<IDeviceTrackingInterface>& DeviceToLookup);

	UPROPERTY(BlueprintAssignable)
	FOnDeviceTrackingLookupComplete OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FOnDeviceTrackingLookupComplete OnFailure;

protected:
	UFUNCTION()
	void HandleFinishAndDestroy(bool bSuccess);

	UFUNCTION()
	void OnBasicDeviceLookupFinished(const TArray<FBasicDeviceTrackingInfo> BasicDeviceTrackingInfos);

	UFUNCTION()
	void OnFailureToFindLookupDeviceInfo();

	UFUNCTION()
	void OnLookupDeviceInfoUpdated(const FDetailedDeviceTrackingInfo& CurrentSelectedDevice);

	UPROPERTY(Transient)
	int32 DeviceTrackingGuidToLookup;

	UPROPERTY(Transient)
	FDetailedDeviceTrackingInfo LookupDeviceInfo;

	UPROPERTY(Transient)
	TArray<int32> RequestedDeviceTrackingGuids;

	UPROPERTY(Transient)
	TArray<FTrackedDevicesByEvent> EventFunctionsToBoundDevicesOfLookupDevice;

};

