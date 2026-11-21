// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Creative/Components/PlayspaceControllerComponent_DeviceTracking.h"
#include "Creative/FortCreativeDeviceBrowserTypes.h"
#include "FortCreativeDeviceBrowser.generated.h"

class AActor;
class UAthenaCustomizationPickerSortAndFilterBlade;
class UCommonButtonBase;
class UCommonListView;
class UCommonTextBlock;
class UEventBrowserSubscriptionListEntryObj;
class UFortCTAButton;
class UFortCreativeDeviceBrowserListView;
class UObject;
class UWidget;
enum class EDeviceTrackingFilterType : uint8;
enum class EDeviceTrackingSortingType : uint8;

USTRUCT(BlueprintType)
struct FCreativeDeviceCached
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceCached")
	FText DisplayName;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceCached")
	int32 NumBoundEvents;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceCached")
	int32 NumBoundFunctions;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CreativeDeviceCached")
	TSoftObjectPtr<AActor> ActorPtr;

};

USTRUCT(BlueprintType)
struct FCreativeDeviceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceInfo")
	int32 DeviceTrackingGUID;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CreativeDeviceInfo")
	TSoftObjectPtr<AActor> ActorPtr;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceInfo")
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CreativeDeviceInfo")
	TArray<FCreativeDeviceSubscription> OutgoingEvents;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CreativeDeviceInfo")
	TArray<FCreativeDeviceSubscription> CalledFunctions;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceInfo")
	int32 NumBoundEvents;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceInfo")
	int32 NumBoundFunctions;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeDeviceBrowser : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|TraversalDialog")
	void CloseTraversalDialog();

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|ListView")
	UEventBrowserSubscriptionListEntryObj* CreateSubscriptionListHeader(UObject* Outer, const bool bIsEvent);

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|ListView")
	UEventBrowserSubscriptionListEntryObj* CreateSubscriptionListItem(UObject* Outer, const FCreativeDeviceSubscription& Subscription);

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|ListView")
	UEventBrowserSubscriptionListEntryObj* CreateSubscriptionListMessage(UObject* Outer, const FString Message);

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Settings")
	float GetRequestDelay() const;

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Settings")
	float GetScrollOffsetToRequestNewPage() const;

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Settings")
	float GetSearchInputDelay() const;

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Settings")
	bool IsTeleportAllowed() const;

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Settings")
	bool IsTeleportEnabled() const;

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Settings")
	bool IsTraversalAllowed(int32 DeviceTrackingGUID) const;

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|TraversalDialog")
	bool IsTraversalDialogOpen() const;

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Settings")
	bool IsTraversalEnabled() const;

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|TraversalDialog")
	void OpenTraversalDialog();

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|SortAndFilter")
	void SetFilter(const EDeviceTrackingFilterType NewFilterToUse);

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|SortAndFilter")
	void SetFilterByName(const FName FilterName);

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|NameSearch")
	void SetSearchString(const FString& SearchString);

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|SortAndFilter")
	void SetSort(const EDeviceTrackingSortingType NewSortToUse);

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|SortAndFilter")
	void SetSortByName(const FName SortName);

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(BlueprintProtected))
	void DebugPrintCreativeDeviceInfo() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(BlueprintProtected))
	void DebugPrintCreativeDeviceWithBindingsInfo() const;

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Teleport", meta=(BlueprintProtected))
	AActor* GetCurrentTeleportTarget();

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Teleport", meta=(BlueprintProtected))
	int32 GetCurrentTeleportTargetGUID();

	UFUNCTION(BlueprintImplementableEvent)
	int32 GetDeviceGUIDFromListViewObject(const UObject* ListViewObject);

	UFUNCTION(BlueprintPure, Category="DeviceBrowser|Requests", meta=(BlueprintProtected))
	int32 GetNumDevicesCached() const;

	UFUNCTION(BlueprintImplementableEvent)
	AActor* GetTeleportActorFromListViewObject(const UObject* ListViewObject);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleButtonTextSearchClicked();

	UFUNCTION(BlueprintPure, Category="DeviceBrowser", meta=(BlueprintProtected))
	bool IsBrowsingDevices() const;

	UFUNCTION(BlueprintPure, Category="DeviceBrowser", meta=(BlueprintProtected))
	bool IsBrowsingSubscriptions() const;

	UFUNCTION(BlueprintImplementableEvent, Category="DeviceBrowser|Events")
	void OnDeviceDetailsInfoReceived(const FCreativeDeviceInfo& SelectedDeviceInfo);

	UFUNCTION(BlueprintImplementableEvent, Category="DeviceBrowser|Events")
	void OnDeviceInfosPageUpdated();

	UFUNCTION(BlueprintImplementableEvent, Category="DeviceBrowser|Events")
	void OnListViewRefreshNeeded();

	UFUNCTION(BlueprintImplementableEvent, Category="DeviceBrowser|Events")
	void OnSelectedDeviceInfoFailed();

	UFUNCTION(BlueprintImplementableEvent, Category="DeviceBrowser|Events")
	void OnSelectedDeviceNoSubscriptions(const FCreativeDeviceInfo& SelectedDeviceInfo);

	UFUNCTION(BlueprintImplementableEvent, Category="DeviceBrowser|Events")
	void OnTeleporting();

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	void RequestCloseUI();

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|Requests", meta=(BlueprintProtected))
	bool RequestPage(const bool bAddRequestedPageToCurrentPage = false, const FString& SearchString = TEXT(""), const EDeviceTrackingFilterType& Filter = EDeviceTrackingFilterType::WithBindings, const EDeviceTrackingSortingType& SortToUse = EDeviceTrackingSortingType::Default);

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|Requests", meta=(BlueprintProtected))
	bool RequestPageBasicDeviceTrackingInfos(const bool bAddRequestedPageToCurrentPage = false, const FString& SearchString = TEXT(""), const EDeviceTrackingFilterType Filter = EDeviceTrackingFilterType::Unfiltered, const EDeviceTrackingSortingType Sort = EDeviceTrackingSortingType::Default);

	UFUNCTION(BlueprintCallable, Category="DeviceBrowser|Requests", meta=(BlueprintProtected))
	bool RequestSelectDevice(int32 DeviceTrackingGUIDToAssign);

	UFUNCTION(BlueprintCallable)
	void RequestTeleport();

	UFUNCTION(BlueprintCallable)
	void RequestTeleportByGUID(const int32 TeleportTargetGUID);

	UFUNCTION(BlueprintCallable)
	void RequestTeleportByListItem(UObject* ListItem);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeDeviceBrowser")
	TArray<int32> CreativeDeviceInfo;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeDeviceBrowser")
	TMap<int32, FCreativeDeviceInfo> CreativeDeviceInfoMap;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeDeviceBrowser")
	TMap<int32, FCreativeDeviceCached> KnownDevicesMap;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Select;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Teleport;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeDeviceBrowser", meta=(AllowPrivateAccess))
	TWeakObjectPtr<UObject> Selected_ListView_Devices_Teleport_Target;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeDeviceBrowser", meta=(AllowPrivateAccess))
	TWeakObjectPtr<UObject> Selected_ListView_Subscriptions_Teleport_Target;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeDeviceBrowser")
	FString CurrentSearchString;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeDeviceBrowser")
	EDeviceTrackingSortingType CurrentSort;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeDeviceBrowser")
	EDeviceTrackingFilterType CurrentFilter;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DeviceBrowser|SortAndFilter")
	FName CurrentSortName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DeviceBrowser|SortAndFilter")
	FName CurrentFilterName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeDeviceBrowser", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Traversal_Device;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeDeviceBrowser", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCreativeDeviceBrowserListView> ListView_Traversal_Subscriptions;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeDeviceBrowser", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> TraversalDialog;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeDeviceBrowser", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Devices;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeDeviceBrowser", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCreativeDeviceBrowserListView> ListView_Subscriptions;

	UPROPERTY(BlueprintReadOnly, Export, Category="DeviceBrowser|NameSearch", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TextSearch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeDeviceBrowser", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaCustomizationPickerSortAndFilterBlade> Blade_SortAndFilter;

	UPROPERTY(BlueprintReadOnly, Export, Category="DeviceBrowser|SortAndFilter", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_SortAndFilter;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseSortAndFilterBlade;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SortTag;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FilterTag;

	UPROPERTY(EditDefaultsOnly, Category="DeviceBrowser|SortAndFilter")
	EDeviceTrackingSortingType DefaultSort;

	UPROPERTY(EditDefaultsOnly, Category="DeviceBrowser|SortAndFilter")
	TMap<EDeviceTrackingSortingType, FName> SortEnumToSortNameMap;

	UPROPERTY(EditDefaultsOnly, Category="DeviceBrowser|SortAndFilter")
	TMap<FName, FText> SortNameToSortDisplayText;

	UPROPERTY(EditDefaultsOnly, Category="DeviceBrowser|SortAndFilter")
	EDeviceTrackingFilterType DefaultFilter;

	UPROPERTY(EditDefaultsOnly, Category="DeviceBrowser|SortAndFilter")
	TMap<EDeviceTrackingFilterType, FName> FilterEnumToFilterNameMap;

	UPROPERTY(EditDefaultsOnly, Category="DeviceBrowser|SortAndFilter")
	TMap<FName, FText> FilterNameToFilterDisplayText;

};

