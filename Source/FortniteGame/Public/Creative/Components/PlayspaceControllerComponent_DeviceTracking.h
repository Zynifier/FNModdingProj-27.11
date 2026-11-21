// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPath.h"
#include "Building/SpatialGameplay/SpatialEnterExitContext.h"
#include "Components/FortControllerComponent.h"
#include "Creative/Components/PlayspaceComponent_DeviceTracking.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "PlayspaceControllerComponent_DeviceTracking.generated.h"

enum class EDeviceTrackingFilterType : uint8;
enum class EDeviceTrackingSortingType : uint8;

UENUM(BlueprintType)
enum class EDeviceTrackingFilterType : uint8
{
	Undefined = 0,
	Unfiltered = 1 UMETA(DisplayName="All Devices", Tooltip="Get All Devices"),
	WithEventsOrFunctions = 2 UMETA(DisplayName="With Events or Functions", Tooltip="Get All Devices with Events or Functions"),
	WithFunctions = 3 UMETA(DisplayName="With Functions", Tooltip="Get All Devices with Functions"),
	WithEvents = 4 UMETA(DisplayName="With Events", Tooltip="Get All Devices with Events"),
	WithOnlyFunctions = 5 UMETA(DisplayName="With Only Functions", Tooltip="Get All Devices with Functions and no Events"),
	WithOnlyEvents = 6 UMETA(DisplayName="With Only Events", Tooltip="Get All Devices with Events and no Functions"),
	WithBindings = 7 UMETA(DisplayName="With Bindings", Tooltip="Get All Devices with Bindings"),
	/** Unimplemented */
	Favorites = 8 UMETA(DisplayName="Favorites"),
};

UENUM(BlueprintType)
enum class EDeviceTrackingSortingType : uint8
{
	Undefined = 0,
	Default = 1 UMETA(DisplayName="No Sorting"),
	Alphabetical = 2 UMETA(DisplayName="A-Z"),
	ReverseAlphabetical = 3 UMETA(DisplayName="Z-A"),
	/** Unimplemented */
	Favorites = 4 UMETA(DisplayName="Favorites"),
	MostBindingsToLeast = 5 UMETA(DisplayName="Largest Number of Bindings to Smallest"),
	LeastBindingsToMost = 6 UMETA(DisplayName="Smallest Number of Bindings to Largest"),
};

USTRUCT()
struct FBasicDeviceInstanceInfosLookupCallbackPair
{
	GENERATED_BODY()

};

USTRUCT()
struct FDeviceTrackingPageBase
{
	GENERATED_BODY()

private:
	UPROPERTY()
	uint32 PageRequestCounter;

};

USTRUCT()
struct FBasicDeviceTrackingInfosPage : public FDeviceTrackingPageBase
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FBasicDeviceTrackingInfo> BasicDeviceTrackingInfosPage;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UPlayspaceControllerComponent_DeviceTracking : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_BasicDeviceTrackingInfosPage();

	UFUNCTION()
	void OnRep_CurrentSelectedDevice();

	UFUNCTION(Server, Reliable)
	void ServerClearBasicDeviceTrackingInfosPage();

	UPROPERTY()
	TMap<int32, FBasicDeviceTrackingInfo> DeviceGuidToBasicDeviceInfo;

private:
	UFUNCTION(Client, Reliable)
	void ClientAckCurrentSelectedDeviceAlreadyUpToDate();

	UFUNCTION(Client, Reliable)
	void ClientAssignCurrentSelectedDeviceRequestFailed();

	UFUNCTION(Client, Reliable)
	void ClientNotifyFindFailed(bool bShouldBeBlank);

	UFUNCTION(Client, Reliable)
	void ClientRequestBasicDeviceInfoResponse(const int32 DeviceTrackingGUIDRequested, const bool bFoundDeviceInstanceInfo, FBasicDeviceTrackingInfo BasicDeviceInfo);

	UFUNCTION(Client, Reliable)
	void ClientRequestBasicDeviceInfosResponse(const TArray<int32>& DeviceTrackingGUIDsRequested, const TArray<FBasicDeviceTrackingInfo>& BasicDeviceInfos);

	UFUNCTION()
	void OnDeviceChangedInPlayspace(const int32 ChangedDeviceTrackingGUID, const FCreativeDeviceInstanceInfo& ChangedDeviceInfo);

	UFUNCTION()
	void OnDeviceRemovedFromPlayspace(const int32 RemovedDeviceTrackingGUID, const FCreativeDeviceInstanceInfo& RemovedDeviceInfo);

	UFUNCTION()
	void PlayerEnteredSpatialGameplayActor_WithPawn(FEventMessageTag Channel, const FPlayerEnterSpatialActorContextWithPawn& PlayerEnterSpatialActorContext);

	UFUNCTION()
	void PlayerExitSpatialGameplayActor_WithPawn(FEventMessageTag Channel, const FPlayerExitSpatialActorContextWithPawn& PlayerExitSpatialActorContext);

	UFUNCTION(Server, Reliable)
	void ServerAckCurrentSelectedDeviceOnRep();

	UFUNCTION(Server, Reliable)
	void ServerRequestAssignCurrentSelectedDevice(int32 DeviceTrackingGUIDToAssign);

	UFUNCTION(Server, Reliable)
	void ServerRequestBasicDeviceInfo(const int32 DeviceTrackingGUIDRequested);

	UFUNCTION(Server, Reliable)
	void ServerRequestBasicDeviceInfos(const TArray<int32>& DeviceTrackingGUIDsRequested);

	UFUNCTION(Server, Reliable)
	void ServerRequestPageBasicDeviceTrackingInfos(const bool bAddRequestedPageToCurrentPage, const FString& SearchString, const EDeviceTrackingFilterType FilterType, const EDeviceTrackingSortingType SortingType);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRequestTeleportToSpecificDevice(int32 DeviceTrackingGUIDToTeleportTo, const FSoftObjectPath& ObjectPathToTeleportTo) const;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentSelectedDevice)
	FDetailedDeviceTrackingInfo CurrentSelectedDevice;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BasicDeviceTrackingInfosPage)
	FBasicDeviceTrackingInfosPage BasicDeviceTrackingInfosPage;

};

