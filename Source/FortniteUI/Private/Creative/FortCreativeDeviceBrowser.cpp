// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeDeviceBrowser.h"

void UFortCreativeDeviceBrowser::CloseTraversalDialog()
{
}

UEventBrowserSubscriptionListEntryObj* UFortCreativeDeviceBrowser::CreateSubscriptionListHeader(UObject* Outer, const bool bIsEvent)
{
	return nullptr;
}

UEventBrowserSubscriptionListEntryObj* UFortCreativeDeviceBrowser::CreateSubscriptionListItem(UObject* Outer, const FCreativeDeviceSubscription& Subscription)
{
	return nullptr;
}

UEventBrowserSubscriptionListEntryObj* UFortCreativeDeviceBrowser::CreateSubscriptionListMessage(UObject* Outer, const FString Message)
{
	return nullptr;
}

void UFortCreativeDeviceBrowser::DebugPrintCreativeDeviceInfo() const
{
}

void UFortCreativeDeviceBrowser::DebugPrintCreativeDeviceWithBindingsInfo() const
{
}

AActor* UFortCreativeDeviceBrowser::GetCurrentTeleportTarget()
{
	return nullptr;
}

int32 UFortCreativeDeviceBrowser::GetCurrentTeleportTargetGUID()
{
	return int32();
}

int32 UFortCreativeDeviceBrowser::GetNumDevicesCached() const
{
	return int32();
}

float UFortCreativeDeviceBrowser::GetRequestDelay() const
{
	return float();
}

float UFortCreativeDeviceBrowser::GetScrollOffsetToRequestNewPage() const
{
	return float();
}

float UFortCreativeDeviceBrowser::GetSearchInputDelay() const
{
	return float();
}

bool UFortCreativeDeviceBrowser::IsBrowsingDevices() const
{
	return false;
}

bool UFortCreativeDeviceBrowser::IsBrowsingSubscriptions() const
{
	return false;
}

bool UFortCreativeDeviceBrowser::IsTeleportAllowed() const
{
	return false;
}

bool UFortCreativeDeviceBrowser::IsTeleportEnabled() const
{
	return false;
}

bool UFortCreativeDeviceBrowser::IsTraversalAllowed(int32 DeviceTrackingGUID) const
{
	return false;
}

bool UFortCreativeDeviceBrowser::IsTraversalDialogOpen() const
{
	return false;
}

bool UFortCreativeDeviceBrowser::IsTraversalEnabled() const
{
	return false;
}

void UFortCreativeDeviceBrowser::OpenTraversalDialog()
{
}

void UFortCreativeDeviceBrowser::RequestCloseUI()
{
}

bool UFortCreativeDeviceBrowser::RequestPage(const bool bAddRequestedPageToCurrentPage, const FString& SearchString, const EDeviceTrackingFilterType& Filter, const EDeviceTrackingSortingType& SortToUse)
{
	return false;
}

bool UFortCreativeDeviceBrowser::RequestPageBasicDeviceTrackingInfos(const bool bAddRequestedPageToCurrentPage, const FString& SearchString, const EDeviceTrackingFilterType Filter, const EDeviceTrackingSortingType Sort)
{
	return false;
}

bool UFortCreativeDeviceBrowser::RequestSelectDevice(int32 DeviceTrackingGUIDToAssign)
{
	return false;
}

void UFortCreativeDeviceBrowser::RequestTeleport()
{
}

void UFortCreativeDeviceBrowser::RequestTeleportByGUID(const int32 TeleportTargetGUID)
{
}

void UFortCreativeDeviceBrowser::RequestTeleportByListItem(UObject* ListItem)
{
}

void UFortCreativeDeviceBrowser::SetFilter(const EDeviceTrackingFilterType NewFilterToUse)
{
}

void UFortCreativeDeviceBrowser::SetFilterByName(const FName FilterName)
{
}

void UFortCreativeDeviceBrowser::SetSearchString(const FString& SearchString)
{
}

void UFortCreativeDeviceBrowser::SetSort(const EDeviceTrackingSortingType NewSortToUse)
{
}

void UFortCreativeDeviceBrowser::SetSortByName(const FName SortName)
{
}
