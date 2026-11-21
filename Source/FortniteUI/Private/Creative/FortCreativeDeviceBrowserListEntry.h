// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonBase.h"
#include "UObject/NoExportTypes.h"
#include "Creative/FortCreativeDeviceBrowserTypes.h"
#include "FortCreativeDeviceBrowserListEntry.generated.h"

UCLASS(BlueprintType)
class UEventBrowserSubscriptionListEntryObj : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EventBrowserSubscriptionListEntryObj")
	bool bIsEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EventBrowserSubscriptionListEntryObj")
	bool bIsHeader;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EventBrowserSubscriptionListEntryObj")
	int32 DeviceTrackingGUID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EventBrowserSubscriptionListEntryObj")
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EventBrowserSubscriptionListEntryObj")
	FCreativeDeviceSubscription Subscription;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeDeviceBrowserListEntry : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

};

