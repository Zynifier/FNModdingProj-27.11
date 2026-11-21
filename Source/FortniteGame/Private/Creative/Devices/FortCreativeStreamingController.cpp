// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Devices/FortCreativeStreamingController.h"
#include "Net/UnrealNetwork.h"

void AFortCreativeStreamingController::ClearOverrideStreamingDevice(const AActor* ExpectedOverrideStreamingDevice)
{
}

TSoftObjectPtr<AActor> AFortCreativeStreamingController::GetControllingStreamingDevice() const
{
	return TSoftObjectPtr<AActor>();
}

AActor* AFortCreativeStreamingController::GetDeviceByName(const FString& DeviceName)
{
	return nullptr;
}

void AFortCreativeStreamingController::GetStreamingDevices(TArray<AActor*>& OutArray)
{
}

void AFortCreativeStreamingController::OnRep_ReplicatedStreamingActors()
{
}

void AFortCreativeStreamingController::RecalculateStreamingPriorities()
{
}

void AFortCreativeStreamingController::RegisterDevice(TSoftObjectPtr<AActor> DeviceToRegister)
{
}

void AFortCreativeStreamingController::SetOverrideStreamingDevice(const AActor* NewOverrideStreamingDevice)
{
}

void AFortCreativeStreamingController::UnregisterDevice(TSoftObjectPtr<AActor> DeviceToUnregister)
{
}

void AFortCreativeStreamingController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCreativeStreamingController, ReplicatedStreamingProperties);
}
