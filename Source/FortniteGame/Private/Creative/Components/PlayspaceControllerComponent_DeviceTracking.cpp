// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/PlayspaceControllerComponent_DeviceTracking.h"
#include "Net/UnrealNetwork.h"

void UPlayspaceControllerComponent_DeviceTracking::ClientAckCurrentSelectedDeviceAlreadyUpToDate_Implementation()
{
}

void UPlayspaceControllerComponent_DeviceTracking::ClientAssignCurrentSelectedDeviceRequestFailed_Implementation()
{
}

void UPlayspaceControllerComponent_DeviceTracking::ClientNotifyFindFailed_Implementation(bool bShouldBeBlank)
{
}

void UPlayspaceControllerComponent_DeviceTracking::ClientRequestBasicDeviceInfoResponse_Implementation(const int32 DeviceTrackingGUIDRequested, const bool bFoundDeviceInstanceInfo, FBasicDeviceTrackingInfo BasicDeviceInfo)
{
}

void UPlayspaceControllerComponent_DeviceTracking::ClientRequestBasicDeviceInfosResponse_Implementation(const TArray<int32>& DeviceTrackingGUIDsRequested, const TArray<FBasicDeviceTrackingInfo>& BasicDeviceInfos)
{
}

void UPlayspaceControllerComponent_DeviceTracking::OnDeviceChangedInPlayspace(const int32 ChangedDeviceTrackingGUID, const FCreativeDeviceInstanceInfo& ChangedDeviceInfo)
{
}

void UPlayspaceControllerComponent_DeviceTracking::OnDeviceRemovedFromPlayspace(const int32 RemovedDeviceTrackingGUID, const FCreativeDeviceInstanceInfo& RemovedDeviceInfo)
{
}

void UPlayspaceControllerComponent_DeviceTracking::OnRep_BasicDeviceTrackingInfosPage()
{
}

void UPlayspaceControllerComponent_DeviceTracking::OnRep_CurrentSelectedDevice()
{
}

void UPlayspaceControllerComponent_DeviceTracking::PlayerEnteredSpatialGameplayActor_WithPawn(FEventMessageTag Channel, const FPlayerEnterSpatialActorContextWithPawn& PlayerEnterSpatialActorContext)
{
}

void UPlayspaceControllerComponent_DeviceTracking::PlayerExitSpatialGameplayActor_WithPawn(FEventMessageTag Channel, const FPlayerExitSpatialActorContextWithPawn& PlayerExitSpatialActorContext)
{
}

void UPlayspaceControllerComponent_DeviceTracking::ServerAckCurrentSelectedDeviceOnRep_Implementation()
{
}

void UPlayspaceControllerComponent_DeviceTracking::ServerClearBasicDeviceTrackingInfosPage_Implementation()
{
}

void UPlayspaceControllerComponent_DeviceTracking::ServerRequestAssignCurrentSelectedDevice_Implementation(int32 DeviceTrackingGUIDToAssign)
{
}

void UPlayspaceControllerComponent_DeviceTracking::ServerRequestBasicDeviceInfo_Implementation(const int32 DeviceTrackingGUIDRequested)
{
}

void UPlayspaceControllerComponent_DeviceTracking::ServerRequestBasicDeviceInfos_Implementation(const TArray<int32>& DeviceTrackingGUIDsRequested)
{
}

void UPlayspaceControllerComponent_DeviceTracking::ServerRequestPageBasicDeviceTrackingInfos_Implementation(const bool bAddRequestedPageToCurrentPage, const FString& SearchString, const EDeviceTrackingFilterType FilterType, const EDeviceTrackingSortingType SortingType)
{
}

void UPlayspaceControllerComponent_DeviceTracking::ServerRequestTeleportToSpecificDevice_Implementation(int32 DeviceTrackingGUIDToTeleportTo, const FSoftObjectPath& ObjectPathToTeleportTo) const
{
}
bool UPlayspaceControllerComponent_DeviceTracking::ServerRequestTeleportToSpecificDevice_Validate(int32 DeviceTrackingGUIDToTeleportTo, const FSoftObjectPath& ObjectPathToTeleportTo)
{
	return true;
}

void UPlayspaceControllerComponent_DeviceTracking::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceControllerComponent_DeviceTracking, CurrentSelectedDevice);
	DOREPLIFETIME(UPlayspaceControllerComponent_DeviceTracking, BasicDeviceTrackingInfosPage);
}
