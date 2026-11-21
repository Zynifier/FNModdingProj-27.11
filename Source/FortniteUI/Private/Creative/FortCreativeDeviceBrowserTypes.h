// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeDeviceBrowserTypes.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FCreativeDeviceSubscription
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceSubscription")
	int32 DestinationDeviceGUID;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceSubscription")
	bool bIsEvent;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceSubscription")
	FText SourceSubscriptionDisplayName;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceSubscription")
	FText DestinationDeviceDisplayName;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDeviceSubscription")
	FText DestinationSubscriptionDisplayName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CreativeDeviceSubscription")
	TSoftObjectPtr<AActor> ActorPtr;

};

