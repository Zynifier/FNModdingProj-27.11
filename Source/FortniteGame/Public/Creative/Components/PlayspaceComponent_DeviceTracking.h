// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/NetSerialization.h"
#include "UObject/SoftObjectPath.h"
#include "Creative/FortCreativeEventSystemType.h"
#include "PlayspaceComponent.h"
#include "PlayspaceComponent_DeviceTracking.generated.h"

class AActor;
class UObject;

USTRUCT(BlueprintType)
struct FCreativeDeviceEventSubscriptionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CreativeDeviceEventSubscriptionInfo")
	FName FunctionPropertyName;

	UPROPERTY(VisibleInstanceOnly, Category="CreativeDeviceEventSubscriptionInfo")
	TArray<FFortGameplayEventReference> FunctionSubscriptions;

};

USTRUCT(BlueprintType)
struct FCreativeDeviceInstanceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	TSoftObjectPtr<AActor> ActorPtr;

	UPROPERTY()
	FSoftObjectPath ActorPath;

	UPROPERTY(VisibleInstanceOnly, Category="CreativeDeviceInstanceInfo")
	int32 DeviceTrackingGUID;

	UPROPERTY(VisibleInstanceOnly, Category="CreativeDeviceInstanceInfo")
	UClass* Class;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CreativeDeviceInstanceInfo")
	FString Label;

	UPROPERTY(VisibleInstanceOnly, NotReplicated, Category="CreativeDeviceInstanceInfo")
	bool bIsActorCut;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CreativeDeviceInstanceInfo")
	FVector_NetQuantize10 ActorLocation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="CreativeDeviceInstanceInfo")
	TArray<FCreativeDeviceEventSubscriptionInfo> DeviceFunctionSubscriptions;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeviceAddedToPlayspace, const int32, AddedDeviceTrackingGUID, const FCreativeDeviceInstanceInfo&, AddedDeviceInfo);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeviceChangedInPlayspace, const int32, ChangedDeviceTrackingGUID, const FCreativeDeviceInstanceInfo&, ChangedDeviceInfo);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDeviceRemovedFromPlayspace, const int32, RemovedDeviceTrackingGUID, const FCreativeDeviceInstanceInfo&, RemovedDeviceInfo);

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FBasicDeviceTrackingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="BasicDeviceTrackingInfo")
	int32 DeviceTrackingGUID;

	UPROPERTY()
	FSoftObjectPath ActorPath;

	UPROPERTY(BlueprintReadOnly, Category="BasicDeviceTrackingInfo")
	UClass* Class;

	UPROPERTY(BlueprintReadOnly, Category="BasicDeviceTrackingInfo")
	FString Label;

	UPROPERTY(BlueprintReadOnly, Category="BasicDeviceTrackingInfo")
	FVector_NetQuantize10 ActorLocation;

	UPROPERTY()
	uint16 NumBoundFunctions;

	UPROPERTY()
	uint16 NumBoundEvents;

	UPROPERTY()
	int32 CabinModeNameNum;

};

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FDetailedDeviceTrackingInfo : public FCreativeDeviceInstanceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 bServerAndClientBindingsInSync : 1;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_DeviceTracking : public UPlayspaceComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="PlayspaceComponent_DeviceTracking")
	FOnDeviceRemovedFromPlayspace OnDeviceRemovedFromPlayspace;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="PlayspaceComponent_DeviceTracking")
	FOnDeviceAddedToPlayspace OnDeviceAddedToPlayspace;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="PlayspaceComponent_DeviceTracking")
	FOnDeviceChangedInPlayspace OnDeviceChangedInPlayspace;

protected:
	UFUNCTION()
	void OnDeviceEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UPROPERTY(Transient)
	TSet<FString> DeviceLabels;

	UPROPERTY(Transient)
	TSet<FString> ReservedDeviceLabels;

};

