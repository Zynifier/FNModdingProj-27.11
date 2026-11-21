// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortCreativeStreamingController.generated.h"

class AActor;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCDeviceUnregistered, AActor*, DeviceRemoved);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnControllingStreamDeviceChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeviceArrayUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeviceRegistered, AActor*, DeviceAdded);

USTRUCT()
struct FORTNITEGAME_API FReplicatedStreamingProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TSoftObjectPtr<AActor> CurrentStreamingDevice;

	UPROPERTY(Transient)
	TSoftObjectPtr<AActor> OverrideStreamingDevice;

	UPROPERTY(Transient)
	TArray<TSoftObjectPtr<AActor>> StreamingDevices;

};

UCLASS()
class FORTNITEGAME_API AFortCreativeStreamingController : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearOverrideStreamingDevice(const AActor* ExpectedOverrideStreamingDevice);

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<AActor> GetControllingStreamingDevice() const;

	UFUNCTION(BlueprintCallable)
	AActor* GetDeviceByName(const FString& DeviceName);

	UFUNCTION(BlueprintCallable)
	void GetStreamingDevices(TArray<AActor*>& OutArray);

	UFUNCTION(BlueprintCallable)
	void RecalculateStreamingPriorities();

	UFUNCTION(BlueprintCallable)
	void RegisterDevice(TSoftObjectPtr<AActor> DeviceToRegister);

	UFUNCTION(BlueprintCallable)
	void SetOverrideStreamingDevice(const AActor* NewOverrideStreamingDevice);

	UFUNCTION(BlueprintCallable)
	void UnregisterDevice(TSoftObjectPtr<AActor> DeviceToUnregister);

	UPROPERTY(BlueprintReadWrite, Transient, BlueprintAssignable, Category="FortCreativeStreamingController")
	FOnControllingStreamDeviceChanged OnControllingStreamDeviceChanged;

	UPROPERTY(BlueprintReadWrite, Transient, BlueprintAssignable, Category="FortCreativeStreamingController")
	FOnDeviceArrayUpdated OnDeviceArrayUpdated;

	UPROPERTY(BlueprintReadWrite, Transient, BlueprintAssignable, Category="FortCreativeStreamingController")
	FOnDeviceRegistered OnDeviceRegistered;

	UPROPERTY(BlueprintReadWrite, Transient, BlueprintAssignable, Category="FortCreativeStreamingController")
	FOnCDeviceUnregistered OnDeviceUnregistered;

private:
	UFUNCTION()
	void OnRep_ReplicatedStreamingActors();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedStreamingActors)
	FReplicatedStreamingProperties ReplicatedStreamingProperties;

};

